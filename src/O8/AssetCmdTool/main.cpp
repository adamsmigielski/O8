/** License
*
* Copyright (c) 2015 Adam Œmigielski
*
*
*  Permission is hereby granted, free of charge, to any person obtaining a
*      copy of this software and associated documentation files (the
*      "Software"), to deal in the Software without restriction, including
*      without limitation the rights to use, copy, modify, merge, publish,
*      distribute, sublicense, and/or sell copies of the Software, and to
*      permit persons to whom the Software is furnished to do so, subject to
*      the following conditions: The above copyright notice and this permission
*      notice shall be included in all copies or substantial portions of the
*      Software.
*
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
*      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*      TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
**/

/**
* @author Adam Œmigielski
* @file main.cpp
**/

#include "PCH.hpp"

#include <O8\Asset\File.hpp>
#include <O8\Asset\Registry.hpp>
#include <O8\Asset_Importer\Asset_import_manager.hpp>

typedef int(*Action)(int argc, const char * argv[]);

int Load_extensions(
    const char * file_name,
    O8::Asset_importer::Asset_format::List & list);
int Load_importers(
    const char * file_name,
    O8::Asset_importer::Asset_format::List & list);
void Output_usage();
int Store_extensions(
    const char * file_name,
    O8::Asset_importer::Asset_format::List & list);
int Store_importers(
    const char * file_name,
    O8::Asset_importer::Asset_format::List & list);

/*
* @param argv[2] Registry file
* @param argv[3] ID
* @param argv[4] Path
*/
int Action_append_asset(int argc, const char * argv[])
{
    if (5 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    /* Arguments */
    const char * registry_file_name = argv[2];
    const char * id = argv[3];
    const char * path = argv[4];

    /* Create and load registry */
    O8::Asset::Registry registry;

    registry.Load(registry_file_name);

    /* Search for entry */
    auto entry = registry.Search(
        O8::Utility::Name_predicate<O8::Asset::Registry_entry>(id));

    /* Add new entry */
    if (nullptr == entry)
    {
        LOG("Added new entry");

        entry = O8::Asset::Create_registry_entry();
        entry->m_Name(id);
        
        registry.Attach(entry);
        registry.Sort(O8::Utility::Name_ascend_predicate<O8::Asset::Registry_entry>());
    }
    else
    {
        LOG("Entry already available - update path");
    }

    /* Update path */
    entry->m_Path = path;

    /* Store results */
    return registry.Store(registry_file_name);
}

/*
 * @param argv[2] Registry file
 * @param argv[3] Extension name
 * @param argv[4] Format name
 */
int Action_append_extension(int argc, const char * argv[])
{
    if (5 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    /* Arguments */
    const char * registry_file_name = argv[2];
    const char * extension_name = argv[3];
    const char * format_name = argv[4];

    /* Load current content */
    O8::Asset_importer::File_extension::List list;
    Load_extensions(registry_file_name, list);

    /* Search for format entry */
    auto ext = list.Search(
        O8::Utility::Name_predicate<O8::Asset_importer::File_extension>(extension_name));

    /* Extension was not added yet */
    if (nullptr == ext)
    {
        LOG(extension_name << " extension added");

        ext = new O8::Asset_importer::File_extension;
        ext->m_Name(extension_name);
        ext->m_Format_name(format_name);

        list.Attach(ext);

        list.Sort(
            O8::Utility::Name_ascend_predicate<O8::Asset_importer::Asset_format>());
    }
    else
    {
        LOG(extension_name << " extension updated");
        ext->m_Format_name(format_name);
    }

    return Store_extensions(argv[2], list);
}

/*
* @param argv[2] Archive file
* @param argv[3] Extensions file
* @param argv[4] Importers file
* @param argv[5] Registry file
*/
int Action_append_importer(int argc, const char * argv[])
{
    if (5 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    /* Arguments */
    const char * registry_file_name = argv[2];
    const char * importer_name = argv[3];
    const char * format_name = argv[4];

    /* Load current content */
    O8::Asset_importer::Asset_format::List list;
    Load_importers(registry_file_name, list);

    /* Search for format entry */
    auto format = list.Search(
        O8::Utility::Name_predicate<O8::Asset_importer::Asset_format>(format_name));

    /* Format was not added yet */
    if (nullptr == format)
    {
        LOG(format_name << " format added");

        format = new O8::Asset_importer::Asset_format;
        format->m_Name(argv[4]);

        list.Attach(format);

        list.Sort(
            O8::Utility::Name_ascend_predicate<O8::Asset_importer::Asset_format>());
    }
    else
    {
        LOG(format_name << " format already available, update importer");
    }

    format->m_Importer_library_path(importer_name);

    return Store_importers(argv[2], list);
}

int Action_create_archive(int argc, const char * argv[])
{
    if (6 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    /* Arguments */
    const char * archive_file_name = argv[2];
    const char * extension_file_name = argv[3];
    const char * importer_file_name = argv[4];
    const char * registry_file_name = argv[5];

    /* Create and load registry */
    O8::Asset::Registry registry;

    if (O8::Success != registry.Load(registry_file_name))
    {
        ERRLOG("Assets registry file is not available");
        return -1;
    }

    /* Load asset import manager */
    O8::Asset_importer::Asset_import_manager import_manager;
    if (O8::Success != Load_importers(
        registry_file_name,
        import_manager.m_Formats,
        import_manager.m_Importers))
    {
        ERRLOG("Importers registry file is not available");
        return -1;
    }

    if (O8::Success != Load_extensions(
        extension_file_name,
        import_manager.m_Extensions))
    {
        ERRLOG("Extensions registry file is not available");
        return -1;
    }

    /* Create archive */
    auto archive = O8::Asset::Store_file(
        archive_file_name,
        );


    return 0;
}

int Load_extensions(
    const char * file_name,
    O8::Asset_importer::File_extension::List& list)
{
    std::fstream file;
    file.open(file_name, std::fstream::in);
    if (false == file.is_open())
    {
        return -1;
    }

    while (1)
    {
        std::string ext_str;
        std::string format_str;

        file >> ext_str;
        file >> format_str;

        if (true == file.eof())
        {
            break;
        }

        if ((true == ext_str.empty()) ||
            (true == format_str.empty()))
        {
            ERRLOG("Invalid entry. Ext: " << ext_str << " format: " << format_str);
            continue;
        }

        auto ext = list.Search(
            O8::Utility::Name_predicate<O8::Asset_importer::File_extension>(ext_str));
        if (nullptr == ext)
        {
            LOG("Loaded entry: " << ext_str << " " << format_str);

            ext = new O8::Asset_importer::File_extension;
            ext->m_Name(format_str);
            ext->m_Format_name(format_str);
            list.Attach(ext);
        }
        else
        {
            ERRLOG("Multiple entries for the same extension: " << ext_str << " " << format_str);
        }
    }

    return 0;
}

int Load_importers(
    const char * file_name,
    O8::Asset_importer::Asset_format::List& list)
{
    std::fstream file;
    file.open(file_name, std::fstream::in);
    if (false == file.is_open())
    {
        return -1;
    }

    while (1)
    {
        std::string importer_str;
        std::string format_str;

        file >> importer_str;
        file >> format_str;

        if (true == file.eof())
        {
            break;
        }

        if ((true == importer_str.empty()) ||
            (true == format_str.empty()))
        {
            ERRLOG("Invalid entry. Importer: " << importer_str << " format: " << format_str);
            continue;
        }

        auto format = list.Search(
            O8::Utility::Name_predicate<O8::Asset_importer::Asset_format>(format_str));
        if (nullptr == format)
        {
            format = new O8::Asset_importer::Asset_format;
            format->m_Name(format_str);
            list.Attach(format);
        }

        format->m_Importer_library_path(importer_str);
    }

    return 0;
}

int Load_importers(
    const char * file_name,
    O8::Asset_importer::Asset_format::List& formats,
    O8::Asset_importer::Asset_importer_owner::List& importers)
{
    std::fstream file;
    file.open(file_name, std::fstream::in);
    if (false == file.is_open())
    {
        return -1;
    }

    while (1)
    {
        std::string importer_str;
        std::string format_str;

        file >> importer_str;
        file >> format_str;

        if (true == file.eof())
        {
            break;
        }

        if ((true == importer_str.empty()) ||
            (true == format_str.empty()))
        {
            ERRLOG("Invalid entry. Importer: " << importer_str << " format: " << format_str);
            continue;
        }

        auto format = formats.Search(
            O8::Utility::Name_predicate<O8::Asset_importer::Asset_format>(format_str));
        if (nullptr == format)
        {
            format = new O8::Asset_importer::Asset_format;
            format->m_Name(format_str);
            formats.Attach(format);
        }

        format->m_Importer_library_path(importer_str);

        auto importer = importers.Search(
            O8::Asset_importer::Importer_library_path_predicate
            <O8::Asset_importer::Asset_importer_owner>
            (importer_str));
        if (nullptr == importer)
        {
            importer = new O8::Asset_importer::Asset_importer_owner;
            importer->m_Importer_library_path(importer_str);
            importers.Attach(importer);
        }
    }

    return 0;
}

void Output_usage()
{
    ERRLOG("Usage:"
        "\n\t-a creates archive file\n\t\tOUTPUT_ARCHIVE_FILE\n\t\tEXTENSION_REGISTRY_FILE\n\t\tIMPORTER_REGISTRY_FILE\n\t\tASSET_REGISTRY_FILE"
        "\n\t-e appends entry to extension registry file\n\t\tOUTPUT_EXTENSION_REGISTRY_FILE\n\t\tEXTENSION\n\t\tFORMAT"
        "\n\t-i appends entry to importer registry file\n\t\tOUTPUT_IMPORTER_REGISTRY_FILE\n\t\tIMPORTER_PATH\n\t\tFORMAT"
        "\n\t-r appends entry to asset registry file\n\t\tOUTPUT_REGISTRY_FILE\n\t\tENTRY_ID\n\t\tFILE_PATH")
}

Action Get_action(const char * arg_1)
{
    if (0 == strcmp("-a", arg_1))
    {
        return Action_create_archive;
    }
    else if (0 == strcmp("-e", arg_1))
    {
        return Action_append_extension;
    }
    else if (0 == strcmp("-i", arg_1))
    {
        return Action_append_importer;
    }
    else if (0 == strcmp("-r", arg_1))
    {
        return Action_append_asset;
    }
    else
    {
        return nullptr;
    }
}

int Store_extensions(
    const char * file_name,
    O8::Asset_importer::File_extension::List& list)
{
    std::fstream file;
    file.open(file_name, std::fstream::out | std::fstream::trunc);
    if (false == file.is_open())
    {
        ERRLOG("Failed to open file: " << file_name);
        return -1;
    }

    for (auto ext = list.First(); nullptr != ext; ext = ext->Next())
    {
        file << ext->m_Name() << " " << ext->m_Format_name() << std::endl;
    }

    return 0;
}

int Store_importers(
    const char * file_name,
    O8::Asset_importer::Asset_format::List& list)
{
    std::fstream file;
    file.open(file_name, std::fstream::out | std::fstream::trunc);
    if (false == file.is_open())
    {
        ERRLOG("Failed to open file: " << file_name);
        return -1;
    }

    for (auto format = list.First(); nullptr != format; format = format->Next())
    {
        file << format->m_Importer_library_path()  << " " << format->m_Name() << std::endl;
    }

    return 0;
}

int main(int argc, const char * argv[])
{
    if (2 > argc)
    {
        Output_usage();
        return -1;
    }

    auto action = Get_action(argv[1]);

    if (nullptr == action)
    {
        ERRLOG("Invalid parameters");
        Output_usage();
        return -1;
    }

    return action(argc, argv);
}

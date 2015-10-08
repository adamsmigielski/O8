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
#include <O8\Asset\Archiver.hpp>
#include <O8\Asset\Import_manager.hpp>

typedef int(*Action)(int argc, const char * argv[]);

void Output_usage();

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

        auto entry = new O8::Asset::Registry_entry;
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
    O8::Asset::Import_manager manager;
    manager.Load_extensions(registry_file_name);

    /* Search for format entry */
    auto ext = manager.m_Extensions.Search(
        O8::Utility::Name_predicate<O8::Asset::File_extension>(extension_name));

    /* Extension was not added yet */
    if (nullptr == ext)
    {
        LOG(extension_name << " extension added");

        ext = new O8::Asset::File_extension;
        ext->m_Name(extension_name);
        ext->m_Format_name(format_name);

        manager.m_Extensions.Attach(ext);

        manager.m_Extensions.Sort(
            O8::Utility::Name_ascend_predicate<O8::Asset::File_extension>());
    }
    else
    {
        LOG(extension_name << " extension updated");
        ext->m_Format_name(format_name);
    }

    return manager.Store_extensions(registry_file_name);
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
    O8::Asset::Import_manager manager;
    manager.Load_importers(registry_file_name);

    /* Search for format entry */
    auto format = manager.m_Formats.Search(
        O8::Utility::Name_predicate<O8::Asset::Format>(format_name));

    /* Format was not added yet */
    if (nullptr == format)
    {
        LOG(format_name << " format added");

        format = new O8::Asset::Format;
        format->m_Name(argv[4]);

        manager.m_Formats.Attach(format);

        manager.m_Formats.Sort(
            O8::Utility::Name_ascend_predicate<O8::Asset::Format>());
    }
    else
    {
        LOG(format_name << " format already available, update importer");
    }

    format->m_Importer_library_path(importer_name);

    return manager.Store_formats(registry_file_name);
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

    if (O8::Utilities::Success != registry.Load(registry_file_name))
    {
        ERRLOG("Assets registry file is not available");
        return -1;
    }

    /* Load asset import manager */
    O8::Asset::Import_manager import_manager;
    if (O8::Utilities::Success != import_manager.Load_importers(registry_file_name))
    {
        ERRLOG("Importers registry file is not available");
        return -1;
    }

    if (O8::Utilities::Success != import_manager.Load_extensions(extension_file_name))
    {
        ERRLOG("Extensions registry file is not available");
        return -1;
    }

    auto archiver_list = O8::Asset::Archiver::Get_archivization_list(
        registry,
        import_manager);

    return O8::Asset::File::Store_file(
        archive_file_name,
        archiver_list.First(),
        nullptr);
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

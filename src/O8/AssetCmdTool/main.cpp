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

typedef int(*Action)(int argc, const char * argv[]);

void Output_usage();
int Load_extensions(
    const char * file_name,
    O8::Asset_importer::Asset_format::List & list);
int Store_extensions(
    const char * file_name,
    O8::Asset_importer::Asset_format::List & list);


int Action_append_asset(int argc, const char * argv[])
{
    if (5 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    auto registry = O8::Asset::Create_registry();

    if (O8::Success != registry->Load(argv[2]))
    {
        delete registry;
        return -3;
    }

    auto entry = registry->Search(
        O8::Utility::Name_predicate<O8::Asset::Registry_entry>(argv[3]));

    if (nullptr == entry)
    {
        entry = O8::Asset::Create_registry_entry();
        entry->m_Name(argv[3]);
    }

    entry->m_Path = argv[4];

    registry->Attach(entry);
    registry->Sort(O8::Utility::Name_ascend_predicate<O8::Asset::Registry_entry>());
    registry->Store(argv[2]);

    return 0;
}

int Action_append_extension(int argc, const char * argv[])
{
    if (5 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    O8::Asset_importer::Asset_format::List list;
    if (0 != Load_extensions(argv[2], list))
    {
        return -1;
    }

    auto format = list.Search(
        O8::Utility::Name_predicate<O8::Asset_importer::Asset_format>(argv[4]));

    if (nullptr == format)
    {
        format = new O8::Asset_importer::Asset_format;
        format->m_Name(argv[4]);
    }

    list.Attach(format);
    list.Sort(
        O8::Utility::Name_ascend_predicate<O8::Asset_importer::Asset_format>());

    auto ext = format->Search(
        O8::Utility::Name_predicate<O8::Asset_importer::File_extension>(argv[3]));

    if (nullptr == ext)
    {
        ext = new O8::Asset_importer::File_extension;
        ext->m_Name(argv[3]);
        format->Attach(ext);

        format->Sort(
            O8::Utility::Name_ascend_predicate<O8::Asset_importer::File_extension>());

        return Store_extensions(argv[2], list);
    }
    else
    {
        return 0;
    }
}

int Action_append_importer(int argc, const char * argv[])
{
    if (4 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    return 0;
}

int Action_create_archive(int argc, const char * argv[])
{
    if (4 != argc)
    {
        ERRLOG("Invalid number of parameters");
        Output_usage();
        return -1;
    }

    return 0;
}

int Load_extensions(
    const char * file_name,
    O8::Asset_importer::Asset_format::List& list)
{
    std::fstream file;
    file.open(file_name, std::fstream::in);
    if (false == file.is_open())
    {
        ERRLOG("Failed to open file: " << file_name);
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

        auto format = list.Search(
            O8::Utility::Name_predicate<O8::Asset_importer::Asset_format>(format_str));
        if (nullptr == format)
        {
            format = new O8::Asset_importer::Asset_format;
            format->m_Name(format_str);
            list.Attach(format);
        }

        auto ext = format->Search(
            O8::Utility::Name_predicate<O8::Asset_importer::File_extension>(ext_str));

        if (nullptr == ext)
        {
            ext = new O8::Asset_importer::File_extension;
            ext->m_Name(ext_str);
            format->Attach(ext);
        }
    }

    return 0;
}

void Output_usage()
{
    ERRLOG("Usage:"
        "\n\t-a creates archive file\n\t\tOUTPUT_ARCHIVE_FILE\n\t\tIMPORTER_REGISTRY_FILE\n\t\tLIST_OF_REGISTRY_FILES"
        "\n\t-e appends entry to extension registry file\n\t\tOUTPUT_EXTENSION_REGISTRY_FILE\n\t\tEXTENSION\n\t\tFORMAT"
        "\n\t-i appends entry to importer registry file\n\t\tOUTPUT_IMPORTER_REGISTRY_FILE\n\t\tFILE_PATH"
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
        for (auto ext = format->First(); nullptr != ext; ext = ext->Next())
        {
            file << ext->m_Name() << " " << format->m_Name() << std::endl;
        }
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

    if (O8::Success != O8::Asset::Load_asset_registry("Asset_Registry.dll"))
    {
        return -2;
    }



    return action(argc, argv);
}

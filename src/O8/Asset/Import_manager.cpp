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
* @file Asset_import_manager.cpp
**/

#include "PCH.hpp"

#include "Import_manager.hpp"
#include <O8\DL\DL.hpp> 

namespace O8
{
    namespace Asset
    {
        
        Format::Format()
        {
            m_Importer = nullptr;
        }
        
        Format::~Format()
        {
            m_Importer = nullptr;
        }

        File_extension::File_extension()
        {
            m_Format = nullptr;
        }

        File_extension::~File_extension()
        {
            m_Format = nullptr;
        }

        
        Importer_owner::Importer_owner()
            : m_Importer(nullptr, O8::Asset::Importer::Deleter)
        {
            /* Nothing to be done */
        }


        Importer * Import_manager::Get_importer_by_extension(
            const std::string & extension)
        {
            DEBUGLOG("Accessing importer for extension: " << extension);

            auto ext = m_Extensions.Search(Helpers::Name_predicate<File_extension>(extension));

            return get_importer(ext);
        }

        Platform::int32 Import_manager::Load_extensions(const std::string & file_name)
        {
            std::fstream file;
            file.open(file_name, std::fstream::in);
            if (false == file.is_open())
            {
                return Utilities::Failed_to_open_file;
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

                auto ext = m_Extensions.Search(
                    Helpers::Name_predicate
                        <File_extension>
                        (ext_str));

                if (nullptr == ext)
                {
                    LOG("Loaded entry: " << ext_str << " " << format_str);

                    ext = new File_extension;
                    ext->m_Name(ext_str);
                    ext->m_Format_name(format_str);
                    m_Extensions.Attach(ext);
                }
                else
                {
                    ERRLOG("Multiple entries for the same extension: " << ext_str << " " << format_str);
                }
            }

            return Utilities::Success;
        }

        Platform::int32 Import_manager::Load_formats(const std::string & file_name)
        {
            std::fstream file;
            file.open(file_name, std::fstream::in);
            if (false == file.is_open())
            {
                return Utilities::Failed_to_open_file;
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

                auto format = m_Formats.Search(
                    Helpers::Name_predicate<Format>(format_str));
                if (nullptr == format)
                {
                    format = new Format;
                    format->m_Name(format_str);
                    m_Formats.Attach(format);
                }

                format->m_Importer_library_path(importer_str);
            }

            return Utilities::Success;
        }

        Platform::int32 Import_manager::Load_importers(const std::string & file_name)
        {
            std::fstream file;
            file.open(file_name, std::fstream::in);
            if (false == file.is_open())
            {
                return Utilities::Failed_to_open_file;
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

                auto format = m_Formats.Search(
                    Helpers::Name_predicate<Format>(format_str));
                if (nullptr == format)
                {
                    format = new Format;
                    format->m_Name(format_str);
                    m_Formats.Attach(format);
                }

                format->m_Importer_library_path(importer_str);

                auto importer = m_Importers.Search(
                    Importer_library_path_predicate
                    <Importer_owner>
                    (importer_str));
                if (nullptr == importer)
                {
                    importer = new Importer_owner;
                    importer->m_Importer_library_path(importer_str);
                    m_Importers.Attach(importer);
                }
            }

            return Utilities::Success;
        }

        Platform::int32 Import_manager::Store_extensions(const std::string & file_name)
        {
            std::fstream file;
            file.open(file_name, std::fstream::out | std::fstream::trunc);
            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                return Utilities::Failed_to_open_file;
            }

            for (auto ext = m_Extensions.First(); nullptr != ext; ext = ext->Next())
            {
                file << ext->m_Name() << " " << ext->m_Format_name() << std::endl;
            }

            return Utilities::Success;
        }

        Platform::int32 Import_manager::Store_formats(const std::string & file_name)
        {
            std::fstream file;
            file.open(file_name, std::fstream::out | std::fstream::trunc);
            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                return Utilities::Failed_to_open_file;
            }

            for (auto format = m_Formats.First(); nullptr != format; format = format->Next())
            {
                file << format->m_Importer_library_path() << " " << format->m_Name() << std::endl;
            }

            return Utilities::Success;
        }

        Format * Import_manager::get_format(
            const std::string & format_name)
        {
            return m_Formats.Search(
                Helpers::Name_predicate<Format>(
                format_name));
        }

        Importer * Import_manager::get_importer(File_extension * ext)
        {
            if (nullptr == ext)
            {
                ERRLOG("Missing entry for extension.");
                return nullptr;
            }

            if (nullptr == ext->m_Format)
            {
                ext->m_Format = get_format(ext->m_Format_name());
            }

            return get_importer(ext->m_Format);
        }

        Importer * Import_manager::get_importer(Format * format)
        {
            if (nullptr == format)
            {
                ERRLOG("Missing entry for format.");
                return nullptr;
            }

            if (nullptr == format->m_Importer)
            {
                format->m_Importer = get_importer(format->m_Importer_library_path());
            }

            return format->m_Importer;
        }

        Importer * Import_manager::get_importer(const std::string & library_path)
        {
            auto owner = m_Importers.Search(
                Importer_library_path_predicate<Importer_owner>(
                    library_path));

            if (nullptr == owner)
            {
                ERRLOG("Missing entry for importer: " << library_path);
                return nullptr;
            }

            if (nullptr == owner->m_Importer)
            {
                owner->m_Importer.reset(load_importer(
                    owner->m_Importer_library_path()));
            }

            return owner->m_Importer.get();
        }

        Importer * Import_manager::load_importer(
            const std::string & file_path)
        {
            DL::DL * dl = DL::Load(file_path.c_str());
            if (nullptr == dl)
            {
                ERRLOG("Failed to load library" << file_path);
                ASSERT(0);
                return nullptr;
            }

            auto create = (PFN_CREATE_IMPORTER) dl->GetFunctionAddress("Create_importer");
            if (nullptr == create)
            {
                ERRLOG("Failed to get \"Create_importer\" function");
                ASSERT(0);
                delete dl;
                return nullptr;
            }

            auto importer = create();
            if (nullptr == importer)
            {
                ERRLOG("Function \"Create_importer\" failed");
                ASSERT(0);
                delete dl;
                return nullptr;
            }

            importer->m_Dl = dl;

            auto ret = importer->Init();
            if (Utilities::Success != ret)
            {
                ERRLOG("Importer initialization failed");
                ASSERT(0);
                O8::Asset::Importer::Deleter(importer);
                return nullptr;
            }

            return importer;
        }
    }
}

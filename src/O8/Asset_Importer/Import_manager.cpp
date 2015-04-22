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

#include "Asset_import_manager.hpp"
#include <O8\DL\DL.hpp> 

namespace O8
{
    namespace Asset_importer
    {
        
        Asset_format::Asset_format()
        {
            m_Importer = nullptr;
        }
        
        Asset_format::~Asset_format()
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

        //Asset_import_manager::Asset_import_manager()
        //{
        //
        //}
        //
        //Asset_import_manager::~Asset_import_manager()
        //{
        //
        //}

        Asset_importer * Asset_import_manager::Get_importer_by_extension(
            const std::string & extension)
        {
            DEBUGLOG("Accessing importer for extension: " << extension);

            auto ext = m_Extensions.Search(Utility::Name_predicate<File_extension>(extension));

            return get_importer(ext);
        }

        Asset_format * Asset_import_manager::get_format(
            const std::string & format_name)
        {
            return m_Formats.Search(
                Utility::Name_predicate<Asset_format>(
                format_name));
        }

        Asset_importer * Asset_import_manager::get_importer(File_extension * ext)
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

        Asset_importer * Asset_import_manager::get_importer(Asset_format * format)
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

        Asset_importer * Asset_import_manager::get_importer(const std::string & library_path)
        {
            auto owner = m_Importers.Search(
                Importer_library_path_predicate<Asset_importer_owner>(
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

        Asset_importer * Asset_import_manager::load_importer(
            const std::string & file_path)
        {
            DL::DL * dl = DL::Load(file_path.c_str());
            if (nullptr == dl)
            {
                ERRLOG("Failed to load library" << file_path);
                ASSERT(0);
                return nullptr;
            }

            auto create = (PFN_CREATE_IMPORTER) dl->GetFunctionAddress("Create_imoprter");
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

            return importer;
        }
    }
}

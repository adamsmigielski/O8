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
#include <O8\Utility\Hash_string.hpp>

namespace O8
{
    namespace Asset_importer
    {
        File_extension::File_extension()
        {

        }

        File_extension::~File_extension()
        {

        }

        Asset_format::Asset_format()
        {

        }

        Asset_format::~Asset_format()
        {

        }

        bool Asset_format::Does_extension_match(
            const std::string & ext) const
        {
            auto ptr = Search(Utility::Name_predicate<File_extension>(ext));

            return (nullptr != ptr);
        }

        class Match_asset_format_by_ext
        {
        public:
            Match_asset_format_by_ext(const std::string & ext)
                : m_ext(ext)
            {

            }

            bool operator ()(const Asset_format & format) const
            {
                return format.Does_extension_match(m_ext);
            }

        private:
            const std::string & m_ext;
        };

        Asset_import_manager::Asset_import_manager()
        {

        }

        Asset_import_manager::~Asset_import_manager()
        {

        }

        Asset_importer * Asset_import_manager::Get_importer_by_extension(
            const std::string & extension)
        {
            auto format = m_formats.Search(Match_asset_format_by_ext(extension), true);

            if (nullptr != format)
            {
                return format->m_Importer;
            }
            else
            {
                return nullptr;
            }
        }

        Asset_importer * Asset_import_manager::Get_importer_by_format(
            const std::string & format_name)
        {
            auto format = m_formats.Search(Utility::Name_predicate<Asset_format>(format_name));

            if (nullptr != format)
            {
                return format->m_Importer;
            }
            else
            {
                return nullptr;
            }
        }

        Asset_importer * Asset_import_manager::Load_importer(
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

            for (auto it = m_formats.First(); nullptr != it; ++it)
            {
                if (nullptr == it->m_Importer)
                {
                    if (true == importer->Is_format_supported(it->m_Name()))
                    {
                        LOG("Importer registered for: " << it->m_Name());

                        it->m_Importer = importer;
                    }
                }
            }

            return importer;
        }
    }
}

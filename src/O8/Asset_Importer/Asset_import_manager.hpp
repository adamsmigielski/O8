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
* @file Asset_importer.hpp
**/

#ifndef O8_ASSET_IMPORTER_ASSET_IMPORT_MANAGER_HPP
#define O8_ASSET_IMPORTER_ASSET_IMPORT_MANAGER_HPP

#include <O8\Templates\IntrusiveList.hpp>
#include <O8\Utility\Name.hpp>

#include "Asset_importer.hpp"

namespace O8
{
    namespace Asset_importer
    {
        class File_extension : public O8::IntrusiveList::Node < File_extension >
        {
        public:
            /* Types */
            typedef O8::IntrusiveList::List<File_extension> List;

            /* Ctr & Dtr */
            File_extension();
            virtual ~File_extension();

            Utility::Name m_Name;
        };

        class Asset_format : public O8::IntrusiveList::Node<Asset_format>
                           , public File_extension::List
        {
        public:
            /* Types */
            typedef O8::IntrusiveList::List<Asset_format> List;

            /* Ctr & Dtr */
            Asset_format();
            virtual ~Asset_format();

            virtual bool Does_extension_match(
                const std::string & ext) const;

            Asset_importer * m_Importer;
            Utility::Name m_Name;
        };

        class Asset_import_manager : public O8::IntrusiveList::Node<Asset_importer>
        {
        public:
            Asset_import_manager();
            virtual ~Asset_import_manager();

            virtual Asset_importer * Get_importer_by_extension(
                const std::string & extension);
            virtual Asset_importer * Get_importer_by_format(
                const std::string & format_name);
            virtual Asset_importer * Load_importer(
                const std::string & file_path);

        private:
            Asset_format::List m_formats;
        };
    }
}

#endif /* O8_ASSET_IMPORTER_ASSET_IMPORT_MANAGER_HPP */

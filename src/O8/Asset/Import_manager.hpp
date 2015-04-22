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
* @file Import_manager.hpp
**/

#ifndef O8_ASSET_IMPORT_MANAGER_HPP
#define O8_ASSET_IMPORT_MANAGER_HPP

#include <memory>

#include <O8\Templates\IntrusiveList.hpp>
#include <O8\Utility\Name.hpp>

#include "Importer.hpp"

namespace O8
{
    namespace Asset
    {
        class Format : public O8::IntrusiveList::Node<Format>
        {
        public:
            /* Types */
            typedef O8::IntrusiveList::List<Format> List;

            /* Ctr & Dtr */
            Format();
            virtual ~Format();

            Importer * m_Importer;
            Utility::Name m_Importer_library_path;
            Utility::Name m_Name;
        };

        class File_extension : public O8::IntrusiveList::Node < File_extension >
        {
        public:
            /* Types */
            typedef O8::IntrusiveList::List<File_extension> List;

            /* Ctr & Dtr */
            File_extension();
            ~File_extension();

            Format * m_Format;
            Utility::Name m_Format_name;
            Utility::Name m_Name;
        };

        class Importer_owner : public O8::IntrusiveList::Node<Importer_owner>
        {
        public:
            /* Types */
            typedef O8::IntrusiveList::List<Importer_owner> List;

            std::unique_ptr<Importer> m_Importer;
            Utility::Name m_Importer_library_path;
        };

        class Import_manager
        {
        public:
            virtual Importer * Get_importer_by_extension(
                const std::string & extension);

            int32 Load_extensions(const std::string & file_name);
            int32 Load_formats(const std::string & file_name);
            int32 Load_importers(const std::string & file_name);
            int32 Store_extensions(const std::string & file_name);
            int32 Store_formats(const std::string & file_name);

            File_extension::List m_Extensions;
            Format::List m_Formats;
            Importer_owner::List m_Importers;

        private:
            Format * get_format(
                const std::string & format_name);
            Importer * get_importer(
                File_extension * ext);
            Importer * get_importer(
                Format * format);
            Importer * get_importer(
                const std::string & library_path);
            Importer * load_importer(
                const std::string & file_path);
        };

        template <typename T>
        class Importer_library_path_predicate
        {
        public:
            Importer_library_path_predicate(const std::string & name)
                : m_hash(Utility::Hash_string(name))
            {
                /* Nothing to be done here */
            }

            Importer_library_path_predicate(size_t hash)
                : m_hash(hash)
            {
                /* Nothing to be done here */
            }

            bool operator()(const T& t) const
            {
                return (t.m_Importer_library_path.Hash() == m_hash);
            }

        private:
            size_t m_hash;
        };
    }
}

#endif /* O8_ASSET_IMPORT_MANAGER_HPP */

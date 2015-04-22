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
* @file Archiver.hpp
**/

#ifndef O8_ASSET_ARCHIVER_HPP
#define O8_ASSET_ARCHIVER_HPP

#include "Type.hpp"
#include "File.hpp"

#include "Importer.hpp"
#include "Import_manager.hpp"

#include <O8\Templates\IntrusiveList.hpp>
#include <O8\Utility\Name.hpp>

namespace O8
{
    namespace Asset
    {
        class Registry_entry : public IntrusiveList::Node<Registry_entry>
        {
        public:
            /* Types */
            typedef IntrusiveList::List<Registry_entry> List;

            /* Ctr & Dtr */
            Registry_entry();
            virtual ~Registry_entry();

            Utility::Name m_Name;
            std::string m_Path;
        };

        class Registry : public Registry_entry::List
        {
        public:
            Registry();
            Registry(const Registry &) = delete;
            Registry & operator = (const Registry &) = delete;

            virtual ~Registry();

            virtual int32 Load(const std::string & file_name);
            virtual int32 Store(const std::string & file_name) const;
        };

        class Archiver_descriptor : public Asset_descriptor
        {
        public:
            /*Types */
            typedef IntrusiveList::List<Archiver_descriptor> List;

            /* Ctr $ Dtr */
            Archiver_descriptor(
                const Registry_entry * entry,
                Importer * importer);
            virtual ~Archiver_descriptor();

            virtual int32 Get_details(
                Utility::Binary_data & out_data,
                Type::Types & out_type) const;
            virtual const std::string & Get_name() const;

        private:
            const Registry_entry * m_entry;
            Importer * m_importer;
        };

        class Archiver
        {
        public:
            static Asset_descriptor::List Get_archivization_list(
                const Registry_entry::List & entries,
                Import_manager & import_manager);
        };
    }
}

#endif O8_ASSET_ARCHIVER_HPP

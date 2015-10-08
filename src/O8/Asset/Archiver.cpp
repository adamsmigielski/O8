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
* @file Archiver.cpp
**/

#include "PCH.hpp"

#include "Archiver.hpp"

#include <fstream>

namespace O8
{
    namespace Asset
    {
        Registry_entry::Registry_entry()
            : m_Path("")
        {
            /* Nothing to be done here */
        }

        Registry_entry::~Registry_entry()
        {
            /* Nothing to be done here */
        }

        Registry::Registry()
        {
            /* Nothing to be done here */
        }

        Registry::~Registry()
        {
            /* Nothing to be done here */
        }

        int32 Registry::Load(const std::string & file_name)
        {
            std::fstream file;

            file.open(file_name.c_str(), std::fstream::in);

            if (false == file.is_open())
            {
                DEBUGLOG("Failed to open file: " << file_name);
                return Failed_to_open_file;
            }

            while (1)
            {
                std::string id;
                std::string path;

                file >> id;
                file >> path;

                if (true == file.eof())
                {
                    break;
                }

                auto desc = new Registry_entry;
                desc->m_Name(id);
                desc->m_Path = path;

                Attach(desc);
            }

            file.close();

            return Utilities::Success;
        }

        int32 Registry::Store(const std::string & file_name) const
        {
            std::fstream file;

            file.open(file_name.c_str(), std::fstream::out | std::fstream::trunc);

            if (false == file.is_open())
            {
                ERRLOG("Failed to open file: " << file_name);
                ASSERT(0);
                return Failure;
            }

            for (auto it = First(); nullptr != it; it = it->Next())
            {
                file << " ";
                file << it->m_Name();
                file << " ";
                file << it->m_Path;
                file << std::endl;
            }

            file.close();

            return Utilities::Success;
        }

        Archiver_descriptor::Archiver_descriptor(
            const Registry_entry * entry,
            Importer * importer)
            : m_entry(entry)
            , m_importer(importer)
        {
            /* Nothing to be done here*/
        }

        Archiver_descriptor::~Archiver_descriptor()
        {
            m_entry = nullptr;
            m_importer = nullptr;
        }

        int32 Archiver_descriptor::Get_details(
            Utility::Binary_data & out_data,
            Type::Types & out_type) const
        {
            return m_importer->Get_asset(
                m_entry->m_Path,
                out_data,
                out_type);
        }

        const std::string & Archiver_descriptor::Get_name() const
        {
            return m_entry->m_Name();
        }

        Asset_descriptor::List Archiver::Get_archivization_list(
            const Registry_entry::List & entries,
            Import_manager & import_manager)
        {
            Asset_descriptor::List list;

            for (auto entry = entries.First();
                nullptr != entry;
                entry = entry->Next())
            {
                size_t last_dot = entry->m_Name().rfind('.');

                if (std::string::npos == last_dot)
                {
                    ERRLOG("Wrong path string, extension is missing: " << entry->m_Name());
                    continue;
                }

                const std::string & extension_str = entry->m_Name().substr(last_dot + 1);

                auto importer = import_manager.Get_importer_by_extension(extension_str);

                if (nullptr == importer)
                {
                    ERRLOG("Missing importer for extension: " << extension_str);
                    continue;
                }

                auto desc = new Archiver_descriptor(
                    entry,
                    importer);

                if (nullptr == desc)
                {
                    ERRLOG("Memory allocation failed");
                    continue;
                }

                list.Attach(desc);
            }

            return list;
        }
    }
}

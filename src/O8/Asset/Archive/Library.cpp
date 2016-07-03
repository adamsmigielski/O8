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
* @file Library.cpp
**/

#include "PCH.hpp"

#include "Library.hpp"
#include <Utilities\helpers\Hash_string.hpp>

namespace O8
{
    namespace Asset
    {
        Library::Library()
        {
            /* Nothing to be done here */
        }

        Library::~Library()
        {
            /* Nothing to be done here */
        }

        Memory::Binary_data Library::Get_asset(
            const std::string & id,
            bool is_endianess_swapped)
        {
            std::string file_name;
            std::string entry_name;
            Memory::Binary_data result;

            Platform::int32 ret = Split_asset_id(
                id,
                file_name,
                entry_name);
            if (Utilities::Success != ret)
            {
                return result;
            }

            auto file = Get_file(file_name);
            if (nullptr == file)
            {
                ERRLOG("Wrong asset id: " << id)
                return result;
            }

            auto desc = file->Get_descriptor(entry_name);
            if (nullptr == desc)
            {
                ERRLOG("Wrong asset id: " << id)
                return result;
            }

            result = file->Get_asset(*desc);
            if (result.Size() != desc->m_Size)
            {
                ERRLOG("File: " << file_name
                    << " is corrupted at id: " << id
                    << " offset " << desc->m_Offset
                    << " size: " << desc->m_Size);
                result.Release();
            }

            is_endianess_swapped = file->Is_endianess_swapped();

            return result;
        }

        File * Library::Get_file(const std::string & file_name)
        {
            auto file = Search(Helpers::Name_predicate<File>(file_name));

            if (nullptr != file)
            {
                return file;
            }

            file = new File;
            Platform::int32 ret = file->Load(file_name);
            if (Utilities::Success != ret)
            {
                ERRLOG("Not ava/ilable file: " << file_name);
                delete file;
                return nullptr;
            }

            Attach(file);
            file->m_Name(file_name);

            return file;
        }

        Platform::int32 Merge_asset_id(
            const std::string & archive_name,
            const std::string & entry_name,
            std::string & out_id)
        {
            out_id = archive_name;
            out_id.append(":");
            out_id.append(entry_name);

            return Utilities::Success;
        }

        Platform::int32 Split_asset_id(
            const std::string & id,
            std::string & out_archive_name,
            std::string & out_entry_name)
        {
            const size_t delim_off = id.find(':');
            const size_t str_length = id.length();

            if ((std::string::npos == delim_off) ||
                (0 == delim_off) ||
                (str_length <= delim_off + 2))
            {
                return Utilities::Invalid_parameter;
            }

            const size_t archive_name_length = delim_off;
            const size_t entry_name_offset = delim_off + 1;
            const size_t entry_name_length = str_length - entry_name_offset;

            out_archive_name = id.substr(0, archive_name_length);
            out_entry_name = id.substr(entry_name_offset, entry_name_length);

            return Utilities::Success;
        }
    }
}

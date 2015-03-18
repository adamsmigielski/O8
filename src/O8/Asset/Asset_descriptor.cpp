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
* @file Asset_descriptor.cpp
**/

#include "PCH.hpp"

#include "Asset_descriptor.hpp"

namespace O8
{
    namespace Asset
    {
        Asset_descriptor::Asset_descriptor()
            : m_Type(Type::Unknown)
        {
            /* Nothing to be done here */
        }

        Asset_descriptor::~Asset_descriptor()
        {
            /* Nothing to be done here */
        }

        int32 Merge_asset_id(
            const std::string & archive_name,
            const std::string & entry_name,
            std::string & out_id)
        {
            out_id = archive_name;
            out_id.append(":");
            out_id.append(entry_name);

            return Success;
        }

        int32 Split_asset_id(
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
                return Invalid_parameter;
            }

            const size_t archive_name_length = delim_off;
            const size_t entry_name_offset = delim_off + 1;
            const size_t entry_name_length = str_length - entry_name_offset;

            out_archive_name = id.substr(0, delim_off);
            out_entry_name = id.substr(entry_name_offset, entry_name_length);

            return Success;
        }

    }
}

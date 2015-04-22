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
* @file Library.hpp
**/

#ifndef O8_ASSET_LIBRARY_HPP
#define O8_ASSET_LIBRARY_HPP

#include "File.hpp"


namespace O8
{
    namespace Asset
    {
        class Library : public File::List
        {
        public:
            Library();
            virtual ~Library();

            virtual Utility::Binary_data Get_asset(const std::string & id);
            virtual File * Get_file(const std::string & file_name);
        };

        int32 Merge_asset_id(
            const std::string & archive_name,
            const std::string & entry_name,
            std::string & out_id);

        int32 Split_asset_id(
            const std::string & id,
            std::string & out_archive_name,
            std::string & out_entry_name);
    }
}

#endif O8_ASSET_LIBRARY_HPP

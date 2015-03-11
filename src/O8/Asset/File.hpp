/** License
*
* Copyright (c) 2014 Adam Œmigielski
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
* @file File.hpp
**/

#ifndef O8_ASSET_FILE_HPP
#define O8_ASSET_FILE_HPP

#include "Asset.hpp"
#include "Descriptor.hpp"
#include "Type.hpp"

#include <O8\Templates\IntrusiveList.hpp>

namespace O8
{
    namespace Asset
    {
        class File_descriptor : public Descriptor
                              , public IntrusiveList::Node<File_descriptor>
        {
        public:
            typedef IntrusiveList::List<File_descriptor> List;

            File_descriptor();
            virtual ~File_descriptor();

            uint64 m_Offset;
            uint64 m_Size;
            Type::Types m_Type;
        };

        class File : public File_descriptor::List
        {
        public:
            File();
            virtual ~File();

            virtual Asset * Get_asset(const File_descriptor & desc) const;
            virtual const File_descriptor * Get_descriptor(const std::string & id) const;
            virtual int32 Load(const std::string & file_name);

        private:
            std::string m_file_name;
        };

        typedef File * (O8_API * PFN_CREATE_FILE)();
        typedef int32 (O8_API * PFN_STORE_FILE)(
            const std::string & file_name,
            const Asset::List & assets);
    }
}

/* DL entry points */
O8_API_DECORATION DLL_EXPORT O8::Asset::File * O8_API Create_file();
O8_API_DECORATION DLL_EXPORT O8::int32 O8_API Store_file(
    const std::string & file_name,
    const O8::Asset::Asset::List & assets);

#endif O8_ASSET_FILE_HPP

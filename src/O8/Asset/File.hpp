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
* @file File.hpp
**/

#ifndef O8_ASSET_FILE_HPP
#define O8_ASSET_FILE_HPP

#include "Type.hpp"

#include <O8\Templates\IntrusiveList.hpp>
#include <O8\Utility\Binary_data.hpp>
#include <O8\Utility\Name.hpp>

namespace O8
{
    namespace Asset
    {
        class File_descriptor : public IntrusiveList::Node<File_descriptor>
        {
        public:
            typedef IntrusiveList::List<File_descriptor> List;

            File_descriptor();
            virtual ~File_descriptor();

            Utility::Name m_Name;
            uint64 m_Offset;
            uint64 m_Size;
            Type::Types m_Type;
        };

        class Asset_descriptor : public IntrusiveList::Node<Asset_descriptor>
        {
        public:
            /*Types */
            typedef IntrusiveList::List<Asset_descriptor> List;

            /* Ctr $ Dtr */
            virtual ~Asset_descriptor() {}

            virtual int32 Get_details(
                Utility::Binary_data & out_data,
                Type::Types & out_type) const = 0;
            virtual const std::string & Get_name() const = 0;

        protected:
            Asset_descriptor() {}
        };

        class File
            : public File_descriptor::List
            , public IntrusiveList::Node<File>
        {
        public:
            /* Types */
            typedef IntrusiveList::List<File> List;

            /* Ctr & Dtr */
            File();
            virtual ~File();

            /* Name */
            Utility::Name m_Name;

            /* Asset access */
            virtual Utility::Binary_data Get_asset(const File_descriptor & desc) const;
            virtual const File_descriptor * Get_descriptor(const std::string & id) const;
            virtual int32 Load(const std::string & file_name);

            /* Static routines */
            static int32 Store_file(
                const std::string & file_name,
                const Asset_descriptor * first,
                const Asset_descriptor * end);

        private:
            std::string m_file_name;
        };
    }
}

#endif O8_ASSET_FILE_HPP

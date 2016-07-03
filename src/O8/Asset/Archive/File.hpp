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

#include "O8\Asset\Type.hpp"

#include <Utilities\containers\IntrusiveList.hpp>
#include <Utilities\helpers\Name.hpp>
#include <Utilities\memory\Binary_data.hpp>

namespace O8
{
    namespace Asset
    {
        class File_descriptor : public Containers::IntrusiveList::Node<File_descriptor>
        {
        public:
            File_descriptor();
            virtual ~File_descriptor();

            Helpers::Name m_Name;
            Platform::uint64 m_Offset;
            Platform::uint64 m_Size;
            Type::Types m_Type;
        };

        class Asset_descriptor : public Containers::IntrusiveList::Node<Asset_descriptor>
        {
        public:
            /* Ctr $ Dtr */
            virtual ~Asset_descriptor() {}

            virtual Platform::int32 Get_details(
                Memory::Binary_data & out_data,
                Type::Types & out_type) const = 0;
            virtual const std::string & Get_name() const = 0;

        protected:
            Asset_descriptor() {}
        };

        class File
            : public File_descriptor::List
            , public Containers::IntrusiveList::Node<File>
        {
        public:
            /* Ctr & Dtr */
            File() = default;
            virtual ~File() = default;

            /* Name */
            Helpers::Name m_Name;

            /* Asset access */
            virtual Memory::Binary_data Get_asset(const File_descriptor & desc) const;
            virtual const File_descriptor * Get_descriptor(const std::string & id) const;
            virtual Platform::int32 Load(const std::string & file_name);

            /* Endianess */
            virtual bool Is_endianess_swapped() const;

            /* Static routines */
            static Platform::int32 Store_file(
                const std::string & file_name,
                const Asset_descriptor * first,
                const Asset_descriptor * end);

        private:
            std::string m_file_name;
            bool m_is_endianess_swapped = false;
        };
    }
}

#endif /* O8_ASSET_FILE_HPP */

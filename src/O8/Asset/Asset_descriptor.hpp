/** License
*
* Copyright (c) 2015 Adam �migielski
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
* @author Adam �migielski
* @file Asset_descriptor.hpp
**/

#ifndef O8_ASSET_ASSET_DESCRIPTOR_HPP
#define O8_ASSET_ASSET_DESCRIPTOR_HPP

#include <O8\Templates\IntrusiveList.hpp>
#include "Type.hpp"

namespace O8
{
    namespace Asset
    {
        class Asset_descriptor : public IntrusiveList::Node<Asset_descriptor>
        {
        public:
            typedef IntrusiveList::List<Asset_descriptor> List;

            Asset_descriptor();
            virtual ~Asset_descriptor();

            std::string m_ID;
            Type::Types m_Type;
            void * m_User_info;
        };

        class Asset_data_provider
        {
        public:
            Asset_data_provider();
            virtual ~Asset_data_provider();

            virtual void Provide_data(
                const Asset_descriptor & asset,
                const uint8 *& out_data_ptr,
                size_t & out_data_size);
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

#endif O8_ASSET_ASSET_DESCRIPTOR_HPP
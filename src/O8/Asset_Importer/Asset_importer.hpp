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
* @file Asset_importer.hpp
**/

#ifndef O8_ASSET_IMPORTER_ASSET_IMPORTER_HPP
#define O8_ASSET_IMPORTER_ASSET_IMPORTER_HPP


#include <O8\Asset\Type.hpp>
#include <O8\Templates\IntrusiveList.hpp>
#include <O8\Utility\Binary_data.hpp>

namespace O8
{
    namespace DL
    {
        class DL;
    }

    namespace Asset_importer
    {
        class Asset_importer : public O8::IntrusiveList::Node<Asset_importer>
        {
        public:
            Asset_importer();
            virtual ~Asset_importer();

            virtual bool Is_format_supported(const std::string & name);
            virtual int32 Get_asset(
                const std::string & file_path,
                Utility::Binary_data & out_data,
                Asset::Type::Types & out_type);

            DL::DL * m_Dl;
        };

        typedef Asset_importer * (O8_API * PFN_CREATE_IMPORTER)();
    }
}

#endif /* O8_ASSET_IMPORTER_ASSET_IMPORTER_HPP */

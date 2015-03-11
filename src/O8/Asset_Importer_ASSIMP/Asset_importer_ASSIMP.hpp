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
* @file Asset_importer_ASSIMP.hpp
**/

#ifndef O8_ASSET_IMPORTER_ASSIMP_HPP
#define O8_ASSET_IMPORTER_ASSIMP_HPP

#include <O8\Asset_Importer\Asset_importer.hpp>

namespace O8
{
    namespace Asset
    {
        class Asset;
    }

    namespace DL
    {
        class DL;
    }

    namespace Asset_importer
    {
        class Asset_importer_ASSIMP : public Asset_importer
        {
        public:
            Asset_importer_ASSIMP();
            virtual ~Asset_importer_ASSIMP();

            virtual bool Is_format_supported(const std::string & name);
            virtual Asset::Asset * Get_asset(const std::string & file_path);
        };
    }
}

O8_API_DECORATION DLL_EXPORT O8::Asset_importer::Asset_importer * O8_API Create_importer();

#endif /* O8_ASSET_IMPORTER_ASSIMP_HPP */

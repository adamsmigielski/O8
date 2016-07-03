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
* @file Asset_importer_ASSIMP.hpp
**/

#ifndef O8_ASSET_IMPORTER_ASSIMP_HPP
#define O8_ASSET_IMPORTER_ASSIMP_HPP

#include <O8\Asset\Importer.hpp>

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

    namespace Asset
    {
        class Importer_ASSIMP : public Importer
        {
        public:
            Importer_ASSIMP();
            virtual ~Importer_ASSIMP();

            virtual Platform::int32 Init();

            virtual Platform::int32 Get_asset(
                const std::string & file_path,
                Memory::Binary_data & out_data,
                Type::Types & out_type);
        };
    }
}

UTILITIES_API_DECORATION DLL_EXPORT O8::Asset::Importer * UTILITIES_API Create_importer();

#endif /* O8_ASSET_IMPORTER_ASSIMP_HPP */

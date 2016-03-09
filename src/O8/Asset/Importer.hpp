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

#ifndef O8_ASSET_IMPORTER_HPP
#define O8_ASSET_IMPORTER_HPP


#include <Utilities\containers\IntrusiveList.hpp>
#include <Utilities\memory\Binary_data.hpp>

#include "Type.hpp"

namespace O8
{
    namespace DL
    {
        class DL;
    }

    namespace Asset
    {
        class Importer
        {
        public:
            Importer();

            virtual Platform::int32 Init() = 0;

            virtual Platform::int32 Get_asset(
                const std::string & file_path,
                Memory::Binary_data & out_data,
                Type::Types & out_type) = 0;

            static void Deleter(Importer * importer);

            DL::DL * m_Dl;

        protected:
            virtual ~Importer();
        };

        typedef Importer * (UTILITIES_API * PFN_CREATE_IMPORTER)();
    }
}

#endif /* O8_ASSET_IMPORTER_HPP */

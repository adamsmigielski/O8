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
* @file Library.hpp
**/

#ifndef O8_ASSET_LIBRARY_HPP
#define O8_ASSET_LIBRARY_HPP

#include "Descriptor.hpp"

#include <O8\Templates\IntrusiveList.hpp>

namespace O8
{
    namespace Asset
    {
        class Library_descriptor : public Descriptor
                                 , public IntrusiveList::Node<Library_descriptor>
        {
        public:
            Library_descriptor();
            virtual ~Library_descriptor();

            std::string m_Path;
        };

        class Library : public IntrusiveList::List<Library_descriptor>
        {
        public:
            Library();
            virtual ~Library();

            virtual int32 Load(const std::string & file_name);
            virtual int32 Store(const std::string & file_name) const;
        };

        typedef Library * (O8_API * PFN_CREATE_LIBRARY)();
    }
}

/* DL entry points */
O8_API_DECORATION DLL_EXPORT O8::Asset::Library * O8_API Create_library();

#endif O8_ASSET_LIBRARY_HPP

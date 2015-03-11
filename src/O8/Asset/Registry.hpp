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
* @file Registry.hpp
**/

#ifndef O8_ASSET_REGISTRY_HPP
#define O8_ASSET_REGISTRY_HPP

#include "Descriptor.hpp"
#include "Type.hpp"

#include <O8\Templates\IntrusiveList.hpp>

namespace O8
{
    namespace Asset
    {
        class Registry_descriptor : public Descriptor
                                  , public IntrusiveList::Node<Registry_descriptor>
        {
        public:
            Registry_descriptor();
            virtual ~Registry_descriptor();

            std::string m_Path;
            Type::Types m_Type;
        };

        class Registry : public IntrusiveList::List<Registry_descriptor>
        {
        public:
            Registry();
            Registry(const Registry &) = delete;
            Registry & operator = (const Registry &) = delete;

            virtual ~Registry();

            virtual int32 Load(const std::string & file_name);
            virtual int32 Store(const std::string & file_name) const;
        };

        typedef Registry * (O8_API * PFN_CREATE_REGISTRY)();
    }
}

/* DL entry points */
O8_API_DECORATION DLL_EXPORT O8::Asset::Registry * O8_API Create_registry();

#endif O8_ASSET_REGISTRY_HPP

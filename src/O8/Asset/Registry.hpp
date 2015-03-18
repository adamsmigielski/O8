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
* @file Registry.hpp
**/

#ifndef O8_ASSET_REGISTRY_HPP
#define O8_ASSET_REGISTRY_HPP

#include "Type.hpp"

#include <O8\Templates\IntrusiveList.hpp>
#include <O8\Utility\Name.hpp>

namespace O8
{
    namespace Asset
    {
        class Registry_entry : public IntrusiveList::Node<Registry_entry>
        {
        public:
            Registry_entry();
            virtual ~Registry_entry();

            Utility::Name m_Name;
            std::string m_Path;
        };

        class Registry : public IntrusiveList::List<Registry_entry>
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
        typedef Registry_entry * (O8_API * PFN_CREATE_REGISTRY_ENTRY)();
    }
}

/* DL entry points */
O8_API_DECORATION DLL_EXPORT O8::Asset::Registry * O8_API Create_registry();
O8_API_DECORATION DLL_EXPORT O8::Asset::Registry_entry * O8_API Create_registry_entry();

#endif O8_ASSET_REGISTRY_HPP

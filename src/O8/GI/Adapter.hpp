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
* @file Adapter.hpp
**/

#ifndef O8_GI_ADAPTER_HPP
#define O8_GI_ADAPTER_HPP

#include <O8\Templates\IntrusiveList.hpp>
#include "Output.hpp"

namespace O8
{
    namespace GI
    {
        class Adapter : public IntrusiveList::Node < Adapter >
                      , public IntrusiveList::List < Output >
        {
        public:
            Adapter();
            virtual ~Adapter();

            virtual std::string Name() const = 0;

            virtual unsigned int Vendor_id() const = 0;
            virtual unsigned int Device_id() const = 0;
            virtual unsigned int Video_memory() const = 0;
            virtual unsigned int System_memory() const = 0;
            virtual unsigned int Shared_memory() const = 0;
        };
    }
}

#endif /* O8_GI_ADAPTER_HPP */

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
* @file GI.hpp
**/

#ifndef O8_GI_GI_HPP
#define O8_GI_GI_HPP

#include <Utilities\containers\IntrusiveList.hpp>
#include "Adapter.hpp"

namespace O8
{
    namespace GI
    {
        class RI;

        class GI : public Containers::IntrusiveList::List<Adapter>
        {
        public:
            virtual ~GI();

            virtual Platform::int32 Init() = 0;
            virtual void Release() = 0;

            virtual RI * Create_rendering_interface(
                Adapter * adapter) = 0;

        protected:
            GI();
        };

        typedef O8::GI::GI * (UTILITIES_API *PFN_CREATE_GI)();
    }
}

#endif /* O8_GI_GI_HPP */

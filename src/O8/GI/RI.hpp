/** License
*
* Copyright (c) 2015 Adam Śmigielski
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
* @author Adam Śmigielski
* @file RI.hpp
**/

#ifndef O8_GI_RI_HPP
#define O8_GI_RI_HPP

#include <Utilities\containers\IntrusiveList.hpp>
#include "Presentation.hpp"
#include "Texture.hpp"

namespace O8
{
    namespace GI
    {
        class RI
        {
        public:
            typedef Containers::IntrusiveList::List < Presentation > Presentation_list;
            typedef Containers::IntrusiveList::List < Texture > Texture_list;

            virtual ~RI();

            virtual Presentation * Create_presentation_for_window(Presentation::Native native) = 0;
            virtual Presentation_list * Get_presenentaton_list() = 0;

            virtual Texture * Create_texture() = 0;
            virtual Texture_list * Get_texture_list() = 0;


        protected:
            RI();
        };
    }
}

#endif /* O8_GI_RI_HPP */

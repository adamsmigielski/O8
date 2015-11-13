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
* @file Texture.hpp
**/

#ifndef O8_GI_TEXTURE_HPP
#define O8_GI_TEXTURE_HPP

#include <Utilities\containers\IntrusiveList.hpp>
#include <Utilities\containers\ReferenceCounted.hpp>

namespace O8
{
    namespace GI
    {
        class Texture
            : public Containers::IntrusiveList::Node < Texture >
            , public Containers::ReferenceCounted::Resource < Texture >
        {
        public:
            /* Enums */
            enum MODEL
            {
                MODEL_UNKNOWN = 0,
                MODEL_2D,
                MODEL_2D_ARRAY,
                MODEL_3D,
                MODEL_CUBE,
                MODEL_CUBE_ARRAY,
            };

            /* Ctr & Dtr */
            virtual ~Texture();

        protected:
            Texture();

            MODEL m_model;
        };
    }
}

#endif /* O8_GI_TEXTURE_HPP */

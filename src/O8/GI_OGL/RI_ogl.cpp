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
* @file RI_ogl.cpp
**/

#include "PCH.hpp"

#include "RI_ogl.hpp"

#include "Texture_ogl.hpp"

namespace O8
{
    namespace GI
    {
        RI_ogl::RI_ogl()
        {
        }

        RI_ogl::~RI_ogl()
        {
        }

        Texture * RI_ogl::Create_texture()
        {
            auto texture = new Texture_ogl;

            if (nullptr == texture)
            {
                ERRLOG("Failed to allocate memory");
                ASSERT(0);
                return nullptr;
            }

            /* TODO Init */

            m_texture_list.Attach(texture);

            return texture;
        }

        RI::Texture_list * RI_ogl::Get_texture_list()
        {
            return &m_texture_list;
        }
    }
}

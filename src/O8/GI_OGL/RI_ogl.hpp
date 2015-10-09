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
* @file RI_ogl.hpp
**/

#ifndef O8_GI_RI_OGL_HPP
#define O8_GI_RI_OGL_HPP

#include <O8\GI\RI.hpp>

namespace OpenGL
{
    class Context;
}

namespace O8
{
    namespace GI
    {
        class RI_ogl : public RI
        {
        public:
            virtual ~RI_ogl();

            virtual OpenGL::Context * Get_context() = 0;

            virtual Presentation * Create_presentation_for_window(Presentation::Native native) = 0;
            virtual Presentation_list * Get_presenentaton_list() = 0;

            virtual Texture * Create_texture();
            virtual Texture_list * Get_texture_list();

        protected:
            RI_ogl();

        private:
            RI::Texture_list m_texture_list;
        };
    }
}

#endif /* O8_GI_RI_OGL_HPP */

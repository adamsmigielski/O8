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
* @file Presentation_win_ogl.hpp
**/

#ifndef O8_GI_PRESENTATION_WIN_OGL_HPP
#define O8_GI_PRESENTATION_WIN_OGL_HPP

#include <O8\GI_OGL\Presentation_ogl.hpp>

namespace O8
{
    namespace GI
    {
        class Context_win_ogl;

        class Presentation_win_ogl : public Presentation_ogl
        {
        public:
            Presentation_win_ogl();
            virtual ~Presentation_win_ogl();

            int32 Init(
                HWND hwnd,
                Context_win_ogl * parent_context);

            virtual OpenGL::Context * Get_context();
            virtual Native Get_native();
            virtual void Make_current();
            virtual void Present();

        private:
            Context_win_ogl * m_context;
            HWND m_hwnd;
        };
    }
}

#endif /* O8_GI_PRESENTATION_WIN_OGL_HPP */

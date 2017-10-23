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
* @file RI_win_ogl.hpp
**/

#ifndef O8_GI_RI_WIN_OGL_HPP
#define O8_GI_RI_WIN_OGL_HPP

#include <O8\GI_OGL\RI_ogl.hpp>

namespace O8
{
    namespace GI
    {
        class Context_win_ogl;
        class Output_win_ogl;

        class RI_win_ogl : public RI_ogl
        {
        public:
            RI_win_ogl();
            virtual ~RI_win_ogl();

            Platform::int32 Init(
                Output_win_ogl * output);

            virtual OpenGL::Context * Get_context();

            virtual Presentation * Create_presentation_for_window(
                Presentation::Native native);
            virtual Presentation_list * Get_presenentaton_list();

        private:
            HWND create_ogl_window(
                Platform::int32 left,
                Platform::int32 right,
                Platform::int32 top,
                Platform::int32 bottom);

            HWND m_ogl_window;
            Context_win_ogl * m_parent_context;
            RI::Presentation_list m_presentation_list;
        };
    }
}

#endif /* O8_GI_RI_WIN_OGL_HPP */

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
* @file Context_win_ogl.hpp
**/

#ifndef O8_GI_CONTEXT_WIN_OGL_HPP
#define O8_GI_CONTEXT_WIN_OGL_HPP

#undef MemoryBarrier
#include <O8\OpenGL\Context.hpp>
#include <Windows.h>
//#include "wglext.h"

namespace O8
{
    namespace DL
    {
        class DL;
    }

    namespace GI
    {
        class Context_win_ogl : public OpenGL::Context
        {
        public:
            Context_win_ogl();
            virtual ~Context_win_ogl();

            int32 Init(
                HDC hdc);
            int32 Init(
                HDC hdc,
                Context_win_ogl * parent_context);
            HDC GetDC() const;
            int32 LoadWGL();

            virtual void Make_current();
            virtual void Swap();

            virtual void * Get_proc_address(const char * name);


        private:
            HGLRC create_extended_context(
                HDC hdc,
                HGLRC basic_context,
                HGLRC shared_context,
                int32 major,
                int32 minor);
            int32 init_gl_rc(
                HDC hdc,
                Context_win_ogl * parent_context,
                int32 major,
                int32 minor,
                HGLRC & out_hglrc);
            int32 prepare_pixel_format(
                HDC hdc,
                PIXELFORMATDESCRIPTOR & pixel_format);

            typedef HGLRC (WINAPI * PFNWGLCREATECONTEXT)(
                HDC device_context);
            typedef HGLRC (WINAPI * PFNWGLCREATECONTEXTATTRIBSARBPROC)(
                HDC hDC,
                HGLRC hShareContext,
                const int32 *attribList);
            typedef BOOL(WINAPI * PFNWGLDELETECONTEXT)(
                HGLRC opengl_context);
            typedef PROC (WINAPI * PFNWGLGETPROCADDRESS)(
                LPCSTR name);
            typedef BOOL(WINAPI * PFNWGLMAKECURRENT)(
                HDC device_context,
                HGLRC opengl_context);
            typedef BOOL (WINAPI * PFNSWAPBUFFERS)(
                HDC device_context);

            PFNWGLCREATECONTEXT m_create_context;
            PFNWGLCREATECONTEXTATTRIBSARBPROC m_create_context_attribs;
            PFNWGLDELETECONTEXT m_delete_context;
            PFNWGLGETPROCADDRESS m_get_proc_address;
            PFNWGLMAKECURRENT m_make_current;
            PFNSWAPBUFFERS m_swap_buffers;

            HDC m_hdc;
            HGLRC m_hglrc;
            int32 m_major;
            int32 m_minor;

            static DL::DL * s_gdi_dl;
            static DL::DL * s_opengl_dl;
        };
    }
}

#endif /* O8_GI_CONTEXT_WIN_OGL_HPP */

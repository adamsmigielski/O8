/** License
*
* Copyright (c) 2014 Adam �migielski
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
* @file Context_win_ogl.cpp
**/

#include "PCH.hpp"

#include "Context_win_ogl.hpp"

#include <O8\DL\DL.hpp>
#include <O8\OpenGL\GL_loader.hpp>

#define WGL_CONTEXT_MAJOR_VERSION_ARB          0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB          0x2092
#define WGL_CONTEXT_FLAGS_ARB                  0x2094
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002

namespace O8
{
    namespace GI
    {
        DL::DL * Context_win_ogl::s_gdi_dl = nullptr;
        DL::DL * Context_win_ogl::s_opengl_dl = nullptr;

        Context_win_ogl::Context_win_ogl()
            : m_create_context        (nullptr)
            , m_create_context_attribs(nullptr)
            , m_delete_context        (nullptr)
            , m_get_proc_address      (nullptr)
            , m_make_current          (nullptr)
            , m_swap_buffers          (nullptr)
            , m_hdc                   (NULL)
            , m_hglrc                 (NULL)
            , m_major                 (0)
            , m_minor                 (0)
        {
        }

        Context_win_ogl::~Context_win_ogl()
        {
            if (NULL != m_hdc)
            {
                if (nullptr != m_delete_context)
                {
                    if (NULL != m_hglrc)
                    {
                        ASSERT(nullptr != m_make_current);

                        m_make_current(m_hdc, NULL);
                        m_delete_context(m_hglrc);
                    }
                }
            }

            m_create_context         = nullptr;
            m_create_context_attribs = nullptr;
            m_delete_context         = nullptr;
            m_get_proc_address       = nullptr;
            m_make_current           = nullptr;
            m_swap_buffers           = nullptr;
            m_hdc                    = NULL;
            m_hglrc                  = NULL;
            m_major                  = 0;
            m_minor                  = 0;
        }

        struct gl_version
        {
            int32 major;
            int32 minor;
        };

        static const gl_version known_gl_versions[] =
        {
            { 4, 5 },
            { 4, 4 },
            { 4, 3 },
            { 4, 2 },
            { 4, 1 },
            { 4, 0 },
            { 3, 3 },
            { 3, 2 },
            { 3, 1 },
            { 3, 0 },
        };

        static const uint32 n_known_gl_versions =
            sizeof(known_gl_versions) / sizeof(gl_version);

        int32 Context_win_ogl::Init(
            HDC hdc)
        {
            int32 ret;
            HGLRC hglrc = NULL;

            if (NULL != m_hdc)
            {
                ERRLOG("Context already initialized");
                ASSERT(0);
                return Invalid_object;
            }

            ret = LoadWGL();
            if (Success != ret)
            {
                ERRLOG("Cannot load wgl");
                return Failure;
            }

            for (uint32 i = 0; i < n_known_gl_versions; ++i)
            {
                const int32 major = known_gl_versions[i].major;
                const int32 minor = known_gl_versions[i].minor;

                DEBUGLOG("Test:" << major << "." << minor);

                ret = init_gl_rc(
                    hdc,
                    nullptr,
                    major,
                    minor,
                    hglrc);

                if (Success != ret)
                {
                    DEBUGLOG("Failed");
                }
                else
                {
                    DEBUGLOG("Success");

                    m_hdc = hdc;
                    m_hglrc = hglrc;

                    Make_current();

                    DEBUGLOG("Get GL");
                    OpenGL::LoadGL(*this);

                    const OpenGL::Functions & gl = Functions();

                    gl.GetIntegerv(GL_MAJOR_VERSION, &m_major);
                    gl.GetIntegerv(GL_MINOR_VERSION, &m_minor);

                    DEBUGLOG("Success:" << m_major << "." << m_minor);

                    break;
                }
            }

            /* ret == Success when successful */
            return ret;
        }



        int32 Context_win_ogl::Init(
            HDC hdc,
            Context_win_ogl * parent_context)
        {
            int32 ret;
            HGLRC hglrc = NULL;
            PIXELFORMATDESCRIPTOR pixel_format;

            pixel_format.nSize = sizeof(PIXELFORMATDESCRIPTOR);
            pixel_format.nVersion = 1;
            pixel_format.dwFlags = PFD_DRAW_TO_WINDOW
                | PFD_SUPPORT_OPENGL
                | PFD_DOUBLEBUFFER;
            pixel_format.iPixelType = PFD_TYPE_RGBA;
            pixel_format.cColorBits = 32;
            pixel_format.cDepthBits = 32;
            pixel_format.iLayerType = PFD_MAIN_PLANE;

            ret = prepare_pixel_format(
                hdc,
                pixel_format);
            if (Success != ret)
            {
                return ret;
            }

            int32 attributes[] = {
                WGL_CONTEXT_MAJOR_VERSION_ARB, parent_context->m_major,
                WGL_CONTEXT_MINOR_VERSION_ARB, parent_context->m_minor,
                WGL_CONTEXT_FLAGS_ARB,
                WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB, 0
            };

            if (NULL != m_hdc)
            {
                ERRLOG("Context already initialized");
                ASSERT(0);
                return Invalid_object;
            }

            ret = LoadWGL();
            if (Success != ret)
            {
                ERRLOG("Cannot load wgl");
                return Failure;
            }

            DEBUGLOG("Test:" 
                << parent_context->m_major
                << "."
                << parent_context->m_minor);

            m_create_context_attribs = parent_context->m_create_context_attribs;

            hglrc = m_create_context_attribs(
                hdc,
                parent_context->m_hglrc,
                attributes);

            if (NULL == hglrc)
            {
                DEBUGLOG("Failed: " << GetLastError());

                return Failure;
            }
            else
            {
                DEBUGLOG("Success");

                m_hdc = hdc;
                m_hglrc = hglrc;

                Make_current();

                DEBUGLOG("Get GL");
                OpenGL::LoadGL(*this);

                const OpenGL::Functions & gl = Functions();

                gl.GetIntegerv(GL_MAJOR_VERSION, &m_major);
                gl.GetIntegerv(GL_MINOR_VERSION, &m_minor);

                DEBUGLOG("Success:" << m_major << "." << m_minor);
            }

            return Success;
        }

        HDC Context_win_ogl::GetDC() const
        {
            return m_hdc;
        }

        void Context_win_ogl::Make_current()
        {
            ASSERT(nullptr != m_make_current);

            m_make_current(m_hdc, m_hglrc);
        }

        void Context_win_ogl::Swap()
        {
            ASSERT(nullptr != m_swap_buffers);

            m_swap_buffers(m_hdc);
        }

        void * Context_win_ogl::Get_proc_address(const char * name)
        {
            ASSERT(nullptr != m_get_proc_address);

            return m_get_proc_address(name);
        }

        int32 Context_win_ogl::LoadWGL()
        {
            if (nullptr == s_opengl_dl)
            {
                s_gdi_dl = DL::Load("gdi32.dll");
                s_opengl_dl = DL::Load("opengl32.dll");

                if (nullptr == s_gdi_dl)
                {
                    ASSERT(0);
                    ERRLOG("Failed to load gdi32.dll");
                    return O8::Failed_to_load_library;
                }

                if (nullptr == s_opengl_dl)
                {
                    ASSERT(0);
                    ERRLOG("Failed to load opengl32.dll");
                    return O8::Failed_to_load_library;
                }
            }

            m_create_context   = (PFNWGLCREATECONTEXT)  s_opengl_dl->GetFunctionAddress("wglCreateContext");
            m_delete_context   = (PFNWGLDELETECONTEXT)  s_opengl_dl->GetFunctionAddress("wglDeleteContext");
            m_get_proc_address = (PFNWGLGETPROCADDRESS) s_opengl_dl->GetFunctionAddress("wglGetProcAddress");
            m_make_current     = (PFNWGLMAKECURRENT)    s_opengl_dl->GetFunctionAddress("wglMakeCurrent");
            m_swap_buffers     = (PFNSWAPBUFFERS)       s_gdi_dl->GetFunctionAddress("SwapBuffers");

            if ((nullptr == m_create_context) ||
                (nullptr == m_delete_context) ||
                (nullptr == m_get_proc_address) ||
                (nullptr == m_make_current) ||
                (nullptr == m_swap_buffers))
            {
                ASSERT(0);
                ERRLOG("Failed to load wgl functions");
                return O8::Failed_to_load_function;
            }

            return Success;
        }

        HGLRC Context_win_ogl::create_extended_context(
            HDC hdc,
            HGLRC basic_context,
            HGLRC shared_context,
            int major,
            int minor)
        {
            int32 attributes[] = {
                WGL_CONTEXT_MAJOR_VERSION_ARB, major,
                WGL_CONTEXT_MINOR_VERSION_ARB, minor,
                WGL_CONTEXT_FLAGS_ARB,
                WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB, 0
            };

            m_make_current(hdc, basic_context);

            m_create_context_attribs = (PFNWGLCREATECONTEXTATTRIBSARBPROC) m_get_proc_address("wglCreateContextAttribsARB");

            return m_create_context_attribs(
                hdc,
                shared_context,
                attributes);
        }

        int32 Context_win_ogl::init_gl_rc(
            HDC hdc,
            Context_win_ogl * parent_context,
            int32 major,
            int32 minor,
            HGLRC & out_hglrc)
        {
            HGLRC basic_context = NULL;
            HGLRC extended_context = NULL;
            HGLRC shared_context = NULL;
            PIXELFORMATDESCRIPTOR pixel_format;

            DEBUGLOG("Prepare pixel format");

            pixel_format.nSize = sizeof(PIXELFORMATDESCRIPTOR);
            pixel_format.nVersion = 1;
            pixel_format.dwFlags = PFD_DRAW_TO_WINDOW
                | PFD_SUPPORT_OPENGL
                | PFD_DOUBLEBUFFER;
            pixel_format.iPixelType = PFD_TYPE_RGBA;
            pixel_format.cColorBits = 32;
            pixel_format.cDepthBits = 32;
            pixel_format.iLayerType = PFD_MAIN_PLANE;

            int32 ret = prepare_pixel_format(
                hdc,
                pixel_format);
            if (Success != ret)
            {
                return ret;
            }

            DEBUGLOG("Create basic context");
            basic_context = m_create_context(hdc);
            if (NULL == basic_context)
            {
                ASSERT(0);
                ERRLOG(" Failed to create basic OGL context");
                return Failure;
            }

            if (nullptr != parent_context)
            {
                shared_context = parent_context->m_hglrc;
            }

            DEBUGLOG("Create extended context");
            extended_context = create_extended_context(
                hdc,
                basic_context,
                shared_context,
                major,
                minor);

            m_make_current(hdc, extended_context);

            DEBUGLOG("Delete basic context");
            m_delete_context(basic_context);

            if (NULL == extended_context)
            {
                ERRLOG("Failed to create extended OGL context");
                return Failure;
            }

            out_hglrc = extended_context;
            return Success;
        }

        int32 Context_win_ogl::prepare_pixel_format(
            HDC hdc,
            PIXELFORMATDESCRIPTOR & pixel_format)
        {
            int32 format_index = ChoosePixelFormat(hdc, &pixel_format);
            BOOL ret;

            ret = SetPixelFormat(hdc, format_index, &pixel_format);
            if (FALSE == ret)
            {
                ERRLOG("SetPixelFormat failed");
                ASSERT(0);
                return Failure;
            }

            return Success;
        }
    }
}


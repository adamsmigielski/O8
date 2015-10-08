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
* @file RI_win_ogl.cpp
**/

#include "PCH.hpp"

#include "RI_win_ogl.hpp"

#include "Context_win_ogl.hpp"
#include "Presentation_win_ogl.hpp"
#include "Output_win_ogl.hpp"

namespace O8
{
    namespace GI
    {
        RI_win_ogl::RI_win_ogl()
            : m_ogl_window(NULL)
            , m_parent_context(nullptr)
        {
        }

        RI_win_ogl::~RI_win_ogl()
        {
            if (NULL != m_ogl_window)
            {
                if (nullptr != m_parent_context)
                {
                    HDC hdc = m_parent_context->GetDC();
                    delete m_parent_context;
                    m_parent_context = nullptr;

                    ReleaseDC(m_ogl_window, hdc);
                }

                DestroyWindow(m_ogl_window);
                m_ogl_window = NULL;
            }
        }

        Platform::int32 RI_win_ogl::Init(
            Output_win_ogl * output)
        {
            DEBUGLOG("Create ogl window");
            auto window = create_ogl_window(
                output->Left(),
                output->Right(),
                output->Top(),
                output->Bottom());

            if (NULL == window)
            {
                ASSERT(0);
                ERRLOG("Failed to create window for rendering interface");
                return Utilities::Failure;
            }

            auto hdc = GetDC(window);
            if (NULL == hdc)
            {
                auto err = GetLastError();

                ASSERT(0);
                ERRLOG("Failed to get DC: " << err);
                DestroyWindow(window);
                return Utilities::Failure;
            }

            auto context = new Context_win_ogl;
            if (nullptr == context)
            {
                ASSERT(0);
                ERRLOG("Failed to create ogl context");
                ReleaseDC(window, hdc);
                DestroyWindow(window);
                return Utilities::Failure;
            }

            auto ret = context->Init(hdc);
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                ERRLOG("Failed to initialize context");
                delete context;
                ReleaseDC(window, hdc);
                DestroyWindow(window);
                return Utilities::Failure;
            }

            m_ogl_window = window;
            m_parent_context = context;

            m_parent_context->Make_current();
            ShowWindow(window, SW_HIDE);

            const char * name = (const char *) m_parent_context->Functions().GetString(GL_VERSION);

            LOG("OpenGL context created, version string: " << name);
            return Utilities::Success;
        }

        OpenGL::Context * RI_win_ogl::Get_context()
        {
            return m_parent_context;
        }

        Presentation * RI_win_ogl::Create_presentation_for_window(
            Presentation::Native native)
        {
            auto hwnd = *(HWND *) native;
            auto presentation = new Presentation_win_ogl();

            if (nullptr == presentation)
            {
                ERRLOG("Failed to allocate memory");
                ASSERT(0);
                return nullptr;
            }

            m_parent_context->Make_current();

            auto ret = presentation->Init(hwnd, m_parent_context);
            if (Utilities::Success != ret)
            {
                ERRLOG("Failed to create presentation");
                ASSERT(0);
                delete presentation;
                return nullptr;
            }

            m_presentation_list.Attach(presentation);

            return presentation;
        }

        RI::Presentation_list * RI_win_ogl::Get_presenentaton_list()
        {
            return &m_presentation_list;
        }

        LRESULT ogl_win_proc(
            HWND hwnd,
            UINT uMsg,
            WPARAM wParam,
            LPARAM lParam)
        {
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }

        HWND RI_win_ogl::create_ogl_window(
            Platform::int32 left,
            Platform::int32 right,
            Platform::int32 top,
            Platform::int32 bottom)
        {
            HWND wnd;
            WNDCLASSEX wndClass;
            int width = right - left;
            int height = bottom - top;

            width /= 3;
            height /= 3;

            wndClass.cbSize = sizeof(WNDCLASSEX);
            wndClass.style = 0;// CS_NOCLOSE;
            wndClass.lpfnWndProc = (WNDPROC) ogl_win_proc;
            wndClass.cbClsExtra = 0;
            wndClass.cbWndExtra = 0;
            wndClass.hInstance = GetModuleHandle(0);
            wndClass.hIcon = 0;
            wndClass.hCursor = 0;
            wndClass.hbrBackground = 0;
            wndClass.lpszMenuName = 0;
            wndClass.lpszClassName = "O8OGLContextCreate";
            wndClass.hIconSm = 0;

            RegisterClassEx(&wndClass);

            wnd = CreateWindowEx(0,
                "O8OGLContextCreate",
                "O8OGLContextWindow",
                WS_VISIBLE,//WS_DISABLED,
                left + width,
                top + height,
                width,
                height,
                GetDesktopWindow(),
                0,
                GetModuleHandle(0),
                0);

            return wnd;
        }
    }
}

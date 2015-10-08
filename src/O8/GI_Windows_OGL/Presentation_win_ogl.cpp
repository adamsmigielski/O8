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
* @file Presentation_win_ogl.cpp
**/

#include "PCH.hpp"

#include "Presentation_win_ogl.hpp"

#include "Context_win_ogl.hpp"

namespace O8
{
    namespace GI
    {
        Presentation_win_ogl::Presentation_win_ogl()
            : m_context(nullptr)
            , m_hwnd(NULL)
        {
        }

        Presentation_win_ogl::~Presentation_win_ogl()
        {
            if (NULL != m_hwnd)
            {
                if (nullptr != m_context)
                {
                    HDC hdc = m_context->GetDC();
                    delete m_context;
                    m_context = nullptr;

                    ReleaseDC(m_hwnd, hdc);
                }

                m_hwnd = NULL;
            }
        }

        Platform::int32 Presentation_win_ogl::Init(
            HWND hwnd,
            Context_win_ogl * parent_context)
        {
            if (NULL != m_hwnd)
            {
                ERRLOG("Presentation already initialized");
                ASSERT(0);
                return Utilities::Invalid_object;
            }

            auto hdc = GetDC(hwnd);
            if (NULL == hdc)
            {
                auto err = GetLastError();

                ASSERT(0);
                ERRLOG("Failed to get DC: " << err);
                return Utilities::Failure;
            }

            auto context = new Context_win_ogl;
            if (nullptr == context)
            {
                ASSERT(0);
                ERRLOG("Failed to create ogl context");
                ReleaseDC(hwnd, hdc);
                return Utilities::Failure;
            }

            auto ret = context->Init(hdc, parent_context);
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                ERRLOG("Failed to initialize context");
                delete context;
                ReleaseDC(hwnd, hdc);
                return Utilities::Failure;
            }

            m_context = context;
            m_hwnd = hwnd;

            return Utilities::Success;
        }

        OpenGL::Context * Presentation_win_ogl::Get_context()
        {
            return m_context;
        }

        Presentation::Native Presentation_win_ogl::Get_native()
        {
            return &m_hwnd;
        }

        void Presentation_win_ogl::Make_current()
        {
            ASSERT(m_context);

            m_context->Make_current();
        }

        void Presentation_win_ogl::Present()
        {
            ASSERT(m_context);

            m_context->Swap();
        }
    }
}

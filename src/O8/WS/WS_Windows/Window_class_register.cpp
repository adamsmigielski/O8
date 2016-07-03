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
* @file Window_class_register.cpp
**/

#include "PCH.hpp"

#include "Window_class_register.hpp"

namespace O8
{
    namespace WS
    {
        const char * Window_class_register::s_window_class_name = "O8DefaultWindowClass";

        Window_class_register::Window_class_register()
        {
            WNDCLASSEX wndClass;
            wndClass.cbSize = sizeof(WNDCLASSEX);
            wndClass.style = 0;// CS_NOCLOSE;
            wndClass.lpfnWndProc = (WNDPROC) window_procedure;
            wndClass.cbClsExtra = 0;
            wndClass.cbWndExtra = 0;
            wndClass.hInstance = GetModuleHandle(0);
            wndClass.hIcon = 0;
            wndClass.hCursor = 0;
            wndClass.hbrBackground = 0;
            wndClass.lpszMenuName = 0;
            wndClass.lpszClassName = s_window_class_name;
            wndClass.hIconSm = 0;

            ATOM reg = RegisterClassEx(&wndClass);

            if (0 == reg)
            {
                DWORD err = GetLastError();
                if (1410 == err) //class WINDOW_DLL registred
                {
                }
                else
                {
                    ASSERT(0);
                    ERRLOG("Error occured: " << err);
                    return;
                }
            }

            DEBUGLOG(s_window_class_name << " class registered");
        }

        Window_class_register::~Window_class_register()
        {
            UnregisterClass(s_window_class_name, GetModuleHandle(0));

            DEBUGLOG(s_window_class_name << " class WINDOW_DLL unregistered");
        }

        const char * Window_class_register::Get_class_name() const
        {
            return s_window_class_name;
        }

        LRESULT Window_class_register::window_procedure(
            HWND hwnd,
            UINT msg,
            WPARAM wParam,
            LPARAM lParam)
        {
            return DefWindowProc(hwnd, msg, wParam, lParam);
        }
    }
}

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
* @file Window_class_register.hpp
**/

#ifndef O8_WS_WINDOWS_WINDOW_CLASS_REGISTER_HPP
#define O8_WS_WINDOWS_WINDOW_CLASS_REGISTER_HPP

#include <Utilities\containers\Singleton.hpp>

namespace O8
{
    namespace WS
    {
        class Window_class_register : public Containers::Singleton<Window_class_register>
        {
            /* Singleton needs access to constructor */
            friend class Containers::Singleton<Window_class_register>;

        public:
            ~Window_class_register();

            const char * Get_class_name() const;

        private:
            Window_class_register();

            static LRESULT CALLBACK window_procedure(
                HWND hwnd,
                UINT msg,
                WPARAM wParam,
                LPARAM lParam);

            static const char * s_window_class_name;
        };
    }
}

#endif /* O8_WS_WINDOWS_WINDOW_CLASS_REGISTER_HPP */

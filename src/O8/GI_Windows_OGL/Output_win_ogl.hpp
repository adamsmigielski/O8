/** License
*
* Copyright (c) 2015 Adam Śmigielski
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
* @author Adam Śmigielski
* @file Output_win_ogl.hpp
**/

#ifndef O8_GI_OUTPUT_WIN_OGL_HPP
#define O8_GI_OUTPUT_WIN_OGL_HPP

#include <O8\GI\Output.hpp>

namespace O8
{
    namespace GI
    {
        class Output_win_ogl : public Output
        {
        public:
            Output_win_ogl();
            virtual ~Output_win_ogl();

            void Init(const std::string & name);

            virtual bool Is_connected() const;

            virtual std::string Name() const;

            virtual Platform::int32 Left() const;
            virtual Platform::int32 Right() const;
            virtual Platform::int32 Top() const;
            virtual Platform::int32 Bottom() const;

        private:
            void add_new_mode(DEVMODE & mode);

            std::string m_name;
            bool m_is_connected;
            Platform::int32 m_left;
            Platform::int32 m_right;
            Platform::int32 m_top;
            Platform::int32 m_bottom;
        };
    }
}
#endif /* O8_GI_OUTPUT_WIN_OGL_HPP */

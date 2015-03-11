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
* @file Mode_win_ogl.hpp
**/

#ifndef O8_GI_MODE_WIN_OGL_HPP
#define O8_GI_MODE_WIN_OGL_HPP

#include <O8\GI\Mode.hpp>

namespace O8
{
    namespace GI
    {
        class Mode_win_ogl : public Mode
        {
        public:
            Mode_win_ogl();
            virtual ~Mode_win_ogl();

            void Init(
                uint32 width,
                uint32 height,
                uint32 freq,
                uint32 bpp);

            virtual uint32 Width() const;
            virtual uint32 Height() const;
            virtual uint32 RefreshRate() const;
            virtual uint32 Channels() const;
            virtual uint32 BitsPerChannel() const;

        private:
            uint32 m_width;
            uint32 m_height;
            uint32 m_freq;
            uint32 m_bpp;
        };
    }
}

#endif /* O8_GI_MODE_WIN_OGL_HPP */

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
* @file Mode_win_ogl.cpp
**/

#include "PCH.hpp"

#include "Mode_win_ogl.hpp"

namespace O8
{
    namespace GI
    {
        Mode_win_ogl::Mode_win_ogl()
            : m_width(0)
            , m_height(0)
            , m_freq(0)
            , m_bpp(0)
        {

        }

        Mode_win_ogl::~Mode_win_ogl()
        {

        }

        void Mode_win_ogl::Init(
            Platform::uint32 width,
            Platform::uint32 height,
            Platform::uint32 freq,
            Platform::uint32 bpp)
        {
            m_width  = width;
            m_height = height;
            m_freq   = freq;
            m_bpp    = bpp;
        }

        Platform::uint32 Mode_win_ogl::Width() const
        {
            return m_width;
        }

        Platform::uint32 Mode_win_ogl::Height() const
        {
            return m_height;
        }

        Platform::uint32 Mode_win_ogl::RefreshRate() const
        {
            return m_freq;
        }

        Platform::uint32 Mode_win_ogl::Channels() const
        {
            return -1;
        }

        Platform::uint32 Mode_win_ogl::BitsPerChannel() const
        {
            return m_bpp;
        }
    }
}

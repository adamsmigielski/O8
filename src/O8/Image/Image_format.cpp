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
* @file Image_format.cpp
**/

#include "PCH.hpp"

#include "Image_format.hpp"

namespace O8
{
    namespace Image
    {
        Image_format::Image_format()
            : m_line_preface(0)
            , m_line_conclusion(0)
        {
            /* Nothing to be done here */
        }

        Image_format::Image_format(const Image_format & image_format)
            : m_color_format(image_format.m_color_format)
            , m_line_preface(image_format.m_line_preface)
            , m_line_conclusion(image_format.m_line_conclusion)
        {
            /* Nothing to be done here */
        }

        Image_format::Image_format(
            const Color_format & color_format,
            uint32 line_preface,
            uint32 line_conclusion)
            : m_color_format(color_format)
            , m_line_preface(line_preface)
            , m_line_conclusion(line_conclusion)
        {
            /* Nothing to be done here */
        }

        Color_format & Image_format::Color()
        {
            return m_color_format;
        }

        const Color_format & Image_format::Color() const
        {
            return m_color_format;
        }

        uint32 & Image_format::Line_preface()
        {
            return m_line_preface;
        }

        const uint32 & Image_format::Line_preface() const
        {
            return m_line_preface;
        }

        uint32 & Image_format::Line_conclusion()
        {
            return m_line_conclusion;
        }

        const uint32 & Image_format::Line_conclusion() const
        {
            return m_line_conclusion;
        }
    }
}

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
* @file Image_format.hpp
**/

#ifndef O8_IMAGE_IMAGE_FORMAT_HPP
#define O8_IMAGE_IMAGE_FORMAT_HPP

#ifndef O8_IMAGE_COLOR_FORMAT_HPP
#include "Color_format.hpp"
#endif /* O8_IMAGE_COLOR_FORMAT_HPP */

namespace O8
{
    namespace Image
    {

        class Image_format
        {
        public:
            Image_format();
            Image_format(const Image_format & image_format);
            Image_format(
                const Color_format & color_format,
                uint32 line_preface,
                uint32 line_conclusion);

            Color_format m_Color_format;
            uint32 m_Line_conclusion;
            uint32 m_Line_preface;
        };
    }
}

#endif /* O8_IMAGE_IMAGE_FORMAT_HPP */

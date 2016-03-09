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
* @file Color_format.hpp
**/

#ifndef O8_IMAGE_COLOR_FORMAT_HPP
#define O8_IMAGE_COLOR_FORMAT_HPP

namespace O8
{
    namespace Image
    {
        class Color_format
        {
        public:
            /* Enums */
            enum CHANNEL
            {
                CHANNEL_NONE  = 0,
                CHANNEL_ONE,
                CHANNEL_TWO,
                CHANNEL_THREE,
                CHANNEL_FOUR,
            };

            enum TYPE
            {
                TYPE_NONE = 0x00,
                TYPE_UINT8,
                TYPE_SINT8,
                TYPE_UINT16,
                TYPE_SINT16,
                TYPE_UINT32,
                TYPE_SINT32,
                TYPE_UINT64,
                TYPE_SINT64,
                TYPE_NORM_UINT8,
                TYPE_NORM_SINT8,
                TYPE_NORM_UINT16,
                TYPE_NORM_SINT16,
                TYPE_NORM_UINT32,
                TYPE_NORM_SINT32,
                TYPE_NORM_UINT64,
                TYPE_NORM_SINT64,
                TYPE_HALF,
                TYPE_FLOAT,
                TYPE_DOUBLE,
            };

            /* Routines */
            Color_format();
            Color_format(const Color_format & color_format);
            Color_format(
                CHANNEL number_of_channels,
                TYPE data_type);

            CHANNEL m_Channel;
            TYPE m_Type;

            void Extract(
                const void * src,
                double out_values[4]) const;
            void Store(
                void * dst,
                const double in_values[4]) const;

            Platform::uint32 Get_bits_per_pixel() const;
            Platform::uint32 Get_bytes_per_pixel() const;
            bool Is_normalized() const;

            /* Static routines */
            static void Convert(
                const void * src,
                const Color_format & src_format,
                void * dst,
                const Color_format & dst_format);
            static Platform::uint32 Get_number_of_channels(CHANNEL channel);
            static Platform::uint32 Get_type_bits(TYPE type);
            static Platform::uint32 Get_type_bytes(TYPE type);
            static bool Is_type_normalized(TYPE type);

            /* Constants */
            static const Color_format s_Light_format;
        };
    }
}

#endif /* O8_IMAGE_COLOR_FORMAT_HPP */

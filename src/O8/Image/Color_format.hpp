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
* @file ColorFormat.hpp
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

            const CHANNEL & Channel() const;
            CHANNEL & Channel();
            const TYPE & Type() const;
            TYPE & Type();

            uint32 Get_bits_per_pixel() const;
            uint32 Get_bytes_per_pixel() const;

            /* Static routines */
            static uint32 Get_number_of_channels(CHANNEL channel);
            static uint32 Get_type_bits(TYPE type);
            static uint32 Get_type_bytes(TYPE type);

        private:
            CHANNEL m_channel;
            TYPE m_type;
        };
    }
}

#endif O8_IMAGE_COLOR_FORMAT_HPP

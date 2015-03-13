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
* @file ColorFormat.cpp
**/

#include "PCH.hpp"

#include "Color_format.hpp"

namespace O8
{
    namespace Image
    {
        Color_format::Color_format()
            : m_channel(CHANNEL_NONE)
            , m_type(TYPE_NONE)
        {
            /* Nothing to be done here */
        }

        Color_format::Color_format(const Color_format & color_format)
            : m_channel(color_format.m_channel)
            , m_type(color_format.m_type)
        {
            /* Nothing to be done here */
        }

        Color_format::Color_format(
            CHANNEL channel,
            TYPE type)
            : m_channel(channel)
            , m_type(type)
        {
            /* Nothing to be done here */
        }

        Color_format::CHANNEL & Color_format::Channel()
        {
            return m_channel;
        }

        const Color_format::CHANNEL & Color_format::Channel() const
        {
            return m_channel;
        }

        Color_format::TYPE & Color_format::Type()
        {
            return m_type;
        }

        const Color_format::TYPE & Color_format::Type() const
        {
            return m_type;
        }

        uint32 Color_format::Get_bits_per_pixel() const
        {
            return Get_number_of_channels(m_channel) * Get_type_bits(m_type);
        }

        uint32 Color_format::Get_bytes_per_pixel() const
        {
            return Get_number_of_channels(m_channel) * Get_type_bytes(m_type);
        }

        uint32 Color_format::Get_number_of_channels(CHANNEL channel)
        {
            uint32 result = 0;

            switch (channel)
            {
            case CHANNEL_NONE: break;
            case CHANNEL_ONE:   result = 1; break;
            case CHANNEL_TWO:   result = 2; break;
            case CHANNEL_THREE: result = 3; break;
            case CHANNEL_FOUR:  result = 4; break;
            default:
                ASSERT(0);
                DEBUGLOG("Invalid enum");
                break;
            }

            return result;
        }

        uint32 Color_format::Get_type_bits(TYPE type)
        {
            uint32 result = 0;

            switch (type)
            {
            case TYPE_NONE: break;
            case TYPE_UINT8:
            case TYPE_SINT8:  result = 8; break;
            case TYPE_HALF:
            case TYPE_UINT16:
            case TYPE_SINT16: result = 16; break;
            case TYPE_FLOAT:
            case TYPE_UINT32:
            case TYPE_SINT32: result = 32; break;
            case TYPE_DOUBLE:
            case TYPE_UINT64:
            case TYPE_SINT64: result = 64; break;
            default:
                ASSERT(0);
                DEBUGLOG("Invalid enum");
                break;
            }

            return result;
        }

        uint32 Color_format::Get_type_bytes(TYPE type)
        {
            uint32 result = 0;

            switch (type)
            {
            case TYPE_NONE: break;
            case TYPE_UINT8:
            case TYPE_SINT8:  result = 1; break;
            case TYPE_HALF:
            case TYPE_UINT16:
            case TYPE_SINT16: result = 2; break;
            case TYPE_FLOAT:
            case TYPE_UINT32:
            case TYPE_SINT32: result = 4; break;
            case TYPE_DOUBLE:
            case TYPE_UINT64:
            case TYPE_SINT64: result = 8; break;
            default:
                ASSERT(0);
                DEBUGLOG("Invalid enum");
                break;
            }

            return result;
        }
    }
}

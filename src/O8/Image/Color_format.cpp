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
* @file Color_format.cpp
**/

#include "PCH.hpp"

#include "Color_format.hpp"

#include <limits>

namespace O8
{
    namespace Image
    {
        Color_format::Color_format()
            : m_Channel(CHANNEL_NONE)
            , m_Type(TYPE_NONE)
        {
            /* Nothing to be done here */
        }

        Color_format::Color_format(const Color_format & color_format)
            : m_Channel(color_format.m_Channel)
            , m_Type(color_format.m_Type)
        {
            /* Nothing to be done here */
        }

        Color_format::Color_format(
            CHANNEL channel,
            TYPE type)
            : m_Channel(channel)
            , m_Type(type)
        {
            /* Nothing to be done here */
        }

        template <typename T>
        void extract_values(const void * src,
            Platform::uint32 n_channels,
            double out_values[4])
        {
            const T * ptr = (const T *) src;

            for (Platform::uint32 i = 0;
                i < n_channels;
                ++i)
            {
                out_values[i] = double(ptr[i]);
            }
        }

        template <typename T>
        void normalize_values(const void * src,
            Platform::uint32 n_channels,
            double out_values[4])
        {
            const T * ptr = (const T *)src;

            std::numeric_limits<T> limits;
            double max = double( limits.max() );

            for (Platform::uint32 i = 0;
                i < n_channels;
                ++i)
            {
                const double value = double(ptr[i]);
                const double normalized = value / max;

                out_values[i] = normalized;
            }
        }

        void Color_format::Extract(
            const void * src,
            double out_values[4]) const
        {
            const Platform::uint32 n_ch = Get_number_of_channels(m_Channel);

            switch (m_Type)
            {
            case TYPE_UINT8:       extract_values<Platform::uint8>   (src, n_ch, out_values); break;
            case TYPE_SINT8:       extract_values<Platform::int8>    (src, n_ch, out_values); break;
            case TYPE_UINT16:      extract_values<Platform::uint16>  (src, n_ch, out_values); break;
            case TYPE_SINT16:      extract_values<Platform::int16>   (src, n_ch, out_values); break;
            case TYPE_UINT32:      extract_values<Platform::uint32>  (src, n_ch, out_values); break;
            case TYPE_SINT32:      extract_values<Platform::int32>   (src, n_ch, out_values); break;
            case TYPE_UINT64:      extract_values<Platform::uint64>  (src, n_ch, out_values); break;
            case TYPE_SINT64:      extract_values<Platform::int64>   (src, n_ch, out_values); break;

            case TYPE_NORM_UINT8:  normalize_values<Platform::uint8> (src, n_ch, out_values); break;
            case TYPE_NORM_SINT8:  normalize_values<Platform::int8>  (src, n_ch, out_values); break;
            case TYPE_NORM_UINT16: normalize_values<Platform::uint16>(src, n_ch, out_values); break;
            case TYPE_NORM_SINT16: normalize_values<Platform::int16> (src, n_ch, out_values); break;
            case TYPE_NORM_UINT32: normalize_values<Platform::uint32>(src, n_ch, out_values); break;
            case TYPE_NORM_SINT32: normalize_values<Platform::int32> (src, n_ch, out_values); break;
            case TYPE_NORM_UINT64: normalize_values<Platform::uint64>(src, n_ch, out_values); break;
            case TYPE_NORM_SINT64: normalize_values<Platform::int64> (src, n_ch, out_values); break;

            case TYPE_HALF:
            case TYPE_FLOAT:       extract_values<float> (src, n_ch, out_values); break;
            case TYPE_DOUBLE:      extract_values<double>(src, n_ch, out_values); break;

            case TYPE_NONE:
            default:
                break;
            }
        }

        Platform::uint32 Color_format::Get_bits_per_pixel() const
        {
            return Get_number_of_channels(m_Channel) * Get_type_bits(m_Type);
        }

        Platform::uint32 Color_format::Get_bytes_per_pixel() const
        {
            return Get_number_of_channels(m_Channel) * Get_type_bytes(m_Type);
        }

        Platform::uint32 Color_format::Get_number_of_channels(CHANNEL channel)
        {
            Platform::uint32 result = 0;

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

        Platform::uint32 Color_format::Get_type_bits(TYPE type)
        {
            Platform::uint32 result = 0;

            switch (type)
            {
            case TYPE_NONE: break;
            case TYPE_UINT8:
            case TYPE_SINT8:
            case TYPE_NORM_UINT8:
            case TYPE_NORM_SINT8:  result = 8; break;
            case TYPE_HALF:
            case TYPE_UINT16:
            case TYPE_SINT16:
            case TYPE_NORM_UINT16:
            case TYPE_NORM_SINT16: result = 16; break;
            case TYPE_FLOAT:
            case TYPE_UINT32:
            case TYPE_SINT32:
            case TYPE_NORM_UINT32:
            case TYPE_NORM_SINT32: result = 32; break;
            case TYPE_DOUBLE:
            case TYPE_UINT64:
            case TYPE_SINT64:
            case TYPE_NORM_UINT64:
            case TYPE_NORM_SINT64: result = 64; break;
            default:
                ASSERT(0);
                DEBUGLOG("Invalid enum");
                break;
            }

            return result;
        }

        Platform::uint32 Color_format::Get_type_bytes(TYPE type)
        {
            Platform::uint32 result = 0;

            switch (type)
            {
            case TYPE_NONE: break;
            case TYPE_UINT8:
            case TYPE_SINT8:
            case TYPE_NORM_UINT8:
            case TYPE_NORM_SINT8:  result = 1; break;
            case TYPE_HALF:
            case TYPE_UINT16:
            case TYPE_SINT16:
            case TYPE_NORM_UINT16:
            case TYPE_NORM_SINT16: result = 2; break;
            case TYPE_FLOAT:
            case TYPE_UINT32:
            case TYPE_SINT32:
            case TYPE_NORM_UINT32:
            case TYPE_NORM_SINT32: result = 4; break;
            case TYPE_DOUBLE:
            case TYPE_UINT64:
            case TYPE_SINT64:
            case TYPE_NORM_UINT64:
            case TYPE_NORM_SINT64: result = 8; break;
            default:
                ASSERT(0);
                DEBUGLOG("Invalid enum");
                break;
            }

            return result;
        }

        bool Color_format::Is_type_normalized(TYPE type)
        {
            bool result = false;

            switch (type)
            {
            case TYPE_NORM_UINT8:
            case TYPE_NORM_SINT8:
            case TYPE_NORM_UINT16:
            case TYPE_NORM_SINT16:
            case TYPE_NORM_UINT32:
            case TYPE_NORM_SINT32:
            case TYPE_NORM_UINT64:
            case TYPE_NORM_SINT64:
                result = true;
                break;

            case TYPE_NONE:
            case TYPE_UINT8:
            case TYPE_SINT8:
            case TYPE_UINT16:
            case TYPE_SINT16:
            case TYPE_UINT32:
            case TYPE_SINT32:
            case TYPE_UINT64:
            case TYPE_SINT64:
            case TYPE_HALF:
            case TYPE_FLOAT:
            case TYPE_DOUBLE:
            default:
                break;
            }

            return result;
        }
    }
}

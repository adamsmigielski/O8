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
* @file Output_win_ogl.cpp
**/

#include "PCH.hpp"

#include "Output_win_ogl.hpp"
#include "Mode_win_ogl.hpp"

namespace O8
{
    namespace GI
    {
        Output_win_ogl::Output_win_ogl()
            : m_is_connected(true)
            , m_left  (0)
            , m_right (0)
            , m_top   (0)
            , m_bottom(0)
        {

        }

        Output_win_ogl::~Output_win_ogl()
        {

        }

        void Output_win_ogl::Init(
            const std::string & name)
        {
            m_name = name;

            DEVMODE mode;
            memset(&mode, 0, sizeof(DEVMODE));
            mode.dmSize = sizeof(DEVMODE);
            mode.dmDriverExtra = 0;

            if (FALSE == EnumDisplaySettingsEx(
                name.c_str(),
                ENUM_CURRENT_SETTINGS,
                &mode,
                0 /* flags */))
            {
                m_is_connected = false;

                DEBUGLOG("Failed to get output settings, not connected.")
            }
            else
            {
                DWORD index = 0;

                if (mode.dmFields & DM_POSITION)
                {
                    m_left = mode.dmPosition.x;
                    m_top = mode.dmPosition.y;
                }

                if (mode.dmFields & DM_PELSWIDTH)
                {
                    m_right = m_left + mode.dmPelsWidth;
                }

                if (mode.dmFields & DM_PELSHEIGHT)
                {
                    m_bottom = m_top + mode.dmPelsHeight;
                }

                DEBUGLOG("Output: "
                    << m_name
                    << " at "
                    << m_left
                    << ","
                    << m_top
                    << " x "
                    << m_right
                    << ","
                    << m_bottom);

                while (FALSE != EnumDisplaySettingsEx(
                    name.c_str(),
                    index,
                    &mode,
                    0 /* flags */))
                {
                    add_new_mode(mode);

                    ++index;
                }
            }
        }

        bool Output_win_ogl::Is_connected() const
        {
            return m_is_connected;
        }

        std::string Output_win_ogl::Name() const
        {
            return m_name;
        }

        int32 Output_win_ogl::Left() const
        {
            return m_left;
        }

        int32 Output_win_ogl::Right() const
        {
            return m_right;
        }

        int32 Output_win_ogl::Top() const
        {
            return m_top;
        }

        int32 Output_win_ogl::Bottom() const
        {
            return m_bottom;
        }

        void Output_win_ogl::add_new_mode(DEVMODE & mode)
        {
            uint32 width = 0;
            uint32 height = 0;
            uint32 freq = 0;
            uint32 bpp = 0;

            if (mode.dmFields & DM_PELSWIDTH)
            {
                width = mode.dmPelsWidth;
            }

            if (mode.dmFields & DM_PELSHEIGHT)
            {
                height = mode.dmPelsHeight;
            }

            if (mode.dmFields & DM_DISPLAYFREQUENCY)
            {
                freq = mode.dmDisplayFrequency;
            }

            if (mode.dmFields & DM_BITSPERPEL)
            {
                bpp = mode.dmBitsPerPel;
            }

            DEBUGLOG(
                "Mode: "
                << m_name
                << " "
                << width
                << "x"
                << height
                << "x"
                << bpp
                << "@"
                << freq);

            auto ptr = new Mode_win_ogl;

            Attach(ptr);

            ptr->Init(
                width,
                height,
                freq,
                bpp);
        }
    }
}

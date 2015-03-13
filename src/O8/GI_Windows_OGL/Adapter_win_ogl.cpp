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
* @file Adapter_win_ogl.cpp
**/

#include "PCH.hpp"

#include "Adapter_win_ogl.hpp"
#include "Output_win_ogl.hpp"

namespace O8
{
    namespace GI
    {
        Adapter_win_ogl::Adapter_win_ogl()
        {

        }

        Adapter_win_ogl::~Adapter_win_ogl()
        {

        }

        void Adapter_win_ogl::Add_output(
            const std::string & name)
        {
            auto output = new Output_win_ogl;

            if (nullptr == output)
            {
                ASSERT(0);
                ERRLOG("new Output_win_ogl - failed");
                return;
            }
            Attach(output);

            output->Init(name);
        }

        void Adapter_win_ogl::Init(
            const std::string & name,
            const std::string & key,
            uint32 vendor_id,
            uint32 device_id)
        {
            m_name = name;
            m_key = key;
            m_vendor_id = vendor_id;
            m_device_id = device_id;
        }

        std::string Adapter_win_ogl::Key() const
        {
            return m_key;
        }

        std::string Adapter_win_ogl::Name() const
        {
            return m_name;
        }

        uint32 Adapter_win_ogl::Vendor_id() const
        {
            return m_vendor_id;
        }

        uint32 Adapter_win_ogl::Device_id() const
        {
            return m_device_id;
        }

        uint32 Adapter_win_ogl::Video_memory() const
        {
            return -1;
        }

        uint32 Adapter_win_ogl::System_memory() const
        {
            return -1;
        }

        uint32 Adapter_win_ogl::Shared_memory() const
        {
            return -1;
        }
    }
}

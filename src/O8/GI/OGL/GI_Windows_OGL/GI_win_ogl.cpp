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
* @file GI_win_ogl.cpp
**/

#include "PCH.hpp"

#include "GI_win_ogl.hpp"

#include "Adapter_win_ogl.hpp"
#include "Output_win_ogl.hpp"
#include "RI_win_ogl.hpp"

namespace O8
{
    namespace GI
    {
        GI_win_ogl::GI_win_ogl()
        {

        }

        GI_win_ogl::~GI_win_ogl()
        {

        }

        Platform::int32 GI_win_ogl::Init()
        {
            return process_adapters();
        }

        void GI_win_ogl::Release()
        {
            Clear();
        }

        RI * GI_win_ogl::Create_rendering_interface(
            Adapter * adapter)
        {
            Output_win_ogl * output = nullptr;
            RI_win_ogl * ri = nullptr;

            if (nullptr == adapter)
            {
                ERRLOG("Invalid adapter");
                ASSERT(0);
                return nullptr;
            }


            for (auto i = adapter->First(); nullptr != i; i = i->Next())
            {
                if (true == i->Is_connected())
                {
                    output = (Output_win_ogl *) i;
                    break;
                }

                output = nullptr;
            }

            if (nullptr == output)
            {
                ASSERT(0);
                ERRLOG("Adapter: " << adapter->Name()
                    << " has no connected output");
                return nullptr;
            }

            ri = create_rendering_interface(output);

            if (nullptr == ri)
            {
                ERRLOG("Failed to create rendering interface");
                return nullptr;
            }

            return ri;
        }

        void GI_win_ogl::add_new_adapter(
            const std::string & name,
            const std::string & key,
            const std::string & string,
            Platform::uint32 vendor_id,
            Platform::uint32 device_id)
        {
            auto adapter = new Adapter_win_ogl;

            if (nullptr == adapter)
            {
                ASSERT(0);
                ERRLOG("new Adapter_win_ogl - failed");
                return;
            }

            DEBUGLOG("Adapter: "
                << string
                << " "
                << vendor_id
                << " "
                << device_id);

            Attach(adapter);

            adapter->Init(
                string,
                key,
                vendor_id,
                device_id);

            add_output_to_adapter(
                name,
                adapter);
        }

        void GI_win_ogl::add_output_to_adapter(
            const std::string & name,
            Adapter_win_ogl * adapter)
        {
            DEBUGLOG("Output "
                << name
                << " adapter "
                << adapter->Name());

            adapter->Add_output(name);
        }

        Platform::int32 GI_win_ogl::compare_device_key(
            const char * dev_a,
            const char * dev_b)
        {
            const char * dev_a_beg = strchr(dev_a,     '{');
            const char * dev_b_beg = strchr(dev_b,     '{');
            const char * dev_a_end = strchr(dev_a_beg, '}');
            const char * dev_b_end = strchr(dev_b_beg, '}');

            //Same length ?
            if ((dev_b_end - dev_b_beg) != (dev_a_end - dev_a_beg))
            {
                return -1;
            }

            return strncmp(dev_a_beg, dev_b_beg, dev_a_end - dev_a_beg);
        }

        RI_win_ogl * GI_win_ogl::create_rendering_interface(
            Output_win_ogl * output)
        {
            auto ri = new RI_win_ogl;

            auto ret = ri->Init(output);
            if (Utilities::Success != ret)
            {
                delete ri;
                return nullptr;
            }

            return ri;
        }

        Platform::uint32 GI_win_ogl::get_device_id(
            const char * device_id)
        {
            auto id = strstr(device_id, "DEV_");

            if (nullptr == id)
            {
                return -1;
            }

            id += 4;
            auto end = strchr(id, '&');
            auto length = end - id;

            char buffer[16];
            memcpy(buffer, id, length);

            buffer[length] = '\0';

            return atoi(buffer);
        }

        Platform::uint32 GI_win_ogl::get_vendor_id(
            const char * device_id)
        {
            auto id = strstr(device_id, "VEN_");

            if (nullptr == id)
            {
                return -1;
            }

            id += 4;
            auto end = strchr(id, '&');
            auto length = end - id;

            char buffer[16];
            memcpy(buffer, id, length);

            buffer[length] = '\0';

            return atoi(buffer);
        }

        Platform::int32 GI_win_ogl::process_adapters()
        {
            static const DWORD flags = 0;

            Platform::uint32 device_index = 0;
            DISPLAY_DEVICE display_device;

            display_device.cb = sizeof(DISPLAY_DEVICE);

            /* For each device */
            while (1)
            {
                if (FALSE == EnumDisplayDevices(
                    nullptr /* device_name*/,
                    device_index,
                    &display_device,
                    flags))
                {
                    break;
                }

                /* Same adapter might be enumerated multiple times */
                Adapter_win_ogl * adapter = nullptr;

                for (auto it = First();
                    nullptr != it;
                    it = it->Next())
                {
                    auto temp = (Adapter_win_ogl *) it;

                    Platform::int32 is_same = compare_device_key(
                        temp->Key().c_str(),
                        display_device.DeviceKey);

                    if (0 == is_same)
                    {
                        adapter = temp;
                    }
                }

                if (nullptr == adapter)
                {
                    add_new_adapter(
                        display_device.DeviceName,
                        display_device.DeviceKey,
                        display_device.DeviceString,
                        get_vendor_id(display_device.DeviceID),
                        get_device_id(display_device.DeviceID));
                }
                else
                {
                    add_output_to_adapter(
                        display_device.DeviceName,
                        adapter);
                }

                device_index += 1;
            }

            return Utilities::Success;
        }
    }
}

O8::GI::GI * Create_GI()
{
    return new O8::GI::GI_win_ogl;
}

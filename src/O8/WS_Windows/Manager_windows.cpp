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
* @file Manager.hpp
**/

#include "PCH.hpp"

#include "Manager_windows.hpp"
#include "Window_windows.hpp"

#include <O8\Thread\Loader.hpp>

namespace O8
{
    namespace WS
    {
        Manager_windows::Manager_windows()
			: m_loop_state(loop_state::Halt)
        {
        }

        Manager_windows::~Manager_windows()
        {
			Stop_event_processing();

            m_loop_state = loop_state::Unknown;

			destroy_windows();
		}

        Platform::int32 Manager_windows::Start_event_processing()
        {
            if (loop_state::Halt != m_loop_state)
            {
                ASSERT(0);

                ERRLOG("Event processing already started");
				return Utilities::Invalid_object;
            }

            loop();

            return Utilities::Success;
        }

		Platform::int32 Manager_windows::Stop_event_processing()
        {
            if (loop_state::Run == m_loop_state)
            {
                m_loop_state = loop_state::Stoping;
                return Utilities::Success;
            }
            else
            {
                ERRLOG("Event processing not started");
				return Utilities::Invalid_object;
            }
        }

		Platform::int32 Manager_windows::Process_events()
        {
            for (auto it = First();
                nullptr != it;
                it = it->Next())
            {
                it->Process_messages();
            }

            return Utilities::Success;
        }


        /* Window management */
        Window * Manager_windows::Create_window()
        {
            auto wnd = new Window_windows();

            if (nullptr == wnd)
            {
                ASSERT(0);
                ERRLOG("Failed to allocate memory");
                return nullptr;
            }

            Attach(wnd);

            return wnd;
        }

        void Manager_windows::destroy_windows()
        {
            Clear();
        }

        void Manager_windows::loop()
        {
            m_loop_state = loop_state::Starting;

            LOG("Window's Manager's loop start");

            m_loop_state = loop_state::Run;

            while (loop_state::Run == m_loop_state)
            {
                //Update windows
                if (Utilities::Success != Process_events())
                {
                    break;
                }

                Thread::Give_up();
            }

            LOG("Window's Manager's loop stop");

            m_loop_state = loop_state::Halt;
        }
    }
}

/* DL entry points */
O8::WS::Manager * UTILITIES_API Create_manager()
{
    return new O8::WS::Manager_windows;
}

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
* @file Factory_windows.cpp
**/

#include "PCH.hpp"

#include "Factory_windows.hpp"

#include "Alarm_windows.hpp"
#include "Blocker_windows.hpp"
#include "Event_windows.hpp"
#include "Thread_windows.hpp"

namespace O8
{
    namespace Thread
    {
        Factory_windows::Factory_windows()
        {
            /* Nothing to be done here */
        }

        Factory_windows::~Factory_windows()
        {
            /* Nothing to be done here */
        }

        Alarm * Factory_windows::Create_alarm()
        {
            return new Alarm_windows;
        }

        Blocker * Factory_windows::Create_blocker()
        {
            return nullptr;
        }

        Event * Factory_windows::Create_event()
        {
            return new Event_windows;
        }

        Thread * Factory_windows::Create_thread()
        {
            return new Thread_windows;
        }

        void Factory_windows::Give_up_cpu()
        {
            SwitchToThread();
        }

        Synchronizer::WaitResult Factory_windows::Wait_for_multiple(
            Synchronizer ** synchronizers,
            Platform::uint32 number)
        {
            ASSERT(0);

            return O8::Thread::Synchronizer::WaitResult::Failure;
        }
    }
}

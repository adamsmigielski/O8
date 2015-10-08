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
* @file Event.cpp
**/

#include "PCH.hpp"

#include "Event_windows.hpp"

namespace O8
{
	namespace Thread
	{
        Event_windows::Event_windows()
		{
		}

        Event_windows::~Event_windows()
		{
		}

        int Event_windows::Init()
		{
			auto handle = CreateEvent(0, TRUE, FALSE, nullptr);
			if (0 == handle)
			{
				ASSERT(0);
				Release();
				DWORD err = GetLastError();
				ERRLOG("CreateEvent - err: " << err);
				return Utilities::Failure;
			}

            auto ret = Init_handle(handle);
            if (Utilities::Success != ret)
            {
                CloseHandle(handle);
            }

			return ret;
		}

        void Event_windows::Release()
		{	
            Release_handle();
		}

        void Event_windows::Signal()
		{
            auto handle = Get_handle();

			if (INVALID_HANDLE_VALUE == handle)
			{
				return;
			}

			SetEvent(handle);
		}

        void Event_windows::Reset()
        {
            auto handle = Get_handle();

            if (INVALID_HANDLE_VALUE == handle)
            {
                return;
            }

			ResetEvent(handle);
		}

		Synchronizer::WaitResult Event_windows::Wait(Platform::uint32 timeout_ms) const
        {
            return Wait_for_single(timeout_ms);
        }
	}
}

O8::Thread::Event * Create_event()
{
    return new O8::Thread::Event_windows;
}


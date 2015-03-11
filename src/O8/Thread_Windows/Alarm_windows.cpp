/** License
*
* Copyright (c) 2014 Adam Œmigielski
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
* @file Alarm.cpp
**/

#include "PCH.hpp"

#include "Alarm_windows.hpp"
#include "Synchronizer_windows.hpp"

namespace O8
{
	namespace Thread
	{
        Alarm_windows::Alarm_windows()
		{
		}

        Alarm_windows::~Alarm_windows()
		{
		}

        int32 Alarm_windows::Init()
		{
			auto handle = CreateWaitableTimer(0, TRUE, nullptr);
            if (INVALID_HANDLE_VALUE == handle)
			{
				ASSERT(0);
				Release();
				DWORD err = GetLastError();
				ERRLOG("CreateWaitableTimer - err:" << err);
				return Failure;
			}

            auto ret = Init_handle(handle);
            if (Success != ret)
            {
                CloseHandle(handle);
            }

            return ret;
		}

        void Alarm_windows::Release()
		{	
            Release_handle();
		}

        int32 Alarm_windows::Start(float time_s)
		{
            auto handle = Get_handle();

            if (INVALID_HANDLE_VALUE == handle)
			{
				ASSERT(0);
                return Invalid_object;
			}

			long long time = time_s * -10000000.0f;

            BOOL ret = SetWaitableTimer(handle,
				(LARGE_INTEGER *)&time,
				0,
				nullptr,
				nullptr,
				FALSE);

			if (0 == ret)
			{
				DWORD err = GetLastError();
				ERRLOG("SetWaitableTimer - err: " << err);
				return Failure;
			}

			return Success;
		}

        Synchronizer::WaitResult Alarm_windows::Wait(uint32 timeout_ms) const
        {
            return Wait_for_single(timeout_ms);
        }
	}
}

O8::Thread::Alarm * Create_alarm()
{
    return new O8::Thread::Alarm_windows;
}


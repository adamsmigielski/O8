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
* @file Thread.cpp
**/

#include "PCH.hpp"

#include "Thread_windows.hpp"

namespace O8
{
	namespace Thread
	{	
        Thread_windows::Thread_windows()
		{
		}

        Thread_windows::~Thread_windows()
		{
		}

        static unsigned long __stdcall thread_routine(void * arg)
        {
            Runnable * runnable = (Runnable *) arg;

            runnable->Run();

            return 0;
        }

        int32 Thread_windows::Start(Runnable * runnable)
		{
			HANDLE thread = CreateThread(
                nullptr /* attributes */,
                0 /* stack size */,
                thread_routine,
                runnable,
                0 /* creation flags */,
                0 /* thread id */);
			if (NULL == thread)
			{
				ASSERT(0);
				ERRLOG("CreateThread");
				return Failure;
			}

			auto ret = Init_handle(thread);
            if (Success != ret)
            {
                CloseHandle(thread);
            }

            return ret;
		}

        Synchronizer::WaitResult Thread_windows::Wait(uint32 timeout_ms) const
        {
            return Wait_for_single(timeout_ms);
        }
	}
}

O8::Thread::Thread * Create_thread()
{
    return new O8::Thread::Thread_windows;
}

void Give_up()
{
    SwitchToThread();
}


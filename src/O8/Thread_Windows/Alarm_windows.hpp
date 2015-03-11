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
* @file Alarm.hpp
**/

#ifndef O8_THREAD_WINDOWS_ALARM_WINDOWS_HPP
#define O8_THREAD_WINDOWS_ALARM_WINDOWS_HPP

#include <O8\Thread\Alarm.hpp>      /* Alarm */
#include "Synchronizer_windows.hpp" /* Synchronizer_windows */
#include <Windows.h>                /* HANDLE */

namespace O8
{
	namespace Thread
	{
		class Alarm_windows : public Alarm,
                              public Synchronizer_windows
		{
		public:
            Alarm_windows();
            virtual ~Alarm_windows();

            /* Alarm */
			virtual int32 Init();
			virtual void Release();

			virtual int32 Start(float time_s);

            /* Synchronizer */
            virtual WaitResult Wait(uint32 timeout_ms) const;
		};
	}
}

O8_API_DECORATION DLL_EXPORT O8::Thread::Alarm * O8_API Create_alarm();

#endif /* O8_THREAD_WINDOWS_ALARM_WINDOWS_HPP */

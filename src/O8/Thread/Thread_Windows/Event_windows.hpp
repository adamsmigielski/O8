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
* @file Event.hpp
**/

#ifndef O8_THREAD_EVENT_WINDOWS_HPP
#define O8_THREAD_EVENT_WINDOWS_HPP

#include <O8\Thread\Event.hpp>      /* Alarm */
#include "Synchronizer_windows.hpp" /* Synchronizer_windows */
#include <Windows.h>                /* HANDLE */

namespace O8
{
	namespace Thread
	{
        class Event_windows : public Event
                            , public Synchronizer_windows
		{
		public:
            Event_windows();
            virtual ~Event_windows();

            /* Event */
			virtual int Init();
			virtual void Release();

			virtual void Signal();
			virtual void Reset();

            /* Synchronizer */
			virtual WaitResult Wait(Platform::uint32 timeout_ms) const;
		};
	}
}

#endif /* O8_THREAD_EVENT_WINDOWS_HPP */

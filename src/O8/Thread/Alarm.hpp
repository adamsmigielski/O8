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
* @file Alarm.hpp
**/

#ifndef O8_THREAD_ALARM_HPP
#define O8_THREAD_ALARM_HPP

#include "Synchronizer.hpp"

namespace O8
{
	namespace Thread
	{
        /** Alarm is signalized after specified time.
        *
        **/
		class Alarm : public Synchronizer
		{
		public:
			Alarm();
			virtual ~Alarm();

			virtual Platform::int32 Init() = 0;
			virtual void Release() = 0;

			virtual Platform::int32 Start(float time_s) = 0;
		};
	}
}

#endif /* O8_THREAD_ALARM_HPP */

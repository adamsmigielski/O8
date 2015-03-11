/** License
*
* Copyright (c) 2014 Adam Śmigielski
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
* @author Adam Śmigielski
* @file Blocker.hpp
**/

#ifndef O8_THREAD_WINDOWS_BLOCKER_WINDOWS_HPP
#define O8_THREAD_WINDOWS_BLOCKER_WINDOWS_HPP

#include <O8\Thread\Blocker.hpp> /* Alarm */
#include <Windows.h>             /* HANDLE */

namespace O8
{
	namespace Thread
	{
		/*class Blocker_windows : public Blocker
		{
		public:
			virtual void Unlock() = 0;
		};*/
	}
}

#endif /* O8_THREAD_WINDOWS_BLOCKER_WINDOWS_HPP */

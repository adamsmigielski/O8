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
* @file Synchronizer.hpp
**/

#ifndef O8_THREAD_SYNCHRONIZER_WINDOWS_HPP
#define O8_THREAD_SYNCHRONIZER_WINDOWS_HPP

#include <O8\Thread\Synchronizer.hpp>
#include <Windows.h>

namespace O8
{
	namespace Thread
	{
        class Synchronizer_windows : virtual public Synchronizer
        {
        public:
            Synchronizer_windows();
            virtual ~Synchronizer_windows();

            Platform::int32 Init_handle(HANDLE handle);
            void Release_handle();

            HANDLE Get_handle();
			WaitResult Wait_for_single(Platform::uint32 timeout_ms) const;

        private:
            HANDLE m_handle;
        };
	}
}

#endif /* O8_THREAD_SYNCHRONIZER_WINDOWS_HPP */

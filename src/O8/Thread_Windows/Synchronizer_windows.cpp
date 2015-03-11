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
* @file Synchronizer.cpp
**/

#include "PCH.hpp"

#include "Synchronizer_windows.hpp"

#include <O8\Common\ErrorCodes.hpp>

namespace O8
{
	namespace Thread
	{
        Synchronizer_windows::Synchronizer_windows()
            : m_handle(INVALID_HANDLE_VALUE)
        {

        }

        Synchronizer_windows::~Synchronizer_windows()
        {
            Release_handle();
        }

        int32 Synchronizer_windows::Init_handle(HANDLE handle)
        {
            if (INVALID_HANDLE_VALUE != m_handle)
            {
                ASSERT(0);
                return Invalid_object;
            }
            else
            {
                m_handle = handle;
                return Success;
            }
        }

        void Synchronizer_windows::Release_handle()
        {
            if (INVALID_HANDLE_VALUE != m_handle)
            {
                CloseHandle(m_handle);
                m_handle = INVALID_HANDLE_VALUE;
            }
        }

        HANDLE Synchronizer_windows::Get_handle()
        {
            return m_handle;
        }

        Synchronizer::WaitResult Synchronizer_windows::Wait_for_single(uint32 timeout_ms) const
        {
            if (INVALID_HANDLE_VALUE != m_handle)
            {
                ASSERT(0);
                return WaitResult::Failure;
            }

            auto ret = WaitForSingleObject(m_handle, (DWORD) timeout_ms);
            WaitResult result;

            switch (ret)
            {
            case WAIT_ABANDONED: result = WaitResult::Abandon;   break;
            case WAIT_OBJECT_0:  result = WaitResult::Ownership; break;
            case WAIT_TIMEOUT:   result = WaitResult::Timeout;   break;
            case WAIT_FAILED:    result = WaitResult::Failure;   break;
            default:             result = WaitResult::Failure;   break;
            }

            return result;
        }
	}
}

O8::Thread::Synchronizer::WaitResult Wait_for_multiple(O8::Thread::Synchronizer ** synchronizers, O8::uint32 number)
{
    ASSERT(0);

    return O8::Thread::Synchronizer::WaitResult::Failure;
}


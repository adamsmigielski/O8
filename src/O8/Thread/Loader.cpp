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
* @file Loader.cpp
**/

#include "PCH.hpp"

#include "Loader.hpp"

#include <O8\Common\ErrorCodes.hpp>
#include <O8\DL\DL.hpp>

namespace O8
{
    namespace Thread
    {
        /* Library in use */
        static DL::DL * g_thread_library = nullptr;


        /* DL entry points */
        PFN_CREATE_ALARM      Create_alarm;
      /*PFN_CREATE_BLOCKER    Create_blocker;*/
        PFN_CREATE_EVENT      Create_event;
        PFN_CREATE_THREAD     Create_thread;
        PFN_GIVE_UP           Give_up;
        PFN_WAIT_FOR_MULTIPLE Wait_for_multiple;

        /* Static routines */
        int LoadDL(const char * library_path)
        {
            /* Load library */
            auto dl = DL::Load(library_path);

            if (nullptr == dl)
            {
                return Failed_to_load_library;
            }

            /* Load functions */
            Create_alarm = (PFN_CREATE_ALARM)dl->GetFunctionAddress("Create_alarm");
            /* Create_blocker = (PFN_CREATE_BLOCKER)dl->GetFunctionAddress("Create_blocker"); */
            Create_event = (PFN_CREATE_EVENT)dl->GetFunctionAddress("Create_event");
            Create_thread = (PFN_CREATE_THREAD)dl->GetFunctionAddress("Create_thread");
            Give_up = (PFN_GIVE_UP) dl->GetFunctionAddress("Give_up");
            Wait_for_multiple = (PFN_WAIT_FOR_MULTIPLE) dl->GetFunctionAddress("Wait_for_multiple");

            /* Verify */
            if ((nullptr == Create_alarm) ||
                /*(nullptr == Create_blocker) ||*/
                (nullptr == Create_event) ||
                (nullptr == Create_thread) ||
                (nullptr == Give_up) ||
                (nullptr == Wait_for_multiple) )
            {
                delete dl;
                return Failed_to_load_function;
            }

            /* Save DL */
            g_thread_library = dl;

            /* Done */
            return Success;
        }

        void UnloadDL()
        {
            delete g_thread_library;
            g_thread_library = nullptr;

            Create_alarm = nullptr;
            /* Create_blocker = nullptr; */
            Create_event = nullptr;
            Create_thread = nullptr;
            Give_up = nullptr;
            Wait_for_multiple = nullptr;
        }
    }
}
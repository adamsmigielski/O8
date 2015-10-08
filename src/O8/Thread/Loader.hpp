/** License
*
* Copyright (c) 2015 Adam Śmigielski
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
* @file Loader.hpp
**/

#include "Alarm.hpp"
#include "Blocker.hpp"
#include "Event.hpp"
#include "Synchronizer.hpp"
#include "Thread.hpp"

namespace O8
{
    namespace Thread
    {
        /* Cross DLL entry points */
        typedef void (UTILITIES_API * PFN_LINK_THREAD)(
            O8::Thread::PFN_CREATE_ALARM create_alarm,
            /*O8::Thread::PFN_CREATE_BLOCKER create_blocker,*/
            O8::Thread::PFN_CREATE_EVENT create_event,
            O8::Thread::PFN_CREATE_THREAD create_thread,
            O8::Thread::PFN_GIVE_UP give_up,
            O8::Thread::PFN_WAIT_FOR_MULTIPLE wait_for_multiple);

        /* DL entry points */
        extern PFN_CREATE_ALARM Create_alarm;
      /*extern PFN_CREATE_BLOCKER Create_blocker;*/
        extern PFN_CREATE_EVENT Create_event;
        extern PFN_CREATE_THREAD Create_thread;
        extern PFN_GIVE_UP Give_up;
        extern PFN_WAIT_FOR_MULTIPLE Wait_for_multiple;

        /* Static routines */
        int LoadDL(const char * library_path);
        void UnloadDL();
    }
}

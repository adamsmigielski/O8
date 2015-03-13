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

#include <O8\Common\ErrorCodes.hpp>
#include "Loader.hpp"
#include "ErrorCodes.hpp"

#include <O8\DL\DL.hpp>
#include <O8\Thread\Loader.hpp>

namespace O8
{
    namespace WS
    {
        /* DL reference */
        static DL::DL * g_ws_library = nullptr;

        /* DL entry points */
        PFN_CREATE_MANAGER Create_manager;

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
            auto link_thread = (Thread::PFN_LINK_THREAD) dl->GetFunctionAddress("Link_thread");
            Create_manager = (PFN_CREATE_MANAGER) dl->GetFunctionAddress("Create_manager");

            /* Verify */
            if ((nullptr == Create_manager) ||
                (nullptr == link_thread))
            {
                delete dl;
                return Failed_to_load_function;
            }

            /* Link thread */
            link_thread(
                Thread::Create_alarm,
                Thread::Create_event,
                Thread::Create_thread,
                Thread::Give_up,
                Thread::Wait_for_multiple);

            /* Save DL */
            g_ws_library = dl;

            /* Done */
            return Success;
        }

        void UnloadDL()
        {
            delete g_ws_library;
            g_ws_library = nullptr;

            Create_manager = nullptr;
        }
    }
}

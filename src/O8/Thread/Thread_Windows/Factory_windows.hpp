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
* @file Facotry_windows.hpp
**/

#ifndef O8_THREAD_FACTORY_WINDOWS_HPP
#define O8_THREAD_FACTORY_WINDOWS_HPP

#include <O8\Thread\Factory.hpp>

namespace O8
{
    namespace Thread
    {
        class Factory_windows : Factory
        {
        public:
            Factory_windows();
            virtual ~Factory_windows();

            virtual Alarm   * Create_alarm();
            virtual Blocker * Create_blocker();
            virtual Event   * Create_event();
            virtual Thread  * Create_thread();

            virtual void Give_up_cpu();
            virtual Synchronizer::WaitResult Wait_for_multiple(
                Synchronizer ** synchronizers,
                Platform::uint32 number);
        };
    }
}

#endif O8_GI_YYY_HPP

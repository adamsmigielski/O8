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
* @file Facotry.hpp
**/

#ifndef O8_THREAD_FACTORY_HPP
#define O8_THREAD_FACTORY_HPP

#include "Synchronizer.hpp"

namespace O8
{
    namespace Thread
    {
        class Alarm;
        class Blocker;
        class Event;
        class Thread;

        class Factory
        {
        public:
            virtual ~Factory();

            virtual Alarm   * Create_alarm()   = 0;
            virtual Blocker * Create_blocker() = 0;
            virtual Event   * Create_event()   = 0;
            virtual Thread  * Create_thread()  = 0;

            virtual void Give_up_cpu() = 0;
            virtual Synchronizer::WaitResult Wait_for_multiple(
                Synchronizer ** synchronizers,
                Platform::uint32 number) = 0;

        protected:
            Factory();
        };

        extern Factory * Create_factory();
    }
}

#endif O8_GI_YYY_HPP

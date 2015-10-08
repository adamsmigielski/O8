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
* @file Manager.hpp
**/

#ifndef O8_WS_MANAGER_HPP
#define O8_WS_MANAGER_HPP

namespace O8
{
	namespace WS
	{
        class Window;
        class Window_event_handler;

		class Manager
		{
		public:
			virtual ~Manager();

            /* Event processing */
            virtual Platform::int32 Start_event_processing() = 0;
            virtual Platform::int32 Stop_event_processing() = 0;
            virtual Platform::int32 Process_events() = 0;

            /* Window management */
            virtual Window * Create_window() = 0;

        protected:
            Manager();
		};

        typedef Manager * (UTILITIES_API * PFN_CREATE_MANAGER)();
	}
}

#endif /* O8_WS_MANAGER_HPP */

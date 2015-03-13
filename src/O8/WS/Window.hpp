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
* @file Window.hpp
**/

#ifndef O8_WS_WINDOW_HPP
#define O8_WS_WINDOW_HPP

namespace O8
{
	namespace WS
	{
		class Window_event_handler;

		class Window
		{
		public:
			/* Creation and initialization */
			typedef void * Native;

			Window();
			virtual ~Window();

			virtual int32 Init(
				Window_event_handler * handler,
				int32 x,
				int32 y,
				int32 width,
				int32 height,
				const char * title) = 0;
			virtual int32 Init(
				Native native,
				Window_event_handler * handler) = 0;
			virtual void Release() = 0;

			/* Native */
			virtual Native Get_native() = 0;

			/* Event handling */
			virtual Window_event_handler * Get_event_handler() = 0;
            void * Get_user_data();
            void Set_user_data(void * info);

			/* Size and position */
			virtual void X(int32 val) = 0;
			virtual void Y(int32 val) = 0;

			virtual int32 X() const = 0;
			virtual int32 Y() const = 0;

			virtual void Width(int32 val) = 0;
			virtual void Height(int32 val) = 0;

			virtual int32 Width() const = 0;
			virtual int32 Height() const = 0;

			virtual void Client_width(int32 width) = 0;
			virtual void Client_height(int32 height) = 0;

			virtual int32 Client_width() const = 0;
			virtual int32 Client_height() const = 0;

			/* Title */
			virtual void Get_title(std::string & title) const = 0;
			virtual void Set_title(const std::string & title) = 0;

        private:
            void * m_user_data;
		};
	}
}

#endif /* O8_WS_WINDOW_HPP */


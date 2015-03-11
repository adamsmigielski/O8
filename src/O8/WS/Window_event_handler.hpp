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
* @file Window_event_handler.hpp
**/

#ifndef O8_WS_WINDOW_EVENT_HANDLER_HPP
#define O8_WS_WINDOW_EVENT_HANDLER_HPP

namespace O8
{
    namespace WS
    {
        class Window;

        class Window_event_handler
        {
        public:
            enum class Sizing_direction {
                Bottom,
                Bottom_left,
                Left,
                Top_left,
                Top,
                Top_right,
                Right,
                Bottom_right,
            };

            Window_event_handler & operator = (const Window_event_handler &) = delete;
            virtual ~Window_event_handler();

            /* Internal callbacks */
            virtual void On_init(
                Window * window);

            virtual void On_release(
                Window * window);

            /* OS */
            virtual int32 On_deactivation(
                Window * window);
            virtual int32 On_activation_click(
                Window * window);
            virtual int32 On_activation(
                Window * window);
                          
            virtual int32 On_close(
                Window * window,
                bool & should_window_close);
            virtual int32 On_quit(
                Window * window);

            virtual int32 On_power_suspend(
                Window * window);
            virtual int32 On_power_resume(
                Window * window);
                          
            virtual int32 On_moving(
                Window * window,
                int32 & left,
                int32 & top,
                int32 & right,
                int32 & bottom);
            virtual int32 On_move(
                Window * window,
                int32 x,
                int32 y);

            virtual int32 On_sizing(
                Window * window,
                Sizing_direction direction,
                int32 & left,
                int32 & top,
                int32 & right,
                int32 & bottom);
            virtual int32 On_size(
                Window * window,
                int32 width,
                int32 height);
            virtual int32 On_maximization(
                Window * window,
                int32 width,
                int32 height);
            virtual int32 On_minimization(
                Window * window,
                int32 width,
                int32 height);
            virtual int32 On_other_window_maximized_or_restored(
                Window * window,
                int32 width,
                int32 height);

            virtual int32 On_paint(
                Window * window);

            virtual int32 On_menu(
                Window * window,
                uint16 id);

            ////OIS
            ////Keyboard
            //virtual bool OnKeyPressed(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg );
            //virtual bool OnKeyReleased(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg );
            //
            ////Mouse
            //virtual bool OnMouseMoved(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg );
            //virtual bool OnMousePressed(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id );
            //virtual bool OnMouseReleased(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id );
            //
            ////Joy
            //virtual bool OnButtonPressed(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button );
            //virtual bool OnButtonReleased(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button );
            //virtual bool OnAxisMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int axis );
            //virtual bool OnPovMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int pov );
            //virtual bool OnVector3Moved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int index);



        protected:
            Window_event_handler();
        };
    }
}

#endif /* O8_WS_WINDOW_EVENT_HANDLER_HPP */

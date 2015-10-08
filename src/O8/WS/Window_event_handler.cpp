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
* @file Window_event_handler.cpp
**/

#include "PCH.hpp"

#include <Utilities\basic\ErrorCodes.hpp>

#include "Window_event_handler.hpp"


namespace O8
{
    namespace WS
    {
        Window_event_handler::Window_event_handler()
        {
        }

        Window_event_handler::~Window_event_handler()
        {
        }
        
        void Window_event_handler::On_init(
            Window * window)
        {

        }

        void Window_event_handler::On_release(
            Window * window)
        {

        }

        Platform::int32 Window_event_handler::On_deactivation(
            Window * window)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_activation_click(
            Window * window)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_activation(
            Window * window)
        {
            return Utilities::Success;
        }


        Platform::int32 Window_event_handler::On_close(
            Window * window,
            bool & should_window_close)
        {
            should_window_close = true;

            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_quit(
            Window * window)
        {
            return Utilities::Success;
        }


        Platform::int32 Window_event_handler::On_power_suspend(
            Window * window)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_power_resume(
            Window * window)
        {
            return Utilities::Success;
        }


        Platform::int32 Window_event_handler::On_moving(
            Window * window,
            Platform::int32 & left,
            Platform::int32 & top,
            Platform::int32 & right,
            Platform::int32 & bottom)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_move(
            Window * window,
            Platform::int32 x,
            Platform::int32 y)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_sizing(
            Window * window,
            Sizing_direction direction,
            Platform::int32 & left,
            Platform::int32 & top,
            Platform::int32 & right,
            Platform::int32 & bottom)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_size(
            Window * window,
            Platform::int32 width,
            Platform::int32 height)

        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_maximization(
            Window * window,
            Platform::int32 width,
            Platform::int32 height)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_minimization(
            Window * window,
            Platform::int32 width,
            Platform::int32 height)

        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_other_window_maximized_or_restored(
            Window * window,
            Platform::int32 width,
            Platform::int32 height)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_paint(
            Window * window)
        {
            return Utilities::Success;
        }

        Platform::int32 Window_event_handler::On_menu(
            Window * window,
			Platform::uint16 id)

        {
            return Utilities::Success;
        }

        ////Keyboard
		//bool WindowEventHandler::OnKeyPressed(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg)
		//{
		//	return true;
		//}
        //
		//bool WindowEventHandler::OnKeyReleased(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg)
		//{
		//	return true;
		//}
        //
        //
		////Mouse
		//bool WindowEventHandler::OnMouseMoved(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg)
		//{
		//	return true;
		//}
        //
		//bool WindowEventHandler::OnMousePressed(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id)
		//{
		//	return true;
		//}
        //
		//bool WindowEventHandler::OnMouseReleased(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id)
		//{
		//	return true;
		//}
        //
        //
		////Joy
		//bool WindowEventHandler::OnButtonPressed(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button)
		//{
		//	return true;
		//}
        //
		//bool WindowEventHandler::OnButtonReleased(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button)
		//{
		//	return true;
		//}
        //
		//bool WindowEventHandler::OnAxisMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int axis)
		//{
		//	return true;
		//}
        //
		//bool WindowEventHandler::OnPovMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int pov)
		//{
		//	return true;
		//}
        //
		//bool WindowEventHandler::OnVector3Moved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int index)
		//{
		//	return true;
		//}
    }
}


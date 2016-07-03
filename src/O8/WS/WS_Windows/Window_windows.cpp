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
* @file Window_windows.cpp
**/

#include "PCH.hpp"

#include <Utilities\basic\ErrorCodes.hpp>
#include <O8\WS\Window_event_handler.hpp> /* Window_event_handler */

#include "Window_windows.hpp"
#include "Window_class_register.hpp"

namespace O8
{
	namespace WS
	{
		Window_windows::Window_windows()
            : m_native(NULL)
			, m_handler(nullptr)
		{
			/* Nothing to be done here */
		}

		Window_windows::~Window_windows()
		{
			release();
		}

		Platform::int32 Window_windows::Init(
			Window_event_handler * handler,
			Platform::int32 x,
			Platform::int32 y,
			Platform::int32 width,
			Platform::int32 height,
			const char * title)
		{
            auto wcs = Window_class_register::Get_singleton();

            HWND hwnd = CreateWindowEx(
                WS_EX_TOPMOST,
                wcs->Get_class_name(),
                title,
                WS_VISIBLE | WS_OVERLAPPEDWINDOW,
                x,
                y,
                width,
                height,
                GetDesktopWindow(),
                0 /* hMenu*/,
                GetModuleHandle(0),
                0 /* WM_CREATE lParam */);

            if (NULL == hwnd)
            {
                ASSERT(0);
                ERRLOG("CreateWindowEx - err: " << GetLastError());
                return Utilities::Failure;
            }

            auto ret = Init((Native) &hwnd, handler);
            if (Utilities::Success != ret)
            {
                ASSERT(0);
                ERRLOG("Failed to initialize window");
                DestroyWindow(hwnd);
            }

            return ret;
		}

		Platform::int32 Window_windows::Init(
			Native native,
			Window_event_handler * handler)
		{
            if (NULL != m_native)
            {
                ASSERT(0);
				return Utilities::Invalid_object;
            }

            if (nullptr == native)
            {
                ASSERT(0);
				return Utilities::Invalid_parameter;
            }

            HWND * p_hwnd = (HWND *) native;
            m_native = *p_hwnd;
            m_handler = handler;

            if (NULL == m_native)
            {
                ASSERT(0);
				return Utilities::Invalid_parameter;
            }

            if (nullptr != m_handler)
            {
                SetLastError(0);
                auto result = SetWindowLongPtr(m_native, GWLP_USERDATA, (LONG_PTR) this);
                if (0 == result)
                {
                    DWORD err = GetLastError();
                    if (0 != err)
                    {
                        ASSERT(0);
                        ERRLOG("Failed to store this pointer in window object: " << err);
                        m_native = 0;
						return Utilities::Failure;
                    }
                }

                result = SetWindowLongPtr(m_native, GWLP_WNDPROC, (LONG_PTR) window_procedure);
                if (0 == result)
                {
                    DWORD err = GetLastError();
                    if (0 != err)
                    {
                        ASSERT(0);
                        ERRLOG("Failed to set window procedure: " << err);
                        m_native = 0;
						return Utilities::Failure;
                    }
                }

                m_handler->On_init(this);
            }

            return Utilities::Success;
		}

        void Window_windows::Close()
        {
            SendMessage(
                m_native,
                WM_CLOSE,
                0,
                0);
        }

		void Window_windows::Release()
		{
			release();
		}

		Window::Native Window_windows::Get_native()
		{
			return &m_native;
        }

        Window_windows * Window_windows::Get_from_native(HWND wnd)
        {
            return (Window_windows *) GetWindowLongPtr(wnd, GWLP_USERDATA);;
        }

		Window_event_handler * Window_windows::Get_event_handler()
		{
			return m_handler;
		}

		void Window_windows::X(Platform::int32 val)
		{
			RECT rect;
			GetWindowRect(m_native, &rect);
			MoveWindow(
				m_native,				/* handle */
				val,				    /* x */
				rect.top,				/* y */
				rect.right - rect.left,	/* w */
				rect.bottom - rect.top,	/* h */
				false);					/* repaint */
        }

        Platform::int32 Window_windows::X() const
        {
            RECT rect;
            GetWindowRect(m_native, &rect);

            return rect.left;
        }

		void Window_windows::Y(Platform::int32 val)
		{
			RECT rect;
			GetWindowRect(m_native, &rect);
			MoveWindow(
				m_native,				/* handle */
				rect.left,              /* x */
				val,		     		/* y */
				rect.right - rect.left,	/* w */
				rect.bottom - rect.top,	/* h */
				false);					/* repaint */
        }

        Platform::int32 Window_windows::Y() const
        {
            RECT rect;
            GetWindowRect(m_native, &rect);

            return rect.top;
        }

        void Window_windows::Width(Platform::int32 val)
        {
            RECT rect;
            GetWindowRect(m_native, &rect);
            MoveWindow(
                m_native,				/* handle */
                rect.left,              /* x */
                rect.top,	     		/* y */
                val,                   	/* w */
                rect.bottom - rect.top,	/* h */
                false);					/* repaint */

            update_input_system(
                val,
                rect.bottom - rect.top);
        }

        Platform::int32 Window_windows::Width() const
        {
            RECT rect;
            GetWindowRect(m_native, &rect);

            return rect.right - rect.left;
        }

        void Window_windows::Height(Platform::int32 val)
        {
            RECT rect;
            GetWindowRect(m_native, &rect);
            MoveWindow(
                m_native,				/* handle */
                rect.left,              /* x */
                rect.top,	     		/* y */
                rect.right - rect.left,	/* w */
                val,                   	/* h */
                false);					/* repaint */

            update_input_system(
                rect.right - rect.left,
                val);
        }

        Platform::int32 Window_windows::Height() const
        {
            RECT rect;
            GetWindowRect(m_native, &rect);

            return rect.bottom - rect.top;
        }

        void Window_windows::Client_width(Platform::int32 val)
        {
            RECT rect;
            WINDOWINFO info;

            GetClientRect(m_native, &rect);
            GetWindowInfo(m_native, &info);

            rect.right = val;
            AdjustWindowRect(
                &rect,
                info.dwStyle,
                IsMenu(GetMenu(m_native)));

            MoveWindow(
                m_native,				/* handle */
                rect.left,              /* x */
                rect.top,	     		/* y */
                rect.right - rect.left,	/* w */
                rect.bottom - rect.top,	/* h */
                false);					/* repaint */

            update_input_system(
                rect.right - rect.left,
                rect.bottom - rect.top);
        }

        Platform::int32 Window_windows::Client_width() const
        {
            RECT rect;
            GetClientRect(m_native, &rect);

            return rect.right - rect.left;
        }

        void Window_windows::Client_height(Platform::int32 val)
        {
            RECT rect;
            WINDOWINFO info;

            GetClientRect(m_native, &rect);
            GetWindowInfo(m_native, &info);

            rect.bottom = val;
            AdjustWindowRect(
                &rect,
                info.dwStyle,
                IsMenu(GetMenu(m_native)));

            MoveWindow(
                m_native,				/* handle */
                rect.left,              /* x */
                rect.top,	     		/* y */
                rect.right - rect.left,	/* w */
                rect.bottom - rect.top,	/* h */
                false);					/* repaint */

            update_input_system(
                rect.right - rect.left,
                rect.bottom - rect.top);
        }

        Platform::int32 Window_windows::Client_height() const
        {
            RECT rect;
            GetClientRect(m_native, &rect);

            return rect.bottom - rect.top;
        }

        void Window_windows::Get_title(std::string & title) const
        {
            int length = GetWindowTextLength(m_native);
            title.reserve(length + 1);

            GetWindowText(m_native, (char *)title.c_str(), length + 1);
        }

        void Window_windows::Set_title(const std::string & title)
        {
            SetWindowText(m_native, title.c_str());
        }

        Platform::int32 Window_windows::Show()
        {
            ShowWindow(m_native, SW_SHOW);

            return Utilities::Success;
        }

        LRESULT Window_windows::Handle_event(OS_message & msg)
        {
            LRESULT ret = 0;

            switch (msg.uMsg)
            {
            case WM_ACTIVATE:
                ret = on_wm_activate(msg);
                break;

            case WM_CLOSE:
                ret = on_wm_close(msg);
                break;

            case WM_COMMAND:
                ret = on_wm_command(msg);
                break;

            case WM_DESTROY:
                ret = on_wm_destroy(msg);
                break;

            case WM_MOVE:
                ret = on_wm_move(msg);
                break;

            case WM_MOVING:
                ret = on_wm_moving(msg);
                break;

            case WM_POWERBROADCAST:
                ret = on_wm_power_broadcast(msg);
                break;

            case WM_PAINT:
                ret = on_wm_paint(msg);
                break;

            case WM_QUIT:
                ret = on_wm_quit(msg);
                break;

            case WM_SIZING:
                ret = on_wm_sizing(msg);
                break;

            case WM_SIZE:
                ret = on_wm_size(msg);
                break;

            default:
                ret = DefWindowProc(
                    msg.hwnd,
                    msg.uMsg,
                    msg.wParam,
                    msg.lParam);
            }

            return ret;
        }

        Platform::int32 Window_windows::Process_messages()
        {
            MSG msg;
            BOOL ret;
            DWORD err;

            while (TRUE == PeekMessage(&msg, m_native, 0, 0, PM_NOREMOVE))
            {
                ret = GetMessage(&msg, m_native, 0, 0);
                if (0 == ret)
                {
                    LOG("Quit message received");
                    return Msg_prc_quit;
                }
                else if (-1 == ret)
                {
                    err = GetLastError();
                    ERRLOG("Error occurred: " << err);

                    return Msg_prc_error;
                }
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }

            capture_input();

            return Msg_prc_Successfull;
        }

        void Window_windows::capture_input(){}
        void Window_windows::disable_input_system(){}
        void Window_windows::enable_input_system(){}

        LRESULT Window_windows::on_wm_activate(OS_message & msg)
        {
            switch (msg.wParam)
            {
            case WA_INACTIVE:
                m_handler->On_deactivation(this);
                break;
            case WA_CLICKACTIVE:
                m_handler->On_activation_click(this);
                break;
            case WA_ACTIVE:
                m_handler->On_activation(this);
                break;
            }
            
            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_close(OS_message & msg)
        {
            bool close_window = true;

            m_handler->On_close(
                this,
                close_window);

            if (true == close_window)
            {
                Release();
            }

            return 0;
        }

        LRESULT Window_windows::on_wm_command(OS_message & msg)
        {
            Platform::uint16 type;
            Platform::uint16 id;
            static const Platform::uint16 MENU_TYPE = 0;

			type = (Platform::uint16)HIWORD(msg.wParam);
			id = (Platform::uint16)LOWORD(msg.wParam);

            if (MENU_TYPE == type)
            {
                m_handler->On_menu(
                    this,
                    id);
            }

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_destroy(OS_message & msg)
        {
            release();

            return 0;
        }

        LRESULT Window_windows::on_wm_move(OS_message & msg)
        {
            Platform::int32 x = (Platform::int32)(short)LOWORD(msg.lParam);
            Platform::int32 y = (Platform::int32)(short)HIWORD(msg.lParam);

            m_handler->On_move(
                this,
                x,
                y);

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_moving(OS_message & msg)
        {
            RECT * rect = (RECT *)msg.lParam;
            int left = rect->left;
            int right = rect->right;
            int top = rect->top;
            int bottom = rect->bottom;

            m_handler->On_moving(
                this,
                left,
                top,
                right,
                bottom);

            rect->left = left;
            rect->right = right;
            rect->top = top;
            rect->bottom = bottom;

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_power_broadcast(OS_message & msg)
        {
            switch (msg.wParam)
            {
            case PBT_APMSUSPEND:
                LOG("Going to sleep mode");
                m_handler->On_power_suspend(this);
                break;
            case PBT_APMRESUMESUSPEND:
                LOG("Resuming from sleep mode");
                m_handler->On_power_resume(this);
                break;
            }

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_paint(OS_message & msg)
        {
            m_handler->On_paint(this);

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_quit(OS_message & msg)
        {
            m_handler->On_quit(this);

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_sizing(OS_message & msg)
        {
            RECT * rect = (RECT *)msg.lParam;
            Window_event_handler::Sizing_direction direction;
            int left = rect->left;
            int right = rect->right;
            int top = rect->top;
            int bottom = rect->bottom;

            switch (msg.wParam)
            {
            case WMSZ_BOTTOM:
                direction = Window_event_handler::Sizing_direction::Bottom;
                break;
            case WMSZ_BOTTOMLEFT:
                direction = Window_event_handler::Sizing_direction::Bottom_left;
                break;
            case WMSZ_LEFT:
                direction = Window_event_handler::Sizing_direction::Left;
                break;
            case WMSZ_TOPLEFT:
                direction = Window_event_handler::Sizing_direction::Top_left;
                break;
            case WMSZ_TOP:
                direction = Window_event_handler::Sizing_direction::Top;
                break;
            case WMSZ_TOPRIGHT:
                direction = Window_event_handler::Sizing_direction::Top_right;
                break;
            case WMSZ_RIGHT:
                direction = Window_event_handler::Sizing_direction::Right;
                break;
            case WMSZ_BOTTOMRIGHT:
                direction = Window_event_handler::Sizing_direction::Bottom_right;
                break;
            }

            m_handler->On_sizing(
                this,
                direction,
                left,
                top,
                right,
                bottom);


            rect->left = left;
            rect->right = right;
            rect->top = top;
            rect->bottom = bottom;

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        LRESULT Window_windows::on_wm_size(OS_message & msg)
        {
            Platform::uint32 width = (Platform::uint32)(short)LOWORD(msg.lParam);
            Platform::uint32 height = (Platform::uint32)(short)HIWORD(msg.lParam);

            switch (msg.wParam)
            {
            case SIZE_RESTORED:
                update_input_system(
                    width,
                    height);

                m_handler->On_size(
                    this,
                    width,
                    height);
                break;
            case SIZE_MINIMIZED:
                disable_input_system();

                m_handler->On_minimization(
                    this,
                    width,
                    height);
                break;
            case SIZE_MAXIMIZED:
                enable_input_system();

                update_input_system(
                    width,
                    height);

                m_handler->On_maximization(
                    this,
                    width,
                    height);
                break;
            case SIZE_MAXHIDE:
                disable_input_system();

                m_handler->On_other_window_maximized_or_restored(
                    this,
                    width,
                    height);
                break;
            case SIZE_MAXSHOW:
                enable_input_system();

                update_input_system(
                    width,
                    height);

                m_handler->On_other_window_maximized_or_restored(
                    this,
                    width,
                    height);
                break;
            }

            return DefWindowProc(
                msg.hwnd,
                msg.uMsg,
                msg.wParam,
                msg.lParam);
        }

        void Window_windows::release()
        {
            /* This routine will be re-entered by DestroyWindow */
            HWND wnd = m_native;
            auto handler = m_handler;

            m_native = NULL;
            m_handler = nullptr;

            if (NULL != wnd)
            {
                DestroyWindow(wnd);
            }

            if (nullptr != handler)
            {
                handler->On_release(this);
            }
        }

        void Window_windows::update_input_system(
            Platform::int32 w,
            Platform::int32 h)
        {
        }

        LRESULT Window_windows::window_procedure(
            HWND hwnd,
            UINT msg,
            WPARAM wParam,
            LPARAM lParam)
        {
            auto window = Get_from_native(hwnd);

            if (nullptr != window)
            {
                OS_message message = { hwnd, msg, wParam, lParam };
                return window->Handle_event(message);
            }
            else
            {
                ASSERT(0);

                return DefWindowProc(hwnd, msg, wParam, lParam);
            }
        }
    }
}

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
* @file main.cpp
**/

#include "PCH.hpp"

#include <O8\Common\ErrorCodes.hpp>
#include <O8\Thread\Loader.hpp>
#include <O8\WS\Loader.hpp>
#include <O8\WS\ErrorCodes.hpp>
#include <O8\WS\Window.hpp>
#include <O8\WS\Window_event_handler.hpp>
#include <O8\Test\Test.hpp>

class Event_handler : public O8::WS::Window_event_handler
{
public:
    void Init(O8::WS::Manager * manager)
    {
        m_manager = manager;
        m_close = 0;
        m_release = 0;
    }

    O8::uint32 GetClose()
    {
        return m_close;
    }

    O8::uint32 GetRelease()
    {
        return m_release;
    }

    virtual O8::int32 On_close(
        O8::WS::Window * window,
        bool & should_window_close)
    {
        should_window_close = true;

        m_close += 1;

        return 0;
    }

    virtual void On_release(
        O8::WS::Window * window)
    {
        m_manager->Stop_event_processing();

        m_release += 1;
    }

private:
    O8::WS::Manager * m_manager;
    O8::uint32 m_close;
    O8::uint32 m_release;
};

int main()
{
    Event_handler handler;

	O8_TEST_INIT("ws_test.txt");

    O8_TEST_ASSERT((O8::Success == O8::Thread::LoadDL("Thread_Windows.dll")), "O8::Thread::LoadDL");

    O8_TEST_ASSERT((O8::Success == O8::WS::LoadDL("WS_Windows.dll")), "O8::WS::LoadDL");

	auto ws_manager = O8::WS::Create_manager();
	O8_TEST_ASSERT((nullptr != ws_manager), "O8::WS::Create_manager");
    handler.Init(ws_manager);

    auto ws_window = ws_manager->Create_window();
    O8_TEST_ASSERT((nullptr != ws_window), "O8::WS::Manager::Create_window");

    O8_TEST_ASSERT((O8::Success == ws_window->Init(&handler, 16, 16, 64, 64, "WS_Test")), "O8::WS::Window::Init");

    ws_manager->Start_event_processing();
    O8_TEST_CHECK((1 <= handler.GetClose()), "O8::WS::Manager::Start/Stop_event_processing - close >= 1");
    O8_TEST_CHECK((1 <= handler.GetRelease()), "O8::WS::Manager::Start/Stop_event_processing - release >= 1");
    O8_TEST_CHECK((1 == handler.GetClose()), "O8::WS::Manager::Start/Stop_event_processing - close == 1");
    O8_TEST_CHECK((1 == handler.GetRelease()), "O8::WS::Manager::Start/Stop_event_processing - release == 1");

    delete ws_window;
    delete ws_manager;

    O8::WS::UnloadDL();
    O8::Thread::UnloadDL();

    return 0;
}



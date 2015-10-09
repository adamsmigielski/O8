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
* @file main.cpp
**/

#include "PCH.hpp"

#include <Utilities\basic\ErrorCodes.hpp>
#include <O8\Thread\Loader.hpp>
#include <O8\WS\Loader.hpp>
#include <O8\WS\ErrorCodes.hpp>
#include <O8\WS\Window.hpp>
#include <O8\WS\Window_event_handler.hpp>
#include <O8\GI\Loader.hpp>
#include <O8\GI\Presentation.hpp>
#include <O8\GI\RI.hpp>
#include <Unit_Tests\UnitTests.hpp>

class GI_test_enviroment : public UnitTests::EnviromentBase
{
public:
    GI_test_enviroment()
    {
        ASSERT(Utilities::Success == O8::Thread::LoadDL(THREAD_IMPL));
        ASSERT(Utilities::Success == O8::WS::LoadDL(WS_IMPL));
        ASSERT(Utilities::Success == O8::GI::LoadDL(GI_IMPL));
    }

    virtual ~GI_test_enviroment()
    {
        O8::GI::UnloadDL();
        O8::WS::UnloadDL();
        O8::Thread::UnloadDL();
    }

private:
    static GI_test_enviroment s_gi_test_enviroment;
};

class Event_handler : public O8::WS::Window_event_handler
{
public:
    void Init(O8::WS::Manager * manager)
    {
        m_manager = manager;
    }

    virtual Platform::int32 On_close(
        O8::WS::Window * window,
        bool & should_window_close)
    {
        should_window_close = true;

        return 0;
    }

    virtual void On_release(
        O8::WS::Window * window)
    {
        m_manager->Stop_event_processing();
    }

private:
    O8::WS::Manager * m_manager;
};

GI_test_enviroment GI_test_enviroment::s_gi_test_enviroment;

UNIT_TEST(gi_creation_and_closing)
{
    Event_handler handler;

    auto ws_manager = O8::WS::Create_manager();
    TEST_ASSERT((nullptr != ws_manager), "O8::WS::Create_manager");
    handler.Init(ws_manager);

    auto ws_window = ws_manager->Create_window();
    TEST_ASSERT((nullptr != ws_window), "O8::WS::Manager::Create_window");

    TEST_ASSERT((Utilities::Success == ws_window->Init(&handler, 16, 16, 64, 64, "GI_Test")), "O8::WS::Window::Init");

    O8::GI::GI * gi = O8::GI::Create_GI();
    TEST_ASSERT((nullptr != gi), "O8::GI::Create_GI");

    TEST_ASSERT((Utilities::Success == gi->Init()), "O8::GI::GI::Init");

    auto ri = gi->Create_rendering_interface(gi->First());
    
    auto presentation = ri->Create_presentation_for_window(ws_window->Get_native());
    ws_window->Set_user_data(presentation);

    TEST_ASSERT((presentation == ws_window->Get_user_data()), "O8::WS::Window::Get_user_data");

    delete presentation;
    delete ri;
    delete gi;

    delete ws_window;
    delete ws_manager;

    return UnitTests::Passed;
}



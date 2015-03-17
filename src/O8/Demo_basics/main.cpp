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

class Event_handler : public O8::WS::Window_event_handler
{
public:
    void Init(O8::WS::Manager * manager)
    {
        m_manager = manager;
    }

    virtual O8::int32 On_close(
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

int main()
{
    Event_handler handler;

    /* Load dlls */
    O8::Thread::LoadDL("Thread_Windows.dll");
    O8::WS::LoadDL("WS_Windows.dll");
    O8::GI::LoadDL("GI_Windows_OGL.dll");

    /* Prepare window */
    auto ws_manager = O8::WS::Create_manager();
    handler.Init(ws_manager);

    auto ws_window = ws_manager->Create_window();
    ws_window->Init(&handler, 16, 16, 256, 256, "O8_demo_basics");

    /* Prepare graphics interface */  
    O8::GI::GI * gi = O8::GI::Create_GI();
    gi->Init();
    auto ri = gi->Create_rendering_interface(gi->First());
    auto presentation = ri->Create_presentation_for_window(ws_window->Get_native());
    ws_window->Set_user_data(presentation);

    /* Start window events processing */
    ws_manager->Start_event_processing();
    /* Event processing loop has finished */

    /* Release graphics interface */
    delete presentation;
    delete ri;
    delete gi;

    /* Release window */
    delete ws_window;
    delete ws_manager;

    /* Unload dlls */
    O8::WS::UnloadDL();
    O8::Thread::UnloadDL();

    /* Done */
    return 0;
}
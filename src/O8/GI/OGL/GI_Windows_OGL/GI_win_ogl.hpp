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
* @file GI_win_ogl.hpp
**/

#ifndef O8_GI_GI_WIN_OGL_HPP
#define O8_GI_GI_WIN_OGL_HPP

#include <O8\GI\GI.hpp>

namespace O8
{
    namespace GI
    {
        class Adapter_win_ogl;
        class Output_win_ogl;
        class RI_win_ogl;

        class GI_win_ogl : public GI
        {
        public:
            GI_win_ogl();
            virtual ~GI_win_ogl();

            virtual Platform::int32 Init();
            virtual void Release();

            virtual RI * Create_rendering_interface(
                Adapter * adapter);

        private:
            void add_new_adapter(
                const std::string & name,
                const std::string & key,
                const std::string & string,
                Platform::uint32 vendor_id,
                Platform::uint32 device_id);
            void add_output_to_adapter(
                const std::string & name,
                Adapter_win_ogl * adapter);
            Platform::int32 compare_device_key(
                const char * dev_a,
                const char * dev_b);
            RI_win_ogl * create_rendering_interface(
                Output_win_ogl * output);
            Platform::uint32 get_device_id(
                const char * device_id);
            Platform::uint32 get_vendor_id(
                const char * device_id);
            Platform::int32 process_adapters();
        };
    }
}

UTILITIES_API_DECORATION DLL_EXPORT O8::GI::GI * UTILITIES_API Create_GI();

#endif /* O8_GI_GI_WIN_OGL_HPP */

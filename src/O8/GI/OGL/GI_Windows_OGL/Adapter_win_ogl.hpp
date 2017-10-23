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
* @file Adapter_win_ogl.hpp
**/

#ifndef O8_GI_ADAPTER_WIN_OGL_HPP
#define O8_GI_ADAPTER_WIN_OGL_HPP

#include <O8\GI\Adapter.hpp>

namespace O8
{
    namespace GI
    {
        class Adapter_win_ogl : public Adapter
        {
        public:
            Adapter_win_ogl();
            virtual ~Adapter_win_ogl();

            void Add_output(
                const std::string & name);

            void Init(
                const std::string & name,
                const std::string & key,
                Platform::uint32 vendor_id,
                Platform::uint32 device_id);

            virtual std::string Name() const;
            std::string Key() const;

            virtual Platform::uint32 Vendor_id() const;
            virtual Platform::uint32 Device_id() const;
            virtual Platform::uint32 Video_memory() const;
            virtual Platform::uint32 System_memory() const;
            virtual Platform::uint32 Shared_memory() const;


        private:
            std::string m_name;
            std::string m_key;
            Platform::uint32 m_vendor_id;
            Platform::uint32 m_device_id;
        };
    }
}

#endif /* O8_GI_ADAPTER_HPP */

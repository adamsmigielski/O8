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
* @file RS.cpp
**/

#include "PCH.hpp"

#include <O8/GI/GI.hpp>
#include <O8/GI/RI.hpp>

#include "RS.hpp"

namespace O8
{
    namespace RS
    {
        RS::RS()
            : m_ri(nullptr)
        {
        }

        RS::~RS()
        {
            release();
        }

        Platform::int32 RS::Init(
            GI::RI * ri)
        {
            if (nullptr != m_ri)
            {
                ERRLOG("RS already initialized");
                ASSERT(0);
                return Utilities::Invalid_object;
            }

            if (nullptr == ri)
            {
                ASSERT(0);
                return Utilities::Invalid_parameter;
            }

            m_ri = ri;

            return Utilities::Success;
        }

        void RS::Release()
        {
            release();
        }

        void RS::release()
        {
            m_ri = nullptr;
        }
    }
}

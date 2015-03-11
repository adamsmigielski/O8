/** License
*
* Copyright(c) 2014 Adam Œmigielski
*
*
*  Permission is hereby granted, free of charge, to any person obtaining a
*      copy of this software and associated documentation files(the
*      "Software"), to deal in the Software without restriction, including
*      without limitation the rights to use, copy, modify, merge, publish,
*distribute, sublicense, and / or sell copies of the Software, and to
*      permit persons to whom the Software is furnished to do so, subject to
*      the following conditions : The above copyright notice and this permission
*      notice shall be included in all copies or substantial portions of the
*      Software.
*
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
*      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
** /

/**
* @author Adam Œmigielski
* @file Binary_data.cpp
**/

#include "PCH.hpp"
#include "Binary_data.hpp"

namespace O8
{
	namespace Utility
	{
        Binary_data::Binary_data()
			: m_data(nullptr),
			  m_size(0)
		{
		}

        Binary_data::Binary_data(uint8 * data, uint64 size)
			: m_data(data),
			  m_size(size)
		{
		}

        Binary_data::Binary_data(Binary_data & data)
			: m_data(data.m_data),
			  m_size(data.m_size)
		{
			data.Reset();
		}

        Binary_data::~Binary_data()
		{
			Reset();
        }

        Binary_data & Binary_data::Copy(const Binary_data & data)
        {
            auto ptr = new uint8[data.m_size];

            if (nullptr == ptr)
            {
                ERRLOG("Memory allocation failure");
                ASSERT(0);
                return *this;
            }

            memcpy(ptr, data.m_data, data.m_size);

            Reset(ptr, data.m_size);

            return *this;
        }

        Binary_data & Binary_data::Take(Binary_data & data)
		{
			Reset(data.m_data, data.m_size);

			data.Reset();

			return *this;
		}

        uint8 * Binary_data::Data() const
		{
			return m_data;
		}

        uint64 Binary_data::Size() const
		{
			return m_size;
		}

        uint8 * Binary_data::operator [] (uint64 offset) const
        {
            if (offset >= m_size)
            {
                return nullptr;
            }

            return m_data + offset;
        }

        void Binary_data::Reset()
		{
			if (nullptr != m_data)
			{
				delete (char *) m_data;
				m_data = nullptr;
			}
			m_size = 0;
		}

        void Binary_data::Reset(uint8 * data, uint64 size)
		{
			Reset();

			m_data = data;
			m_size = size;
		}

        bool Binary_data::Is_null() const
		{
			return (nullptr == m_data);
		}

	} /* namespace Utility */
} /* namespace Ozone */

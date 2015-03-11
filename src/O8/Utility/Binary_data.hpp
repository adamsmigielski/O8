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
* @file Binary_data.hpp
**/

#ifndef O8_UTILITY_BINARYDATA_HPP
#define O8_UTILITY_BINARYDATA_HPP

namespace O8
{
	namespace Utility
	{
		class Binary_data
		{
		public:
            Binary_data();
            Binary_data(uint8 * data, uint64 size);
            Binary_data(Binary_data & data);
            ~Binary_data();

            Binary_data & Copy(const Binary_data & data);
            Binary_data & Take(Binary_data & data);

			uint8 * Data() const;
			uint64 Size() const;
            uint8 * operator [] (uint64 offset) const;

			void Reset();
			void Reset(uint8 * data, uint64 size);

			bool Is_null() const;

		private:
			uint8 * m_data;
			uint64 m_size;
		};

	} /* namespace Utility */
} /* namespace O8 */
#endif /* O8_UTILITY_BINARYDATA_HPP */

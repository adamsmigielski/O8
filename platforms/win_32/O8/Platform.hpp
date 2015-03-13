/** License
*
* Copyright (c) 2015 Adam Śmigielski
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
* @author Adam Śmigielski
* @file Platform.hpp
**/

#ifndef O8_WIN_32_PLATFORM_HPP
#define O8_WIN_32_PLATFORM_HPP

/* DLL */
#if O8_IS_MINGW

#define DLL_EXPORT __declspec(dllexport)

#define DLL_IMPORT __declspec(dllimport)

#else /* O8_IS_MINGW */

#define DLL_EXPORT __declspec(dllexport)

#define DLL_IMPORT __declspec(dllimport)

#endif /* O8_IS_MINGW */

/* Typedefs */
namespace O8
{
    typedef signed   char      int8;
    typedef unsigned char      uint8;
    typedef signed   short     int16;
    typedef unsigned short     uint16;
    typedef signed   int       int32;
    typedef unsigned int       uint32;
    typedef unsigned int       uint;
    typedef signed   long long int64;
    typedef unsigned long long uint64;
}

#endif /* O8_WIN_32_PLATFORM_HPP */

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
* @file Definitions.hpp
**/

#ifndef O8_UNIT_TESTS_DEFINTIONS_HPP
#define O8_UNIT_TESTS_DEFINTIONS_HPP

#ifdef UNIT_TESTS_ENABLE

#define TEST_ASSERT(C, D) if (0 == C) { this->Assert(D, __FILE__, __LINE__); }

#define UNIT_TEST(NAME) namespace O8                                           \
{                                                                              \
    namespace UnitTests                                                        \
    {                                                                          \
        class Unit_test_ ## NAME : public UnitTests::Test                      \
        {                                                                      \
        public:                                                                \
            Unit_test_ ## NAME()                                               \
                : Test(#NAME)                                                  \
            {                                                                  \
                                                                               \
            }                                                                  \
                                                                               \
            virtual ~Unit_test_ ## NAME()                                      \
            {                                                                  \
                                                                               \
            }                                                                  \
                                                                               \
            virtual Result Run(EnviromentBase & env);                          \
        };                                                                     \
                                                                               \
       TestCreator<Unit_test_ ## NAME> g_ ## NAME ## _creator;                 \
    }                                                                          \
}                                                                              \
                                                                               \
O8::UnitTests::Result O8::UnitTests::Unit_test_ ## NAME::Run(O8::UnitTests::EnviromentBase & env)

#else /* UNIT_TESTS_ENABLE */

#define TEST_ASSERT(C, D) 0

#define UNIT_TEST(NAME) O8::UnitTests::Result O8::UnitTests::Unit_test_ ## NAME ## _disabled()

#endif /* UNIT_TESTS_ENABLE */

#endif /* O8_UNIT_TESTS_DEFINTIONS_HPP */

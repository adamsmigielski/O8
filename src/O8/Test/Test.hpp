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
* @file Test.hpp
**/

#ifndef O8_TEST_TEST_HPP
#define O8_TEST_TEST_HPP

#include <O8\Templates\IntrusiveList.hpp>

#define O8_TEST_INIT(path) O8::Test::Enviroment env(path)
#define O8_TEST_ASSERT(CND,MSG) O8::Test::Assert(env, CND, MSG, __FILE__, __LINE__)
#define O8_TEST_CHECK(CND,MSG) O8::Test::Check("Check", env, CND, MSG)

namespace O8
{
	namespace Test
	{
		enum class Status
		{
			Undefined,
			Success,
			Failure,
		};

        class Result : public IntrusiveList::Node < Result >
        {
        public:
            std::string m_Problem_description;
            std::string m_Name;
            Status m_Status;
        };

		class Enviroment : public IntrusiveList::List < Result >
		{
		public:
			Enviroment(const std::string & file_path);
			~Enviroment();

			auto Allocate_test_result() -> Result *;
            void Flush();

		private:
			std::string m_path;
            uint32 m_flushed_id;
            Result * m_flushed;
		};

		class Test
		{
		public:
			Test(
				const std::string & name,
				Enviroment & env);
			virtual ~Test();

		protected:
			void set_status(
				Status status,
				const std::string & description);


		private:
			Result * m_result;
		};

		class Assert : public Test
		{
		public:
			Assert(
				Enviroment & env,
				bool is_successful,
				const std::string & description,
				const char * file,
				int line);
			virtual ~Assert();

			static const int s_Assertion_failed;
		};

		class Check : public Test
		{
		public:
			Check(
				const std::string & name,
				Enviroment & env,
				bool is_successful,
				const std::string & description);
			virtual ~Check();
		};
	}
}

#endif /* O8_TEST_TEST_HPP */

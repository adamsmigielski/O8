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
* @file Test.cpp
**/

#include "PCH.hpp"

#include "Test.hpp"

#include <fstream>
#include <iomanip>
#include <stdlib.h>

namespace O8
{
	namespace Test
	{
		Enviroment::Enviroment(const std::string & file_path)
			: m_path(file_path)
            , m_flushed_id(0)
            , m_flushed(nullptr)
		{
            /* Begin file */
            std::fstream file(
                m_path.c_str(),
                std::fstream::out | std::fstream::trunc);

            if (false == file.is_open())
            {
                return;
            }

            file << std::setw(4) << "ID";
            file << "|";
            file << std::setw(8) << "Status";
            file << "|";
            file << std::setw(32) << "Name";
            file << "|";
            file << "Description";
            file << std::endl;

            /* Close file */
            file.close();
        }

        void writeLogLine(
            std::fstream & file,
            uint32 id,
            Status status,
            const std::string & name,
            const std::string & description)
        {
            const char * str_status = "Failure";
            if (Status::Success == status)
            {
                str_status = "Success";
            }

            file << std::setw(4) << id;
            file << "|";
            file << std::setw(8) << str_status;
            file << "|";
            file << std::setw(32) << name;
            file << "|";
            file << description;
            file << std::endl;
        }

		Enviroment::~Enviroment()
		{
            Flush();
		}

		auto Enviroment::Allocate_test_result() -> Result *
		{
            auto result = new Result;

            Attach(result);

			return result;
		}

        void Enviroment::Flush()
        {
            /* Open file */
            std::fstream file(
                m_path.c_str(),
                std::fstream::out | std::fstream::app);
            Result * next = nullptr;
            
            if (false == file.is_open())
            {
                return;
            }

            /* Flush results */
            if (nullptr == m_flushed)
            {
                m_flushed = First();
            }
            else
            {
                m_flushed = m_flushed->Next();
            }

            if (nullptr != m_flushed)
            {
                next = m_flushed->Next();
            }


            while (1)
            {
                next = m_flushed->Next();

                writeLogLine(
                    file,
                    m_flushed_id,
                    m_flushed->m_Status,
                    m_flushed->m_Name,
                    m_flushed->m_Problem_description);

                if (nullptr == next)
                {
                    break;
                }
                else
                {
                    m_flushed = next;
                    ++m_flushed_id;
                }
            }

            /* Close file */
            file.close();
        }

		Test::Test(
			const std::string & name,
			Enviroment & env)
		{
			m_result = env.Allocate_test_result();

			m_result->m_Name = name;
			m_result->m_Status = Status::Undefined;
		}

		Test::~Test()
		{
			/* Nothing to be done here */
		}

		void Test::set_status(
			Status status,
			const std::string & description)
		{
			m_result->m_Status = status;
			m_result->m_Problem_description = description;
		}

		const int Assert::s_Assertion_failed = -16;

		Assert::Assert(
			Enviroment & env,
			bool is_successful,
			const std::string & description,
			const char * file,
			int line)
			: Test("Assert", env)
		{
			Status status = Status::Undefined;

			if (true == is_successful)
			{
				status = Status::Success;
			}
			else
			{
				status = Status::Failure;
			}

			std::stringstream stream;
			stream << description
				   << " File: " << file
				   << " Line: " << line;

			set_status(status, description);

			if (false == is_successful)
			{
                env.Flush();

				exit(s_Assertion_failed);
			}
		}

		Assert::~Assert()
		{
			/* Nothing to be done here */
		}

		Check::Check(
			const std::string & name,
			Enviroment & env,
			bool is_succsseful,
			const std::string & description)
			: Test(name, env)
		{
			Status status = Status::Undefined;

			if (true == is_succsseful)
			{
				status = Status::Success;
			}
			else
			{
				status = Status::Failure;
			}

			set_status(status, description);
		}

		Check::~Check()
		{
			/* Nothing to be done here */
		}
	}
}

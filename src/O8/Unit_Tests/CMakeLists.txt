PROJECT ( Unit_Tests )

ADD_LIBRARY (Unit_Tests STATIC
			 Creator.cpp
			 Creator.hpp
			 Definitions.hpp
			 Enumerations.hpp
			 Executor.cpp
			 Executor.hpp
			 ExecutorInterface.cpp
			 ExecutorInterface.hpp
			 Test.cpp
			 Test.hpp
			 UnitTests.cpp
			 UnitTests.hpp)
			 
TARGET_COMPILE_DEFINITIONS (Unit_Tests PUBLIC UNIT_TESTS_ENABLE)

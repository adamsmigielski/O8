PROJECT(WS)

# Files
SET (WS_FILES
     Manager.cpp
     Manager.hpp
     Window.cpp
     Window.hpp
     Window_event_handler.cpp
     Window_event_handler.hpp
     PCH.cpp
     PCH.hpp)

# Binaries
ADD_LIBRARY (WS STATIC ${WS_FILES})

# Setup WS
ADD_DEPENDENCIES(WS
				 basic
				 containers
				 helpers
				 task)

# Test
IF (BUILD_TESTS)

# Binaries
    ADD_EXECUTABLE (WS_Test
    			    ErrorCodes.hpp
    				${CMAKE_SOURCE_DIR}/src/Unit_Tests/main.cpp
    				PCH.cpp
    				PCH.hpp
					test.cpp)

# Setup WS_Test
	TARGET_COMPILE_DEFINITIONS (WS_Test PUBLIC UNIT_TESTS_ENABLE)

	TARGET_LINK_LIBRARIES(WS_Test
						  Unit_Tests
						  WS_UT
                          ${WS_IMPL})
ENDIF (BUILD_TESTS)


ADD_SUBDIRECTORY(${WS_IMPL_DIR})

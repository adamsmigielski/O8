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

SET (WS_LOADER_FILES
     ErrorCodes.hpp
     Loader.cpp
     Loader.hpp
     PCH.cpp
     PCH.hpp)

# Binaries
ADD_LIBRARY (WS STATIC ${WS_FILES})

ADD_LIBRARY (WS_Loader STATIC ${WS_LOADER_FILES})

# Setup WS
ADD_DEPENDENCIES(WS
				 Common
				 containers
				 helpers
				 task)

# Setup WS_Loader
TARGET_LINK_LIBRARIES(WS_Loader ${DL_IMPL})

ADD_DEPENDENCIES(WS_Loader ${THREAD_IMPL})

# Test
IF (BUILD_TESTS)

# Binaries
    ADD_LIBRARY (WS_UT STATIC ${WS_FILES})

    ADD_EXECUTABLE (WS_Test
    			    ErrorCodes.hpp
    				Loader.hpp
    				${CMAKE_SOURCE_DIR}/src/Unit_Tests/main.cpp
    				PCH.cpp
    				PCH.hpp
					test.cpp)

# Setup WS_UT
	TARGET_COMPILE_DEFINITIONS (WS_UT PUBLIC UNIT_TESTS_ENABLE)

# Setup WS_Test
	TARGET_COMPILE_DEFINITIONS (WS_Test PUBLIC UNIT_TESTS_ENABLE)

	TARGET_LINK_LIBRARIES(WS_Test
						  Unit_Tests
						  Thread_Loader
						  WS_UT
						  WS_Loader)

	ADD_DEPENDENCIES(WS_Test ${WS_IMPL})
ENDIF (BUILD_TESTS)

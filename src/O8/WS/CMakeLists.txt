PROJECT(WS)

SET (WS_FILES
     Manager.cpp
     Manager.hpp
     Window.cpp
     Window.hpp
     Window_event_handler.cpp
     Window_event_handler.hpp
     PCH.cpp
     PCH.hpp)

SET (WS_LAODER_FILES
     ErrorCodes.hpp
     Loader.cpp
     Loader.hpp
     PCH.cpp
     PCH.hpp)

ADD_LIBRARY (WS STATIC ${WS_FILES})

ADD_LIBRARY (WS_Loader STATIC ${WS_LAODER_FILES})

TARGET_LINK_LIBRARIES(WS_Loader ${DL_IMPL})

ADD_DEPENDENCIES(WS_Loader ${THREAD_IMPL})

IF (BUILD_TESTS)
    ADD_LIBRARY (WS_UT STATIC ${WS_FILES})

    ADD_EXECUTABLE (WS_Test
    			    ErrorCodes.hpp
    				Loader.hpp
    				../Unit_Tests/main.cpp
    				PCH.cpp
    				PCH.hpp
					test.cpp)

	TARGET_COMPILE_DEFINITIONS (WS_UT PUBLIC UNIT_TESTS_ENABLE)
	TARGET_COMPILE_DEFINITIONS (WS_Test PUBLIC UNIT_TESTS_ENABLE)

	TARGET_LINK_LIBRARIES(WS_Test
						  Unit_Tests
						  Thread_Loader
						  WS_UT
						  WS_Loader)

	ADD_DEPENDENCIES(WS_Test ${WS_IMPL})
ENDIF (BUILD_TESTS)

PROJECT(WS)

ADD_LIBRARY (WS STATIC
			 Manager.cpp
			 Manager.hpp
			 Window.cpp
			 Window.hpp
			 Window_event_handler.cpp
			 Window_event_handler.hpp
			 PCH.cpp
			 PCH.hpp)

ADD_LIBRARY (WS_Loader STATIC
			 ErrorCodes.hpp
			 Loader.cpp
			 Loader.hpp
			 PCH.cpp
			 PCH.hpp)

TARGET_LINK_LIBRARIES(WS_Loader
					  ${DL_IMPL})

ADD_DEPENDENCIES(WS_Loader ${THREAD_IMPL})

IF (BUILD_TESTS)
    ADD_EXECUTABLE (WS_Test
    			    ErrorCodes.hpp
    				Loader.hpp
    				main.cpp
    				PCH.cpp
    				PCH.hpp)

	TARGET_LINK_LIBRARIES(WS_Test
						  Test
						  Thread_Loader
						  WS
						  WS_Loader)

	ADD_DEPENDENCIES(WS_Test ${WS_IMPL})
ENDIF (BUILD_TESTS)

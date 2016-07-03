PROJECT(WS_Windows)

ADD_LIBRARY (WS_Windows STATIC
			 Manager_windows.cpp
			 Manager_windows.hpp
			 PCH.cpp
			 PCH.hpp
			 Window_class_register.cpp
			 Window_class_register.hpp
			 Window_windows.cpp
			 Window_windows.hpp)

TARGET_LINK_LIBRARIES(WS_Windows
					  WS
                      Thread
					  Thread_Windows)

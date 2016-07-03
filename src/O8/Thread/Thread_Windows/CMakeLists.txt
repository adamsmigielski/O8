PROJECT ( Thread_Windows )

ADD_LIBRARY (Thread_Windows STATIC
			 Alarm_windows.cpp
			 Alarm_windows.hpp
			 Blocker_windows.cpp
			 Blocker_windows.hpp
			 Event_windows.cpp
			 Event_windows.hpp
			 Factory_windows.cpp
			 Factory_windows.hpp
			 PCH.cpp
			 PCH.hpp
			 Synchronizer_windows.cpp
			 Synchronizer_windows.hpp
			 Thread_windows.cpp
			 Thread_windows.hpp)

TARGET_LINK_LIBRARIES(Thread_Windows
					  Thread)


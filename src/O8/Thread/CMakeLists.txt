PROJECT ( Thread )

ADD_LIBRARY (Thread_Loader STATIC
			 Loader.cpp
			 Loader.hpp
			 PCH.cpp
			 PCH.hpp)

ADD_LIBRARY (Thread STATIC
			 Alarm.cpp
			 Alarm.hpp
			 Blocker.cpp
			 Blocker.hpp
			 Event.cpp
			 Event.hpp
			 PCH.cpp
			 PCH.hpp
			 Synchronizer.cpp
			 Synchronizer.hpp
			 Thread.cpp
			 Thread.hpp)

TARGET_LINK_LIBRARIES (Thread_Loader
					   ${DL_IMPL})

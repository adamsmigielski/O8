PROJECT ( Thread )

ADD_LIBRARY (Thread STATIC
			 Alarm.cpp
			 Alarm.hpp
			 Blocker.cpp
			 Blocker.hpp
			 Event.cpp
			 Event.hpp
             Factory.cpp
             Factory.hpp
			 PCH.cpp
			 PCH.hpp
			 Synchronizer.cpp
			 Synchronizer.hpp
			 Thread.cpp
			 Thread.hpp)

ADD_SUBDIRECTORY(${THREAD_IMPL_DIR})

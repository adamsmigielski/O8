PROJECT(Demo_basics)

ADD_EXECUTABLE(Demo_basics
			   main.cpp
			   PCH.cpp
			   PCH.hpp)

TARGET_LINK_LIBRARIES(Demo_basics
					  DL
					  GI
					  GI_Loader
					  Thread
					  ${THREAD_IMPL}
					  WS
					  ${WS_IMPL})


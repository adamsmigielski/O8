PROJECT(Demo_basics)

ADD_EXECUTABLE(Demo_basics
			   main.cpp
			   PCH.cpp
			   PCH.hpp)
			   
TARGET_LINK_LIBRARIES(Demo_basics
					  Common
					  DL
					  GI
					  GI_Loader
					  Thread
					  Thread_Loader
					  WS
					  WS_Loader)


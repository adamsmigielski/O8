PROJECT(Demo_vulkan)

INCLUDE_DIRECTORIES(C:\\VulkanSDK\\1.0.39.1\\Include)
LINK_DIRECTORIES(C:\\VulkanSDK\\1.0.39.1\\Bin)

ADD_EXECUTABLE(Demo_vulkan
			   main.cpp
			   PCH.cpp
			   PCH.hpp)
			   
TARGET_LINK_LIBRARIES(Demo_vulkan
					  DL
					  GI
					  GI_Loader
					  Thread
					  ${THREAD_IMPL}
					  WS
					  ${WS_IMPL}
					  Vulkan)


PROJECT ( GI_Vulkan )

ADD_LIBRARY (GI_Vulkan STATIC
			 PCH.cpp
			 PCH.hpp
			 Presentation_vulkan.cpp
			 Presentation_vulkan.hpp
			 RI_vulkan.cpp
			 RI_vulkan.hpp)

TARGET_LINK_LIBRARIES (GI_Vulkan
					   GI)

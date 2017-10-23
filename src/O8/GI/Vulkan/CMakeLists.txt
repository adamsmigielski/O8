PROJECT ( GI_Vulkan )

ADD_LIBRARY (GI_Vulkan STATIC
			 PCH.cpp
			 PCH.hpp
			 Presentation.cpp
			 Presentation.hpp
			 RI.cpp
			 RI.hpp)

TARGET_LINK_LIBRARIES (GI_Vulkan
					   GI)

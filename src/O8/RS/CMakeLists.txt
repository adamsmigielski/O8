PROJECT(RS)

ADD_LIBRARY(RS STATIC
			Forward_renderer.cpp
			Forward_renderer.hpp
			Material.cpp
			Material.hpp
			Model.cpp
			Model.hpp
			PCH.cpp
			PCH.hpp
			Renderer.cpp
			Renderer.hpp
			RS.cpp
			RS.hpp
			Scene.cpp
			Scene.hpp
			Type.cpp
			Type.hpp)

ADD_DEPENDENCIES(RS
			     Common
				 containers
				 helpers
				 memory
				 task
                 GI)
				 
ADD_EXECUTABLE(RS_DEMO
			   main.cpp)
			   
TARGET_LINK_LIBRARIES(RS_DEMO
					  WS_Loader
					  GI_Loader
					  Thread_Loader)
			   
ADD_DEPENDENCIES(RS_DEMO
				 ${GI_IMPL}
				 ${WS_IMPL})
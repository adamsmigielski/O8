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
			     basic
				 containers
				 helpers
				 memory
				 task
                 GI)

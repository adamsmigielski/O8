PROJECT(OpenGL)

ADD_LIBRARY(OpenGL STATIC
			Context.cpp
			Context.hpp
			gl.hpp
			GL_loader.cpp
			GL_loader.hpp
			PCH.cpp
			PCH.hpp)
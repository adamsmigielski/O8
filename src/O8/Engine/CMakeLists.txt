PROJECT(Engine)

ADD_LIBRARY(Engine STATIC
			Actor.cpp
			Actor.hpp
			PCH.cpp
			PCH.hpp)

ADD_DEPENDENCIES(Engine
				 common
				 containers
				 helpers
				 memory
				 task)

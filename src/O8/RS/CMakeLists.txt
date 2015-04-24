PROJECT(RS)

ADD_LIBRARY(RS STATIC
			Material.cpp
			Material.hpp
			Model.cpp
			Model.hpp
			PCH.cpp
			PCH.hpp
			RS.cpp
			RS.hpp)

ADD_DEPENDENCIES(RS
			     Common
                 GI
				 Utility)
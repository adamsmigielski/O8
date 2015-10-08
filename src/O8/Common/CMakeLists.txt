PROJECT(Common)

ADD_LIBRARY (Common STATIC
			 Dll.hpp
			 ErrorCodes.hpp
             PCH.cpp
             PCH.hpp
             )

ADD_DEPENDENCIES(Common
				 basic)
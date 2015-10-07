PROJECT(Common)

ADD_LIBRARY (Common STATIC
			 CallConvention.hpp
			 Dll.hpp
			 ErrorCodes.hpp
             PCH.cpp
             PCH.hpp
             )

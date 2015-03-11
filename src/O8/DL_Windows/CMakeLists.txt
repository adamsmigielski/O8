PROJECT ( DL_Windows )

ADD_LIBRARY ( DL_Windows STATIC
		      DL_Windows.cpp
			  DL_Windows.hpp
			  PCH.cpp
			  PCH.hpp )

TARGET_LINK_LIBRARIES (DL_Windows
					   DL )


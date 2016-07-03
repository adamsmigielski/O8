PROJECT ( DL )

ADD_LIBRARY ( DL STATIC
		      DL.cpp
			  DL.hpp
			  PCH.cpp
			  PCH.hpp )

TARGET_LINK_LIBRARIES ( DL )

ADD_SUBDIRECTORY(${DL_IMPL_DIR})
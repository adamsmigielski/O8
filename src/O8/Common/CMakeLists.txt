PROJECT(Common)

ADD_LIBRARY (Common STATIC
			 Align.hpp
             Assert.hpp
             BreakToDebug.hpp
			 CallConvention.hpp
			 ErrorCodes.hpp
             Log.hpp
             PCH.cpp
             PCH.hpp
             )

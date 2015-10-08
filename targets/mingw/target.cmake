# Preprocessor
ADD_DEFINITIONS(/DUTILITIES_OS=${UTIL_TGT_OS_WINDOWS})
ADD_DEFINITIONS(/DUTILITIES_COMPILER=${UTIL_TGT_COMP_MINGM})

# Compiler        
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -msse2 -Wall -Wl,-subsystem,windows")

IF(CMAKE_BUILD_TYPE MATCHES Debug)
	SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)
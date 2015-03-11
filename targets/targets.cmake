# Select target platform
IF(WIN32)
    MESSAGE("Platform: Windows")
    SET(DL_IMPL "DL_Windows")
    SET(THREAD_IMPL "Thread_Windows")
    SET(WS_IMPL "WS_Windows")
    
    IF(MSVC)
        MESSAGE("Toolchain: Visual Studio")
        set(TARGET "vs")
    ENDIF(MSVC)

    IF(MINGW)
        MESSAGE("Toolchain: MinGW")
        set(TARGET "mingw")
    ENDIF(MINGW)
ENDIF(WIN32)
    

# Include target-specific definitions
include(targets/${TARGET}/target.cmake)

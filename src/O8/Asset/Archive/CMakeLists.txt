PROJECT(Asset_Archive)

ADD_LIBRARY(Asset_Archive STATIC
            File.cpp
            File.hpp
            Library.cpp
            Library.hpp
            PCH.cpp
            PCH.hpp)

ADD_DEPENDENCIES(Asset_Archive
                 containers
                 helpers
                 memory
                 Asset)

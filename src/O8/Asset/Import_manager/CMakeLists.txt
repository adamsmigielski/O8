PROJECT(Asset_Import_Manager)

ADD_LIBRARY(Asset_Import_Manager STATIC
			import_manager.cpp
			import_manager.hpp
			PCH.cpp
			PCH.hpp)

ADD_DEPENDENCIES(Asset_Import_Manager
                 containers
                 helpers
                 Asset_Importer)

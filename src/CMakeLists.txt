include_directories( BEFORE ${PROJECT_SOURCE_DIR}/src/external )
add_subdirectory( external )


include_directories( BEFORE ${PROJECT_SOURCE_DIR}/src/DataModel )
include_directories( BEFORE ${PROJECT_SOURCE_DIR}/src/Logging )
include_directories( BEFORE ${PROJECT_SOURCE_DIR}/src/ServiceDiscovery )
include_directories( BEFORE ${PROJECT_SOURCE_DIR}/src/Store )
include_directories( BEFORE ${PROJECT_SOURCE_DIR}/src/Tool )
include_directories( BEFORE ${PROJECT_SOURCE_DIR}/src/ToolChain )

add_subdirectory( DataModel )
add_subdirectory( Logging )
add_subdirectory( ServiceDiscovery )
add_subdirectory( Store )
# include_directories( BEFORE ${PROJECT_SOURCE_DIR}/Tool )
add_subdirectory( Tool )
add_subdirectory( ToolChain )
# add_subdirectory( logger )
MESSAGE( STATUS ${ToolDAQ_HEADERS} )
MESSAGE( STATUS ${ToolDAQ_SOURCES} )

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

##########

# set( ToolDAQ_HEADERS
#     Store/BoostStore.h
#     Store/PointerWrapper.h
#     Store/SerialisableObject.h
#     Store/Store.h
#     Tool/Tool.h
#     ToolChain/ToolChain.h )

# set( ToolDAQ_SOURCES 
#     Store/BoostStore.cpp
#     Store/Store.cpp
#     ToolChain/ToolChain.cpp )


#message(STATUS "Scarab sources: ${Scarab_SOURCES}" )

pbuilder_library( ToolDAQ ToolDAQ_SOURCES "" )

pbuilder_install_headers( ${ToolDAQ_HEADERS} )



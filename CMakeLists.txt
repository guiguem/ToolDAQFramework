# CMakeLists for ToolDAQ
# Author: N. Oblath

# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required (VERSION 3.1)

#########
# Setup #
#########

cmake_policy( SET CMP0048 NEW ) # version in project()
project( ToolDAQ VERSION 1.4.7 )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/src/Scarab/cmake )
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
include( PackageBuilder )

pbuilder_prepare_project()

# ToolDAQ CMake files
# list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
# include( ToolDAQ )


#################
# ToolDAQ options #
#################

# require C++11
set_option( USE_CPP11 TRUE )

# Build the ToolDAQ executable (also requires ToolDAQ_ENABLE_EXECUTABLES)
option( ToolDAQ_BUILD_ToolDAQ_EXE "Flag to build the ToolDAQ executable; also requires ToolDAQ_ENABLE_EXECUTABLES" ON )

# Build python bindings (requires boost::python)
option( ToolDAQ_ENABLE_PYTHON "Build python bindings (ToolDAQPy)" OFF )

# Add a "Standard" build type
#set (CMAKE_BUILD_TYPE standard)
set (CMAKE_CXX_FLAGS_STANDARD "-O1 -DNDEBUG -DSTANDARD" CACHE STRING "Flags used by the compiler during standard builds.")
set (CMAKE_C_FLAGS_STANDARD "-O1 -DNDEBUG -DSTANDARD" CACHE STRING "Flags used by the compiler during standard builds.")
set (CMAKE_EXE_LINKER_FLAGS_STANDARD "" CACHE STRING "Flags used by the linker during standard builds.")
set (CMAKE_MODULE_LINKER_FLAGS_STANDARD "" CACHE STRING "Flags used by the linker during standard builds.")
set (CMAKE_SHARED_LINKER_FLAGS_STANDARD "" CACHE STRING "Flags used by the linker during standard builds.")
mark_as_advanced(CMAKE_CXX_FLAGS_STANDARD CMAKE_C_FLAGS_STANDARD CMAKE_EXE_LINKER_FLAGS_STANDARD CMAKE_MODULE_LINKER_FLAGS_STANDARD CMAKE_SHARED_LINKER_FLAGS_STANDARD)


# Single-threading option
option (ToolDAQ_SINGLETHREADED "Flag for running in single-threaded mode" OFF)

# Optional compiler flags
set (FLAG_WARNINGS "" CACHE STRING "Extra warning and error related flags")
set (FLAG_WARNING_LEVEL "NORMAL" CACHE STRING "Valid values are NONE(-w), NORMAL(), MORE(-Wall), MOST(-Wall -Wextra)")
set (FLAG_WARN_AS_ERROR FALSE CACHE BOOL "Treat all warnings as errors")
mark_as_advanced(FLAG_WARNINGS)

# ToolDAQ_process_options()
  

######################
# ToolDAQ dependencies #
######################

SET (CPPZMQ_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
pbuilder_add_submodule( cppzmq src/vendor/cppzmq )
SET (CPPZMQ_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
find_package(cppzmq)

########
# Scarab
########

# pbuilder_add_submodule( Scarab Scarab/library )

# this is needed for anything that wants to read or write JSON files
# get_directory_property( RAPIDJSON_FILE_BUFFER_SIZE DIRECTORY Scarab/library DEFINITION RAPIDJSON_FILE_BUFFER_SIZE )
# set( RAPIDJSON_FILE_BUFFER_SIZE ${RAPIDJSON_FILE_BUFFER_SIZE} PARENT_SCOPE )

#######
# Boost
#######

# Boost (1.46 required for filesystem version 3)
list (APPEND Boost_COMPONENTS date_time filesystem iostreams program_options serialization system thread)
if (ToolDAQ_ENABLE_PYTHON)
    list(APPEND Boost_COMPONENTS python)
endif (ToolDAQ_ENABLE_PYTHON)
find_package (Boost 1.46.0 REQUIRED COMPONENTS ${Boost_COMPONENTS})
# make sure dynamic linking is assumed for all boost libraries
add_definitions (-DBOOST_ALL_DYN_LINK)
include_directories (${Boost_INCLUDE_DIRS})
pbuilder_add_ext_libraries (${Boost_LIBRARIES})

# python deps
if (ToolDAQ_ENABLE_PYTHON)
    include (PythonPackage)
    python_package_find_python( 2.7 )
endif (ToolDAQ_ENABLE_PYTHON)


###############
# Build ToolDAQ #
###############

# include_directories (BEFORE 
#     ${PROJECT_SOURCE_DIR}/Library/Utility
#     ${PROJECT_SOURCE_DIR}/Library/Data
#     ${PROJECT_SOURCE_DIR}/Library/Processor
#     ${PROJECT_SOURCE_DIR}/Library/IO
#     ${PROJECT_SOURCE_DIR}/Library/Application
# )


# #############
# # ToolDAQ
# #############

# # # subdirectories
include_directories (BEFORE
    ${PROJECT_SOURCE_DIR}/DataModel
    ${PROJECT_SOURCE_DIR}/src/Logging
    ${PROJECT_SOURCE_DIR}/src/ServiceDiscovery
    ${PROJECT_SOURCE_DIR}/src/Store
    ${PROJECT_SOURCE_DIR}/src/Tool
    ${PROJECT_SOURCE_DIR}/src/ToolChain
    ${PROJECT_SOURCE_DIR}/UserTools/DummyTool
    ${PROJECT_SOURCE_DIR}/UserTools/Factory
    ${PROJECT_SOURCE_DIR}/UserTools/Logger
    ${PROJECT_SOURCE_DIR}/UserTools/ServiceAdd
    ${PROJECT_SOURCE_DIR}/vendor/cppzmq
#     ${PROJECT_SOURCE_DIR}/apps
#     # ${PROJECT_SOURCE_DIR}/include
#     ${PROJECT_SOURCE_DIR}/library/applications
#     ${PROJECT_SOURCE_DIR}/library/core
#     ${PROJECT_SOURCE_DIR}/library/misc
)

add_subdirectory (DataModel)
add_subdirectory (src/Logging)
add_subdirectory (src/ServiceDiscovery)
add_subdirectory (src/Store)
add_subdirectory (src/Tool)
add_subdirectory (src/ToolChain)
add_subdirectory (UserTools/DummyTool)
add_subdirectory (UserTools/Factory)
add_subdirectory (UserTools/Logger)
add_subdirectory (UserTools/ServiceAdd)
# add_subdirectory (Tools/progress-cpp)
# # add_subdirectory (src)
# add_subdirectory (library/applications)
# add_subdirectory (library/core)
# add_subdirectory (library/misc)
# add_subdirectory (apps)


# add_subdirectory( Library )
# if (ToolDAQ_ENABLE_EXECUTABLES)
#     add_subdirectory( Executables/Validation )
# endif (ToolDAQ_ENABLE_EXECUTABLES)

pbuilder_variables_for_parent()

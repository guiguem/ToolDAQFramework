# Minimum cmake verison 3.1 required for the variable CMAKE_CXX_STANDARD
cmake_minimum_required (VERSION 3.1)

#########
# setup #
#########

cmake_policy( SET CMP0048 NEW ) # version in project()
project( ToolDAQFramework VERSION 2.3 )

list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
list( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/src/vendor/cppzmq )
include( PackageBuilder )

pbuilder_prepare_project()

########################
# options #
########################


set ( Scarab_BUILD_CODEC_JSON OFF )
set ( Scarab_BUILD_CODEC_YAML TRUE )
set ( Scarab_BUILD_PARAM TRUE )
set ( Scarab_BUILD_AUTHENTICATION OFF )
set ( Scarab_ENABLE_EXECUTABLES OFF )

########################
# dependencies #
########################

# pbuilder_add_submodule( cppzmq src/vendor/libzmq )
SET (CPPZMQ_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
pbuilder_add_submodule( cppzmq src/vendor/cppzmq )
SET (CPPZMQ_BUILD_TESTS OFF CACHE INTERNAL "" FORCE)
find_package(cppzmq)
# pbuilder_add_submodule( cppzmq src/vendor/libzmq )
# pbuilder_add_submodule( cppzmq src/vendor/cppzmq )

# find_package(cppzmq)

######
# Doxygen
######

option (TOOLDAQ_BUILD_DOC "Build doxygen documentation" OFF)

if (TOOLDAQ_BUILD_DOC)
# Require dot, treat the other components as optional
    find_package(Doxygen
                REQUIRED dot
                OPTIONAL_COMPONENTS mscgen dia)
endif(TOOLDAQ_BUILD_DOC)

######
# ROOT
######

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT REQUIRED COMPONENTS MathCore RIO Hist Tree Net TreePlayer Minuit2)
include_directories(${CMAKE_SOURCE_DIR} ${ROOT_INCLUDE_DIRS})
add_definitions(${ROOT_CXX_FLAGS})

######
# ROOT
######

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})
find_package(ROOT 6.00 COMPONENTS MathCore RIO Hist Tree Net TreePlayer Minuit2)
pbuilder_add_ext_libraries (${ROOT_LIBRARIES})
include_directories (${ROOT_INCLUDE_DIR})

######
# BOOST
######

# Boost (1.46 required for filesystem version 3)
list (APPEND Boost_COMPONENTS date_time filesystem iostreams program_options serialization system thread)
# python optional
if (Katydid_USE_PYTHON)
    list(APPEND Boost_COMPONENTS python)
endif (Katydid_USE_PYTHON)
#find_package (Boost 1.46.0 REQUIRED COMPONENTS date_time filesystem program_options system thread)
find_package (Boost 1.46.0 REQUIRED COMPONENTS ${Boost_COMPONENTS})
# make sure dynamic linking is assumed for all boost libraries
add_definitions (-DBOOST_ALL_DYN_LINK)
include_directories (${Boost_INCLUDE_DIRS})
pbuilder_add_ext_libraries (${Boost_LIBRARIES})

#############
# ToolDAQ
#############

# # subdirectories
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

# #######################
# installation config #
#######################

pbuilder_install_config_files()
pbuilder_variables_for_parent()

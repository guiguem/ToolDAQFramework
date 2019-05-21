# CMakeLists.txt for src/exe
# Author: M. Guigue
# Created: Mar 6, 2019

# add_library(master_library_Rainette SHARED
#     dummy.cpp
# )

set( lib_dependencies 
    # ServiceDiscovery
    ToolChain
    DummyTool
    # master_library
    # Wrenches
    # ToolChainFactory
)

set( main_exe
    NodeDaemon
    RemoteControl
)
# Allows us to disable the main exe when using ToolDAQ as a submodule
if (ToolDAQ_BUILD_MAIN_EXE)
    list(APPEND main_exe main)
endif(ToolDAQ_BUILD_MAIN_EXE)

pbuilder_executables( main_exe lib_dependencies )




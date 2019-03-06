# CMakeLists.txt for src/exe
# Author: M. Guigue
# Created: Mar 6, 2019

set( lib_dependencies 
    ServiceDiscovery
    ToolChain
)

set( main_exe
    main
    NodeDaemon
    RemoteControl
)

pbuilder_executables( main_exe lib_dependencies )


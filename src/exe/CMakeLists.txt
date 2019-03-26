# CMakeLists.txt for src/exe
# Author: M. Guigue
# Created: Mar 6, 2019

set( lib_dependencies 
    # ServiceDiscovery
    ToolChain
    DummyTool
    Wrenches
    # ToolChainFactory
)

set( main_exe
    main
    # test
    # NodeDaemon
    # RemoteControl
)

pbuilder_executables( main_exe lib_dependencies )


set( lib_dependencies 
    # ServiceDiscovery
    # ToolChain
    # DummyTool
    ToolChainFactory
    Wrenches
)

set( test_exe
    # main
    test
    # NodeDaemon
    # RemoteControl
)
# pbuilder_executables( test_exe lib_dependencies)


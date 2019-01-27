
# set( ToolDAQ_HEADERS
#     Store/BoostStore.h
#     Store/PointerWrapper.h
#     Store/.h
#     Store/Store.h
#     Tool/Tool.h
#     ToolChain/ToolChain.h )

# set( ToolDAQ_SOURCES 
#     Store/BoostStore.cpp
#     Store/Store.cpp
#     ToolChain/ToolChain.cpp )
set( dir ${CMAKE_CURRENT_SOURCE_DIR} )

MESSAGE( STATUS ${ToolDAQ_HEADERS})

set( ToolDAQ_HEADERS ${ToolDAQ_HEADERS}
    ${dir}/ServiceDiscovery.h
    PARENT_SCOPE )

set( ToolDAQ_SOURCES ${ToolDAQ_SOURCES}
    ${dir}/ServiceDiscovery.cpp
    PARENT_SCOPE )

MESSAGE( STATUS ${ToolDAQ_HEADERS})

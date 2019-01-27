
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

set( ToolDAQ_HEADERS ${ToolDAQ_HEADERS}
    ${dir}/Logging.h
    PARENT_SCOPE )

set( ToolDAQ_SOURCES ${ToolDAQ_SOURCES}
    ${dir}/Logging.cpp
    PARENT_SCOPE )
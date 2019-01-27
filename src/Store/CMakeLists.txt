
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
    ${dir}/BoostStore.h
    ${dir}/PointerWrapper.h
    ${dir}/SerialisableObject.h
    ${dir}/Store.h
    PARENT_SCOPE )

set( ToolDAQ_SOURCES ${ToolDAQ_SOURCES}
    ${dir}/BoostStore.cpp
    ${dir}/Store.cpp
    PARENT_SCOPE )
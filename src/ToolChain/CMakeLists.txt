# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( TOOLCHAIN_DICT_HEADERFILES
    ToolChain.h
)

set( TOOLCHAIN_HEADERFILES
    ${TOOLCHAIN_DICT_HEADERFILES}
)

set( TOOLCHAIN_SOURCEFILES
    ToolChain.cpp
)


set (TOOLCHAIN_DEP_LIBRARIES
 BaseDataModel
 BaseFactory
 Logging
 ServiceDiscovery
 Store
#  cppzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( ToolChain TOOLCHAIN_SOURCEFILES TOOLCHAIN_DEP_LIBRARIES )
pbuilder_install_headers( ${TOOLCHAIN_HEADERFILES} )


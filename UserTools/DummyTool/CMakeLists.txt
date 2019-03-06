# CMakeLists for DummyTool
# Author: M. Guigue
# Date: Jan 15, 2019


set( DUMMYTOOL_DICT_HEADERFILES
    DummyTool.h
)

set( DUMMYTOOL_HEADERFILES
    ${DUMMYTOOL_DICT_HEADERFILES}
)

set( DUMMYTOOL_SOURCEFILES
    DummyTool.cpp
)


set (DUMMYTOOL_DEP_LIBRARIES
 BaseDataModel
 Store
#  cppzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( DummyTool DUMMYTOOL_SOURCEFILES DUMMYTOOL_DEP_LIBRARIES )
pbuilder_install_headers( ${DUMMYTOOL_HEADERFILES} )


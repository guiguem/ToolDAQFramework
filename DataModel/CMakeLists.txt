# CMakeLists for DataModel
# Author: M. Guigue
# Date: Jan 15, 2019


set( BASEDM_DICT_HEADERFILES
    DataModel.h
)

set( BASEDM_HEADERFILES
    ${BASEDM_DICT_HEADERFILES}
)

set( BASEDM_SOURCEFILES
    DataModel.cpp
)


set (BASEDM_DEP_LIBRARIES
 Store
#  cppzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( BaseDataModel BASEDM_SOURCEFILES BASEDM_DEP_LIBRARIES )
pbuilder_install_headers( ${BASEDM_HEADERFILES} )


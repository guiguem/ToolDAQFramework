# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( SERVICEADD_DICT_HEADERFILES
    ServiceAdd.h
)

set( SERVICEADD_HEADERFILES
    ${SERVICEADD_DICT_HEADERFILES}
)

set( SERVICEADD_SOURCEFILES
    ServiceAdd.cpp
)


set (SERVICEADD_DEP_LIBRARIES
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

pbuilder_library( ServiceAdd SERVICEADD_SOURCEFILES SERVICEADD_DEP_LIBRARIES )
pbuilder_install_headers( ${SERVICEADD_HEADERFILES} )


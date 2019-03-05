# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( STORE_DICT_HEADERFILES
    Store.h
    PointerWrapper.h
    BoostStore.h
)

set( STORE_HEADERFILES
    ${STORE_DICT_HEADERFILES}
)

set( STORE_SOURCEFILES
    Store.cpp
    BoostStore.cpp
)


set (STORE_DEP_LIBRARIES
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( Store STORE_SOURCEFILES STORE_DEP_LIBRARIES )
pbuilder_install_headers( ${STORE_HEADERFILES} )


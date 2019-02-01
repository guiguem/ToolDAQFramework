# CMakeLists for  Core
# Author: N. Oblath
# Date: Jan 15, 2018


set( LOGGER_DICT_HEADERFILES
    Logger.h
)

set( LOGGER_HEADERFILES
    ${LOGGER_DICT_HEADERFILES}
)

set( LOGGER_SOURCEFILES
    Logger.cpp
)


set (LOGGER_DEP_LIBRARIES
 BaseDataModel
 Store
 cppzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( Logger LOGGER_SOURCEFILES LOGGER_DEP_LIBRARIES )
pbuilder_install_headers( ${LOGGER_HEADERFILES} )


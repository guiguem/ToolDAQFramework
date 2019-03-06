# CMakeLists for Logging
# Author: M. Guigue
# Date: Jan 15, 2019


set( LOGGING_DICT_HEADERFILES
    Logging.h
)

set( LOGGING_HEADERFILES
    ${LOGGING_DICT_HEADERFILES}
)

set( LOGGING_SOURCEFILES
    Logging.cpp
)


set (LOGGING_DEP_LIBRARIES
 Store
#  libzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( Logging LOGGING_SOURCEFILES LOGGING_DEP_LIBRARIES )
pbuilder_install_headers( ${LOGGING_HEADERFILES} )


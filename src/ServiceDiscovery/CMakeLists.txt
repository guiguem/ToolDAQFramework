# CMakeLists for ServiceDiscovery
# Author: M. Guigue
# Date: Jan 15, 2019


set( SERVICE_DISCOVERY_DICT_HEADERFILES
    ServiceDiscovery.h
)

set( SERVICE_DISCOVERY_HEADERFILES
    ${SERVICE_DISCOVERY_DICT_HEADERFILES}
)

set( SERVICE_DISCOVERY_SOURCEFILES
    ServiceDiscovery.cpp
)


set (SERVICE_DISCOVERY_DEP_LIBRARIES
 Store
#  libzmq
)

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( ServiceDiscovery SERVICE_DISCOVERY_SOURCEFILES SERVICE_DISCOVERY_DEP_LIBRARIES )
pbuilder_install_headers( ${SERVICE_DISCOVERY_HEADERFILES} )


# CMakeLists for  ToolChain
# Author: M. Guigue
# Date: Jan 15, 2019


set( FACTORY_DICT_HEADERFILES
    Factory.h
    ToolBox.h
)

set( FACTORY_HEADERFILES
    ${FACTORY_DICT_HEADERFILES}
)

set( FACTORY_SOURCEFILES
    Factory.cpp
    ToolBox.cpp
)


set (FACTORY_DEP_LIBRARIES
)
MESSAGE (STATUS "kdsfjhqdfknsdfijksnfbvushdfjkdhoivsjdfhjkdf,vjsldfkvsdf ${FACTORY_HEADERFILES}" )

# set( STORE_LINKDEF_HEADERFILE LinkDef/ CoreLinkDef.h )
# set( STORE_SOURCEFILES ${STORE_SOURCEFILES} ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict.cxx )
# set( STORE_DICT_PCMFILE ${CMAKE_CURRENT_BINARY_DIR}/ CoreDict_rdict.pcm )

##################################################

# ROOT_GENERATE_DICTIONARY(  CoreDict ${STORE_DICT_HEADERFILES} LINKDEF ${STORE_LINKDEF_HEADERFILE} )
# pbuilder_install_files( ${LIB_INSTALL_DIR} ${STORE_DICT_PCMFILE} )

pbuilder_library( Factory FACTORY_SOURCEFILES FACTORY_DEP_LIBRARIES )
pbuilder_install_headers( ${FACTORY_HEADERFILES} )


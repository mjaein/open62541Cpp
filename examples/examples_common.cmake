cmake_minimum_required (VERSION 3.9)
project (${APPNAME})

#set(CMAKE_INSTALL_PREFIX /usr/local)
add_definitions( -DUA_LOGLEVEL=100 )

# Add the Open62541 includes
include_directories( ../../include )

# Add Open62541 libraries
find_library(OPEN62541 Open62541Cpp ${CMAKE_INSTALL_PREFIX}/lib)
add_executable(${APPNAME} ${SOURCES})
target_link_libraries (${APPNAME} ${OPEN62541})

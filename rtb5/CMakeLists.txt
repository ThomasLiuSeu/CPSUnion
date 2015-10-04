#cmake file for project wikigraph
#author:>-qian wang
#created:>--2013/06/01

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

SET(CMAKE_C_COMPILER "gcc") 
SET (CMAKE_CXX_COMPILER "gcc")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11  -g -ftest-coverage -fprofile-arcs")

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

PROJECT(rtb5)

SET(BASE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

SET(EXECUTABLE_OUTPUT_PATH ${BASE_PATH}/bin)

SET(LIBRARY_OUTPUT_PATH ${BASE_PATH}/lib)

SET(CMAKE_INCLUDE_PATH ${BASE_PATH})

SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH ON)

LINK_DIRECTORIES(/usr/include /usr/local/include  ${BASE_PATH}/lib)

FIND_PATH(MYSQL_INCLUDE_DIR  
  NAMES mysql.h  
  PATHS /usr/include/ /usr/local/include/  
)  
  
# Finally the library itself  
find_library(MYSQL_LIBRARY  
  NAMES mysqlclient 
  PATHS /usr/lib/ /usr/local/lib/ 
) 

find_library(BOOST_LIBRARY  
  NAMES boost_system 
  PATHS /usr/lib/ /usr/local/lib/ 
)  

find_library(BOOST_LIBRARY  
  NAMES boost_filesystem 
  PATHS /usr/lib/ /usr/local/lib/ 
)  

SUBDIRS(./proto)

SUBDIRS(./src)











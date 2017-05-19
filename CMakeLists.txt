cmake_minimum_required(VERSION 2.6)

project(Muduo)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "release")
endif()

if(NOT MUDUO_PATH)
  set(MUDUO_PATH "/home/$ENV{USER}/build/${CMAKE_BUILD_TYPE}-install")
endif()

set(CXX_FLAGS
 -g
 # -DVALGRIND
 # -DMUDUO_STD_STRING
 -Wall
 -Wextra
 # -m32
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 # -MMD
 # -std=c++0x
 -rdynamic
 )
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

find_path(Muduo_INCLUDE_DIR muduo "${MUDUO_PATH}/include")
find_path(Muduo_LIBRARY_DIR libmuduo_net.a "${MUDUO_PATH}/lib")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} ${Muduo_LIBRARY_DIR})
message(STATUS ${Muduo_INCLUDE_DIR})
message(STATUS ${Muduo_LIBRARY_DIR})

include_directories(${Muduo_INCLUDE_DIR})
find_library(muduo_base muduo_base)
find_library(muduo_net muduo_net)
message(STATUS ${muduo_base})
message(STATUS ${muduo_net})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR})


SET(SRC_DIR ../src)

############################################################################
add_executable(echo1 ${SRC_DIR}/echo1/echo1.cpp)
target_link_libraries(echo1 ${muduo_net})
target_link_libraries(echo1 ${muduo_base})
target_link_libraries(echo1 pthread rt)

############################################################################

SET(ECHO2_SRC ${SRC_DIR}/echo2/echo2.cpp ${SRC_DIR}/echo2/echoserver.cpp)
add_executable(echo2 ${ECHO2_SRC})
target_link_libraries(echo2 ${muduo_net})
target_link_libraries(echo2 ${muduo_base})
target_link_libraries(echo2 pthread rt)

############################################################################

SET(DAYTIME_SRC ${SRC_DIR}/daytime/daytime_main.cpp ${SRC_DIR}/daytime/daytime.cpp)
add_executable(daytime ${DAYTIME_SRC})
target_link_libraries(daytime ${muduo_net})
target_link_libraries(daytime ${muduo_base})
target_link_libraries(daytime pthread rt)

###########################################################################

SET(CHAT_CLIENT_SRC ${SRC_DIR}/chat/client.cpp)
SET(CHAT_SERVER_SRC ${SRC_DIR}/chat/server.cpp)
add_executable(chat_client ${CHAT_CLIENT_SRC})
add_executable(chat_server ${CHAT_SERVER_SRC})
target_link_libraries(chat_server ${muduo_net})
target_link_libraries(chat_server ${muduo_base})
target_link_libraries(chat_server pthread rt)
target_link_libraries(chat_client ${muduo_net})
target_link_libraries(chat_client ${muduo_base})
target_link_libraries(chat_client pthread rt)

###########################################################################

SET(DISCARD_SRC ${SRC_DIR}/discard/discard_main.cpp ${SRC_DIR}/discard/discard.cpp)
add_executable(discard ${DISCARD_SRC})
target_link_libraries(discard ${muduo_net})
target_link_libraries(discard ${muduo_base})
target_link_libraries(discard pthread rt)

###########################################################################

SET(FILETRANSFER_SRC ${SRC_DIR}/filetransfer/download1.cpp)
add_executable(filetransfer ${FILETRANSFER_SRC})
target_link_libraries(filetransfer ${muduo_net})
target_link_libraries(filetransfer ${muduo_base})
target_link_libraries(filetransfer pthread rt)

###########################################################################

SET(TIME_SRC ${SRC_DIR}/time/time_main.cpp ${SRC_DIR}/time/time.cpp)
add_executable(time ${TIME_SRC})
target_link_libraries(time ${muduo_net})
target_link_libraries(time ${muduo_base})
target_link_libraries(time pthread rt)

###########################################################################

SET(TIMECLIENT_SRC ${SRC_DIR}/timeclient/timeclient_main.cpp ${SRC_DIR}/timeclient/timeclient.cpp)
add_executable(timeclient ${TIMECLIENT_SRC})
target_link_libraries(timeclient ${muduo_net})
target_link_libraries(timeclient ${muduo_base})
target_link_libraries(timeclient pthread rt)

###########################################################################

SET(ALLINONE_SRC ${SRC_DIR}/allinone/allinone_main.cpp
    ${SRC_DIR}/discard/discard.cpp
    ${SRC_DIR}/time/time.cpp
    ${SRC_DIR}/daytime/daytime.cpp
    ${SRC_DIR}/echo2/echoserver.cpp)

add_executable(allinone ${ALLINONE_SRC})
target_link_libraries(allinone ${muduo_net})
target_link_libraries(allinone ${muduo_base})
target_link_libraries(allinone pthread rt)


cmake_minimum_required(VERSION 3.10)
project(boost_acio_example)

set(CMAKE_CXX_STANDARD 17)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)
SET(Boost_NO_BOOST_CMAKE ON)

FIND_PACKAGE(Threads)
FIND_PACKAGE(Boost REQUIRED COMPONENTS filesystem locale system thread regex)

IF (Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF (Boost_FOUND)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_executable(boost_acio_example
        main.cpp
        reply.cpp
        reply.h
        request.h
        request_handler.cpp
        request_handler.h
        mime_types.cpp
        mime_types.h
        connection.cpp
        connection.h
        server.cpp
        server.h
        request_parser.cpp
        request_parser.h
        header.h)

IF (UNIX)
    TARGET_LINK_LIBRARIES(boost_acio_example ${Boost_LIBRARIES} Threads::Threads)
ELSE (UNIX)
    TARGET_LINK_LIBRARIES(boost_acio_example ${Boost_LIBRARIES} Threads::Threads ws2_32 wsock32)
ENDIF (UNIX)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
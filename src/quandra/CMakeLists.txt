cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)
include(../../cmake/FindSDL2.cmake)

include_directories(${SDL2_INCLUDE_DIR})

set(q_inc 
	qa_common.h
	qa_platform.h
	qa_compiler.h
	qa_types.h
	qa_application.h
	qa_window.h)

set(q_src 
	qa_application.c
	qa_window.c)

add_library(quandra SHARED ${q_inc} ${q_src})

set_target_properties(quandra PROPERTIES 
					  DEFINE_SYMBOL QUANDRA_BUILD
					  C_STANDARD 11
					  C_VISIBILITY_PRESET hidden)
if(UNIX)
	target_link_libraries(quandra pthread)
endif()

target_link_libraries(quandra ${SDL2_LIBRARY})

source_group("src" FILES ${q_inc} ${q_src})

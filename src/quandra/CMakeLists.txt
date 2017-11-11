cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

find_package(ICU COMPONENTS uc io i18n REQUIRED)
include_directories(${ICU_INCLUDE_DIRS})

set(platform "sdl2" CACHE STRING "Game engine backend")
include(platforms/quandra_platforms.cmake)

add_definitions(-DU_CHARSET_IS_UTF8=1)

set(q_inc 
	qa_common.h
	qa_platform.h
	qa_platform_impl.h
	qa_compiler.h
	qa_types.h
	qa_application.h
	qa_window.h
	qa_gamestate.h
	qa_gamestatemgr.h
	qa_events.h
	qa_io.h)

set(q_src 
	qa_application.c
	qa_window.c
	qa_gamestatemgr.c
	qa_io.c)

add_library(quandra SHARED ${q_inc} ${q_src})

set_target_properties(quandra PROPERTIES 
					  DEFINE_SYMBOL QUANDRA_BUILD
					  C_STANDARD 11
					  C_VISIBILITY_PRESET hidden
					  POSITION_INDEPENDENT_CODE ON)

target_link_libraries(quandra ${platform}_platform ${ICU_LIBRARIES})

source_group("src" FILES ${q_inc} ${q_src})

cmake_minimum_required (VERSION 3.15)
project (HPL)

set(HPL_VERSION_MAJOR 1)
set(HPL_VERSION_MINOR 0)

find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/../OALWrapper/include
	${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/include
	${CMAKE_SOURCE_DIR}/libs/angelscript-sdk-2.37.0/angelscript/include
	${CMAKE_SOURCE_DIR}/libs/Cg-Toolkit/mac/include
	${CMAKE_SOURCE_DIR}/libs/newton-dynamics/newton-3.14/sdk/dgNewton
)
file(GLOB_RECURSE all_sources
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/*.c
)
# Removed Sources
file(GLOB_RECURSE to_remove_all
    win32.cpp
    Video*Theora.cpp
    )
list(REMOVE_ITEM all_sources
    ${to_remove_all})
list(REMOVE_DUPLICATES all_sources)

add_library(HPL STATIC ${all_sources})

add_library(Newton STATIC IMPORTED)
set_target_properties(Newton PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/lib/linux/libNewton.a)

add_library(angelscript STATIC IMPORTED)
set_target_properties(angelscript PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/lib/linux/libangelscript.a)

add_library(SDLmain STATIC IMPORTED)
set_target_properties(SDLmain PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../dependencies/lib/linux/libSDLmain.a)

pkg_search_module(GLEW REQUIRED glew)

find_path(GLEW_INCLUDE_DIR GL/glew.h PATHS /opt/homebrew/include)
find_library(GLEW_LIBRARY GLEW PATHS /opt/homebrew/lib)

include_directories(${GLEW_INCLUDE_DIR})
link_libraries(${GLEW_LIBRARY})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

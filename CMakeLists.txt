cmake_minimum_required (VERSION 3.18.4)
project (sib_examples)
set (CMAKE_EXPORT_COMPILE_COMMANDS=ON)

find_package(SDL2 REQUIRED)

add_executable(basic)

target_sources(basic PRIVATE
	sib/sib.cpp
	sib/sib_readfile.cpp
	examples/basic/basic.cpp
)

target_include_directories(basic PRIVATE
	sib
	${SDL2_INCLUDE_DIRS}
)

target_link_libraries(basic PRIVATE ${SDL2_LIBRARIES})

add_executable(readfile)

target_sources(readfile PRIVATE
	sib/sib.cpp
	sib/sib_readfile.cpp
	examples/readfile/readfile.cpp
)

target_include_directories(readfile PRIVATE
	sib
	${SDL2_INCLUDE_DIRS}
)

target_link_libraries(readfile PRIVATE ${SDL2_LIBRARIES})

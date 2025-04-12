
cmake_minimum_required (VERSION 3.8)

add_executable (hysim 
	"utils.cpp" 
	"utils.h" 
	"instruction.h"
	"instruction.cpp" 
	"assembler.cpp" 
	"assembler.h" 
	"executor.cpp" 
	"executor.h" 
	"main.cpp"
	)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET hysim PROPERTY CXX_STANDARD 17 -O0 -g -Wall)
  #target_compile_options(hysim PRIVATE $<$<CONFIG:Debug>:-O0 -g -Wall>)
  # target_compile_options(hycsim PRIVATE $<$<CONFIG:Debug>:-O0 -g -Wall> $<$<CONFIG:Release>:-O2 -Wall> $<$<CONFIG:RelWithDebInfo>:-O2 -g>)
endif()


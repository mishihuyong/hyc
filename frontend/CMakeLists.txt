cmake_minimum_required (VERSION 3.8)

add_executable (hycc 
	"lex.yy.c" 
	"y.tab.h" 
	"y.tab.c"
	)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  #set_property(TARGET hycc PROPERTY CXX_STANDARD 17)
  #target_compile_options(hycc PRIVATE $<$<CONFIG:Debug>:-O0 -g -Wall>)
  # target_compile_options(hycsim PRIVATE $<$<CONFIG:Debug>:-O0 -g -Wall> $<$<CONFIG:Release>:-O2 -Wall> $<$<CONFIG:RelWithDebInfo>:-O2 -g>)
endif()
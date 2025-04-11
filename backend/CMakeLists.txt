
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (hycsim 
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
  set_property(TARGET hycsim PROPERTY CXX_STANDARD 20)
  # target_compile_options(hycsim PRIVATE $<$<CONFIG:Debug>:-O0 -g -Wall> $<$<CONFIG:Release>:-O2 -Wall> $<$<CONFIG:RelWithDebInfo>:-O2 -g>)
endif()

# TODO: 如有需要，请添加测试并安装目标。

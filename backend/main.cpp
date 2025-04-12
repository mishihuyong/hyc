/**
 * @file main.h
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright huyong Copyright (c) 2025
 * 
 */

 #include <iostream>

#include "assembler.h"
#include "executor.h"

bool Sim(const std::string& cfile) {
	Assembler asmer;
	if (!asmer.Assemble(cfile)) {
		std::cerr << "[err]: Assemble " << cfile << " failed" << std::endl;
		return false;
	}
	auto code = asmer.GetCode();
	code.Print();

	Executor executor;
	var ret;
	if (!executor.Run(code, ret)) {
		std::cerr << "[err]: Execute " << cfile << " failed" << std::endl;
		return false;
	}
	return true;
}

void test_epxr() {
	if (!Sim("/mnt/d/work/prj/hyc/backend/test/test_epxr.asm")) {
		//static_assert(false);
	}
	static_assert(true);
}

void test_func() {
	std::string path;
	// path = "/mnt/d/work/prj/hyc/backend/test/test_func.asm";
	path = "d:/work/prj/hyc/backend/test/test_func.asm";
	if (!Sim(path)) {
		//static_assert(false);
	}
	static_assert(true);
}

int main() {
	//test_epxr();
	test_func();
	return 0;
}
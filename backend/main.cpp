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

bool Sim(const std::string& cfile, bool do_main, bool do_exit) {
	Assembler asmer;
	if (!asmer.Assemble(cfile, do_main, do_exit)) {
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
	var exit_code = executor.GetExit();
	std::cout << "**********[exit]: " << exit_code << std::endl;
	return true;
}

void test_epxr() {
	std::string path;
	// path = "/mnt/d/work/prj/hyc/backend/test/test_expr.asm";
	path = "d:/work/prj/hyc/backend/test/test_expr.asm";
	if (!Sim(path, false, false)) {
		//static_assert(false);
	}
	static_assert(true);
}

void test_func() {
	std::string path;
	// path = "/mnt/d/work/prj/hyc/backend/test/test_func.asm";
	path = "d:/work/prj/hyc/backend/test/test_func.asm";
	if (!Sim(path, true, true)) {
		//static_assert(false);
	}
	static_assert(true);
}

void test_ifelse() {
	std::string path;
	// path = "/mnt/d/work/prj/hyc/backend/test/test_ifelse.asm";
	path = "d:/work/prj/hyc/backend/test/test_ifelse.asm";
	if (!Sim(path, true, true)) {
		//static_assert(false);
	}
	static_assert(true);
}

void test_while() {
	std::string path;
	// path = "/mnt/d/work/prj/hyc/backend/test/test_while.asm";
	path = "d:/work/prj/hyc/backend/test/test_while.asm";
	if (!Sim(path, true, true)) {
		//static_assert(false);
	}
	static_assert(true);
}

int main() {
	//test_epxr();
	test_func();
	test_ifelse();
	test_while();
	return 0;
}
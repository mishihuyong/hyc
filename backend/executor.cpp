/**
 * @file executor.cpp
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright huyong Copyright (c) 2025
 * 
 */

#include "executor.h"

#include <iostream>

bool Executor::Run(const Code& code, var& ret) {
	cpu_.Clear();
	while (cpu_.ip < code.irs.size()) {
		InstructionType instType = code.irs[cpu_.ip].instruction;
		if (instType == InstructionType::NIL || instType == InstructionType::MAX) {
			std::cerr << "[err]: Instruction is error." << std::endl;
			return false;
		}
		auto& funcName = instructionInfos[static_cast<size_t>(instType)].str;
		auto& func = instructionInfos[static_cast<size_t>(instType)].func;
		
		std::cout << "********prev********" << std::endl;
		cpu_.Print();

		std::cout << "********run:" << code.irs[cpu_.ip].label << "\t" <<
			funcName << "\t" << code.irs[cpu_.ip].argument << std::endl;

		// instruction arg's func is null
		if (func != nullptr && !func(cpu_, code)) {
			std::cerr << "[err]: Exec " << code.irs[cpu_.ip].label << " " << funcName << " " <<
				code.irs[cpu_.ip].argument << " failed." << std::endl;
			return false;
		}
		
		std::cout << "********post********" << std::endl;
		cpu_.Print();

		cpu_.ip += 1;
	}

	return true;
}

//static bool Add(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Sub(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Mul(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Div(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Mod(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Neg(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Not(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool And(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Or(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool BitAnd(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool BitOr(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool BitXor(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool CmpEq(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool CmpNe(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool CmpGt(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool CmpLt(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool CmpGe(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool CmpLe(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Push(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Pop(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Jmp(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Jz(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Var(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Call(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Ret(Cpu& cpu, const Code& code) {
//	return true;
//}
//
//static bool Exit(Cpu& cpu, const Code& code) {
//	return true;
//}
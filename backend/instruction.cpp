/**
 * @file instrution.cpp
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10
 *
 * @copyright huyong Copyright (c) 2025
 *
 */

#include "instruction.h"

#include <iostream>
#include <cassert>
#include "utils.h"

void Code::Print() {
	std::cout << "IRs:" << std::endl; 
	for (size_t i = 0; i < irs.size(); i++) {
		std::cout << "\t" << i << ": " << 
			irs[i].label << "\t" << 
			instructionInfos[static_cast<size_t>(irs[i].instruction)].str << "\t" << 
			irs[i].argument << std::endl;
	}

	std::cout << "Label map:" << std::endl;
	for (const auto &it : labelMap) {
		std::cout << "\t" << it.first << ": " << it.second << ",\t";
	}
	std::cout << std::endl;

	std::cout << "FuncName map:" << std::endl;
	for (const auto &it : funcMap) {
		std::cout << "\t" << it.first << ": " << it.second << ",\t";
	}
	std::cout << std::endl;

}

void Cpu::Print() {

	std::cout << "[IP]: " << ip << std::endl;

	std::cout << "Stack:" << std::endl; 
	for (size_t i = 0; i < stack.size(); i++) {
		std::cout << "\t" << i << ": " << 
		statckItemStrMap[stack[i].type] << "\t" <<
		stack[i].data << std::endl;
	}

	if (varMap == nullptr) {
		return;
	}
	std::cout << "Var map: " << reinterpret_cast<uint64_t>(varMap) << std::endl;	
	for (const auto &it : *varMap) {
		std::cout << "\t" << it.first << ": " << it.second << ",\t";
	}
	std::cout << std::endl;
}

InstructionType GetInstructionType(const std::string& instructionStr) {
	for (const auto& it : instructionInfos) {
		if (it.str == instructionStr) {
			return it.type;
		}
	}
	return InstructionType::NIL;
}

bool IsIdentifier(const std::string& ident) {
    if (ident.empty()) {
        return false;
    }
    
    // 检查第一个字符（必须是字母或下划线）
    char firstChar = ident[0];
    if (!(isalpha(firstChar) || firstChar == '_')) {
        return false;
    }
    
    // 检查剩余字符（必须是字母、数字或下划线）
    for (size_t i = 1; i < ident.size(); ++i) {
        char ch = ident[i];
        if (!(isalnum(ch) || ch == '_')) {
            return false;
        }
    }
    
    return true;
}

bool Add(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::ADD);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: Add: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data += right.data;
	cpu.stack.pop_back();
	return true;
}

bool Sub(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::SUB);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: Sub: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data -= right.data;
	cpu.stack.pop_back();
	return true;
}

bool Mul(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::MUL);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: Mul: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data *= right.data;
	cpu.stack.pop_back();
	return true;
}

bool Div(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::DIV);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: Div: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data /= right.data;
	cpu.stack.pop_back();
	return true;
}

bool Mod(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::MOD);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: Mod: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	// TODO: 不光是CONST 还必须是整型数据
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data %= right.data;
	cpu.stack.pop_back();
	return true;
}

bool Neg(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::NEG);

	size_t sz = cpu.stack.size();
	if (sz < 1) {
		std::cerr << "[err]: Neg: stack is not enough." << std::endl;
		return false;
	}
	StackItem& right = cpu.stack[sz - 1];
	right.data = -right.data;
	return true;
}

bool Not(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::NOT);

	size_t sz = cpu.stack.size();
	if (sz < 1) {
		std::cerr << "[err]: Not: stack is not enough." << std::endl;
		return false;
	}
	StackItem& right = cpu.stack[sz - 1];
	right.data = !right.data;
	return true;
}

bool And(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::AND);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: And: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = left.data && right.data;
	cpu.stack.pop_back();
	return true;
}

bool Or(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::OR);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: Or: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = left.data || right.data;
	cpu.stack.pop_back();
	return true;
}

bool BitAnd(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::BITAND);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: BitAnd: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	// TODO: 不光是CONST 还必须是整型数据
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data &= right.data;
	cpu.stack.pop_back();
	return true;
}

bool BitOr(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::BITOR);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: BitOr: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	// TODO: 不光是CONST 还必须是整型数据
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data |= right.data;
	cpu.stack.pop_back();
	return true;
}

bool BitXor(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::BITXOR);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: BitXor: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	// TODO: 不光是CONST 还必须是整型数据
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data ^= right.data;
	cpu.stack.pop_back();
	return true;
}

bool CmpEq(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::CMPEQ);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: CmpEq: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = (left.data == right.data);
	cpu.stack.pop_back();
	return true;
}

bool CmpNe(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::CMPNE);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: CmpNe: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = (left.data != right.data);
	cpu.stack.pop_back();
	return true;
}

bool CmpGt(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::CMPGT);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: CmpGt: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = (left.data > right.data);
	cpu.stack.pop_back();
	return true;
}

bool CmpLt(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::CMPLT);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: CmpLt: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = (left.data < right.data);
	cpu.stack.pop_back();
	return true;
}

bool CmpGe(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::CMPGE);
	if (cpu.stack.size() < 2) {
		std::cerr << "[err]: CmpGe: stack is not enough." << std::endl;
		return false;
	}

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = (left.data >= right.data);
	cpu.stack.pop_back();
	return true;
}

bool CmpLe(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::CMPLE);

	size_t sz = cpu.stack.size();
	if (sz < 2) {
		std::cerr << "[err]: CmpLe: stack is not enough." << std::endl;
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];

	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data = (left.data <= right.data);
	cpu.stack.pop_back();
	return true;
}

// if CONST directly push, else if VAR found value then push 
bool Push(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::PUSH);
	assert(cpu.varMap != nullptr);
	assert(cpu.ip < code.irs.size());

	const auto& arg = code.irs[cpu.ip].argument;
	var value;
	try {
		value = std::stoll(arg, nullptr);
	} catch (const std::invalid_argument& ex) {
		try {
			const auto& si = cpu.stack.at(cpu.varMap->at(arg));
			if (si.type != StackItemType::CONST) {
				std::cerr << "[err]: Push: Cannot push uninitialed value " << arg << std::endl;
				return false;
			}
			value = si.data;
		} catch (const std::out_of_range& ex) {
			std::cerr << "[err]: Push: Undefined variable " << arg << " " << ex.what() << std::endl;
			return false;
		}	
	} catch (const std::out_of_range& ex) {
		std::cerr << "[err]: Push: Too long to stoll: " << arg << " " << ex.what() << std::endl;
		return false;
	}
	cpu.stack.push_back({ StackItemType::CONST, value });

	return true;
}

// Assign value and pop
bool Pop(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::POP);
	assert(cpu.varMap != nullptr);
	assert(cpu.ip < code.irs.size());
	if (cpu.stack.size() == 0) {
		std::cerr << "[err]: Pop: stack is not enough." << std::endl;
		return false;
	}

	const auto& src = cpu.stack.back();
	if (src.type != StackItemType::CONST) {
		std::cerr << "[err]: Pop: Cannot pop non-number value to variable" << std::endl;
		return false;
	}
	const auto& arg = code.irs[cpu.ip].argument;
	try {
		// Assign value;
		auto& dst = cpu.stack.at(cpu.varMap->at(arg));
		dst.type = StackItemType::CONST;
		dst.data = src.data;
	} catch (const std::out_of_range& ex) {
		std::cerr << "[err]: Pop: Undefined variable " << arg << " " << ex.what() << std::endl;
		return false;
	}
	cpu.stack.pop_back();

	return true;
}

bool Jmp(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::JMP);

	auto& label = code.irs[cpu.ip].argument;
	try {
		// here we set eip just befor the label,
		// and when back to run(), we do eip += 1
		cpu.ip = code.labelMap.at(label) - 1;
	} catch (const std::out_of_range& ex) {
		std::cerr << "[err]: Jmp: Wrong label " << label << " " << ex.what() << std::endl;
		return false;
	}

	return true;
}

bool Jz(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::JZ);

	if (cpu.stack.size() == 0) {
		std::cerr << "[err]: Jz: stack is not enough." << std::endl;
		return false;
	}
	if (cpu.stack.back().type != StackItemType::CONST) {
		std::cerr << "[err]: Jz: stack top data type is not CONST." << std::endl;
		return false;
	}

	const auto& label = code.irs[cpu.ip].argument;
	try {
		// here we set eip just befor the label,
		// and when back to run(), we do eip += 1
		auto new_ip = code.labelMap.at(label) - 1;

		if (cpu.stack.back().data == 0LL) {
			cpu.stack.pop_back();
			cpu.ip = new_ip;
		}
	} catch (const std::out_of_range& ex) {
		std::cerr << "[err]: Jmp: Wrong label " << label << " " << ex.what() << std::endl;
		return false;
	}

	return true;
}

// var a, b: push UNINIT , push UNINIT
bool Var(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::VAR);
	assert(cpu.varMap != nullptr);

	const auto& arg = code.irs[cpu.ip].argument;
	std::vector<std::string> args;
	Utils::Split(arg, ",", args);
	for (const auto& it : args) {
		if (!IsIdentifier(it) || cpu.varMap->count(it) == 1) {
			std::cerr << "[err]: Var: Wrong variant name " << it << std::endl;
			return false;
		}
		(*cpu.varMap)[it] = cpu.stack.size();

		cpu.stack.push_back({ StackItemType::UNINIT, 0LL });
	}

	return true;
}

// call func_name
// 'FUNC @func_name'  arg a,b. this arg's func is null. new_ip 
// 'FUNC @func_name'  push a,b. this push is not null . new_ip - 1
// but 
// arg's func will continue. so can be  new_ip - 1
bool Call(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::CALL);
	assert(cpu.varMap != nullptr);

	const auto& callee_func_name = code.irs[cpu.ip].argument;
	uint64_t callee_ip = 0ULL;
	try {	
		callee_ip = code.funcMap.at(callee_func_name);
	} catch (const std::out_of_range& ex) {
		std::cerr << "[err]: Call: Undefined function " << callee_func_name << " " << ex.what() << std::endl;
		return false;
	}
	assert(callee_ip < code.irs.size());
	std::vector<std::string> args;
	if (code.irs[callee_ip].instruction == InstructionType::ARG) {
		Utils::Split(code.irs[callee_ip].argument, ",", args);
	}
	auto new_var_map = new std::map<const std::string, var>;
	uint64_t arg_stack_idx = cpu.stack.size() - args.size();
	for (const auto& arg : args) {
		if (!IsIdentifier(arg) || new_var_map->count(arg) == 1) {
			std::cerr << "[err]: Call: Wrong arg name " << arg << std::endl;
			return false;
		}
		(*new_var_map)[arg] = arg_stack_idx++;
	}
	
	// reserve caller's info
	cpu.stack.push_back({ StackItemType::ARG_SIZE, static_cast<var>(args.size()) });
	cpu.stack.push_back({ StackItemType::IP, static_cast<var>(cpu.ip) });
	cpu.stack.push_back({ StackItemType::VAR_MAP, reinterpret_cast<var>(cpu.varMap) });

	// set callee's info
	cpu.varMap = new_var_map;

	// 由于 arg指令的函数为空，所以 这里-1 和不-1 效果是一样的。-1后空run一圈 啥也不做，只是ip+1
	//cpu.ip = args.size() > 0 ? callee_ip : callee_ip - 1;

	cpu.ip = callee_ip - 1; // arg's func is null, will continue. so all func can be  new_ip - 1
	
	return true;
}


static bool ClearCallee(Cpu& cpu) {
	size_t idx = cpu.stack.size() - 1;
	while (idx < cpu.stack.size() && cpu.stack[idx].type != StackItemType::VAR_MAP) {
		--idx;
	}
	if (idx >= cpu.stack.size()) {
		std::cerr << "[err]: Ret: stack is not enough." << std::endl;
		return false;
	}
	auto caller_var_map = reinterpret_cast<std::map<const std::string, var>*>(cpu.stack[idx].data);
	if (caller_var_map == nullptr) {
		std::cerr << "[err]: Ret: caller var map is not null." << std::endl;
		return false;
	}
	delete cpu.varMap;
	cpu.varMap = caller_var_map;

	--idx;
	if (idx >= cpu.stack.size()) {
		std::cerr << "[err]: Ret: stack is not enough." << std::endl;
		return false;
	}
	if (cpu.stack[idx].type != StackItemType::IP) {
		std::cerr << "[err]: Ret: caller var map is not null." << std::endl;
		return false;
	}
	cpu.ip = static_cast<uint64_t>(cpu.stack[idx].data);

	--idx;
	if (idx >= cpu.stack.size()) {
		std::cerr << "[err]: Ret: stack is not enough." << std::endl;
		return false;
	}
	if (cpu.stack[idx].type != StackItemType::ARG_SIZE) {
		std::cerr << "[err]: Ret: caller var map is not null." << std::endl;
		return false;
	}

	idx -= cpu.stack[idx].data;
	if (idx >= cpu.stack.size()) {
		std::cerr << "[err]: Ret: stack is not enough." << std::endl;
		return false;
	}

	cpu.stack.erase(cpu.stack.begin() + idx, cpu.stack.end());
	return true;
}

// clear self
bool Ret(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::RET);
	assert(cpu.varMap != nullptr);

	const auto& arg = code.irs[cpu.ip].argument;

	StackItem ret_si{ StackItemType::UNINIT, 0ll };
	if (arg.empty()) {
	} else if (arg == "~") {
		ret_si = cpu.stack.back();
	} else {
		try {
			// CONST
			auto value = std::stoll(arg, nullptr);
			ret_si.type = StackItemType::CONST;
			ret_si.data = value;
		} catch (const std::invalid_argument& ex) {
			// VAR
			try {
				ret_si = cpu.stack.at(cpu.varMap->at(arg));
			} catch (const std::out_of_range& ex) {
				std::cerr << "[err]: Ret: Undefined variable " << arg <<
					" " << ex.what() << std::endl;
				return false;
			}
		} catch (const std::out_of_range& ex) {
			std::cerr << "[err]: Ret: Too long to stoll: " << arg <<
				" " << ex.what() << std::endl;
			return false;
		}
	}

	if (!ClearCallee(cpu)) {
		return false;
	}

	//if (ret_si.type != StackItemType::CONST) {
	//	std::cerr << "[err]: Ret: Undefined variable " << arg << std::endl;
	//	return false;
	//}

	cpu.stack.push_back(ret_si);

	return true;
}

bool Exit(Cpu& cpu, const Code& code) {
	assert(code.irs[cpu.ip].instruction == InstructionType::EXIT);
	assert(cpu.varMap != nullptr);

	const auto& arg = code.irs[cpu.ip].argument;

	StackItem ret_si{ StackItemType::UNINIT, 0ll };
	if (arg.empty()) {
	} else if (arg == "~") {
		ret_si = cpu.stack.back();
	} else {
		try {
			// CONST
			auto value = std::stoll(arg, nullptr);
			ret_si.type = StackItemType::CONST;
			ret_si.data = value;
		} catch (const std::invalid_argument& ex) {
			// VAR
			try {
				ret_si = cpu.stack.at(cpu.varMap->at(arg));
			} catch (const std::out_of_range& ex) {
				std::cerr << "[err]: Ret: Undefined variable " << arg <<
					" " << ex.what() << std::endl;
				return false;
			}
		} catch (const std::out_of_range& ex) {
			std::cerr << "[err]: Ret: Too long to stoll: " << arg <<
				" " << ex.what() << std::endl;
			return false;
		}
	}

	//if (ret_si.type != StackItemType::CONST) {
	//	std::cerr << "[err]: Ret: Undefined variable " << arg << std::endl;
	//	return false;
	//}

	cpu.exitCode = ret_si.data;
	std::cout << "[EXIT]: " << cpu.exitCode << std::endl;
	cpu.exit = true;
	// exit(cpu.exitCode); // if not exit, dead cycle
	return true;
}
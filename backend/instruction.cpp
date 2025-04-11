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

InstructionType GetInstructionType(const std::string& instructionStr) {
	for (const auto &it : instructionInfos) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data += right.data;

	return true;
}

bool Sub(Cpu& cpu, const Code& code) {
	size_t sz = cpu.stack.size();
	if (sz < 2) {
		return false;
	}
	StackItem& left = cpu.stack[sz - 2];
	const StackItem& right = cpu.stack[sz - 1];
	if (left.type != StackItemType::CONST || right.type != StackItemType::CONST) {
		return false;
	}

	left.data -= right.data;
	return true;
}

bool Mul(Cpu& cpu, const Code& code) {
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 1) {
		return false;
	}
	StackItem& right = cpu.stack[sz - 1];
	right.data = -right.data;
	return true;
}

bool Not(Cpu& cpu, const Code& code) {
	size_t sz = cpu.stack.size();
	if (sz < 1) {
		return false;
	}
	StackItem& right = cpu.stack[sz - 1];
	right.data = !right.data;
	return true;
}

bool And(Cpu& cpu, const Code& code) {
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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
	size_t sz = cpu.stack.size();
	if (sz < 2) {
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

bool Push(Cpu& cpu, const Code& code) {
	return true;
}

bool Pop(Cpu& cpu, const Code& code) {
	return true;
}

bool Jmp(Cpu& cpu, const Code& code) {
	return true;
}

bool Jz(Cpu& cpu, const Code& code) {
	return true;
}

bool Var(Cpu& cpu, const Code& code) {
	return true;
}

bool Call(Cpu& cpu, const Code& code) {
	return true;
}

bool Ret(Cpu& cpu, const Code& code) {
	return true;
}

bool Exit(Cpu& cpu, const Code& code) {
	return true;
}
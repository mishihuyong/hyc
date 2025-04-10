/**
 * @file instrution.h
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright huyong Copyright (c) 2025
 * 
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <vector>
#include <map>
#include <array>

enum class InstructionType : int {
    NIL = 0x0,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    NEG,
    NOT,
    AND,
    OR,
    BITAND,
    BITOR,
    BITXOR,
    CMPEQ,
    CMPNE,
    CMPGT,
    CMPLT,
    CMPGE,
    CMPLE,
    PUSH,
    POP,
    JMP,
    JZ,
    VAR,
    CALL,
    RET,
    EXIT,
    MAX
};

struct InstructionInfo {
    InstructionType type;
    std::string_view str;
};

inline std::array<InstructionInfo, static_cast<size_t>(InstructionType::MAX)> instructionInfos = {
    InstructionInfo{ InstructionType::NIL, "" },
    InstructionInfo{ InstructionType::ADD, "add" },
    InstructionInfo{ InstructionType::SUB, "sub" },
    InstructionInfo{ InstructionType::MUL, "mul" },
    InstructionInfo{ InstructionType::DIV, "div" },
    InstructionInfo{ InstructionType::MOD, "mod" },
    InstructionInfo{ InstructionType::NEG, "neg" },
    InstructionInfo{ InstructionType::NOT, "not" },
    InstructionInfo{ InstructionType::AND, "and" },
    InstructionInfo{ InstructionType::OR, "or" },
    InstructionInfo{ InstructionType::BITAND, "bitand" },
    InstructionInfo{ InstructionType::BITOR, "bitor" },
    InstructionInfo{ InstructionType::BITXOR, "bitxor" },
    InstructionInfo{ InstructionType::CMPEQ, "cmpeq" },
    InstructionInfo{ InstructionType::CMPNE, "cmpne" },
    InstructionInfo{ InstructionType::CMPGT, "cmpgt" },
    InstructionInfo{ InstructionType::CMPLT, "cmplt" },
    InstructionInfo{ InstructionType::CMPGE, "cmpge" },
    InstructionInfo{ InstructionType::CMPLE, "cmple" },
    InstructionInfo{ InstructionType::PUSH, "push" },
    InstructionInfo{ InstructionType::POP, "pop" },
    InstructionInfo{ InstructionType::JMP, "jmp" },
    InstructionInfo{ InstructionType::JZ, "jz" },
    InstructionInfo{ InstructionType::VAR, "var" },
    InstructionInfo{ InstructionType::CALL, "call" },
    InstructionInfo{ InstructionType::RET, "ret" },
    InstructionInfo{ InstructionType::EXIT, "exit" },
};

struct Ir {
    std::string label;
    InstructionType instruction;
    std::string argument;
};

using var = long long;

struct Code {
    std::vector<Ir> irs;
    std::map<std::string, var> labelMap;
    std::map<std::string, var> funcMap;
};

enum class StackItemType {
    CONST,
    VAR,
    PARAM_SIZE,
    IP,
    VAR_MAP
};

struct StackItem {
    StackItemType type;
    var data;
};

struct Cpu {
    Cpu() : varMap{ new std::map<std::string, var> } {
    }

    inline void Clear() {
        if (varMap != nullptr) {
            delete varMap;
            varMap = nullptr;
        }
        ip = 0;
        stack.clear();
    }

    std::map<std::string, var>* varMap;
    uint64_t ip{ 0 };
    std::vector<var> stack;
};

inline bool IsId(const std::string_view& str) {
    return true;
}

#endif
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

#include <functional>
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
    ARG,
    VAR,
    CALL,
    RET,
    EXIT,
    MAX
};

struct IntermediateRepresentation {
    std::string label;
    InstructionType instruction;
    std::string argument;
};

using var = long long;

struct Code {
    void Clear() {
        irs.clear();
        labelMap.clear();
        funcMap.clear();
    }

    void Print();
    std::vector<IntermediateRepresentation> irs;
    std::map<std::string, var> labelMap;
    std::map<std::string, var> funcMap;
};

enum class StackItemType : int {
    CONST = 0,
    VAR,
    ARG_SIZE,
    IP,
    VAR_MAP
};

inline std::map<StackItemType, const char* const> statckItemStrMap = {
    { StackItemType::CONST, "CONST" },
    { StackItemType::VAR, "VAR" },
    { StackItemType::ARG_SIZE, "ARG_SIZE" },
    { StackItemType::IP, "IP" },
    { StackItemType::VAR_MAP, "VAR_MAP" }
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

    void Print();

    std::map<std::string, var>* varMap;
    uint64_t ip{ 0 };
    std::vector<StackItem> stack;
};

struct InstructionInfo {
    InstructionType type;
    const char* const str;
    std::function<bool(Cpu& cpu, const Code& code)> func;
};

bool Add(Cpu& cpu, const Code& code);
bool Sub(Cpu& cpu, const Code& code);
bool Mul(Cpu& cpu, const Code& code);
bool Div(Cpu& cpu, const Code& code);
bool Mod(Cpu& cpu, const Code& code);
bool Neg(Cpu& cpu, const Code& code);
bool Not(Cpu& cpu, const Code& code);
bool And(Cpu& cpu, const Code& code);
bool Or(Cpu& cpu, const Code& code);
bool BitAnd(Cpu& cpu, const Code& code);
bool BitOr(Cpu& cpu, const Code& code);
bool BitXor(Cpu& cpu, const Code& code);
bool CmpEq(Cpu& cpu, const Code& code);
bool CmpNe(Cpu& cpu, const Code& code);
bool CmpGt(Cpu& cpu, const Code& code);
bool CmpLt(Cpu& cpu, const Code& code);
bool CmpGe(Cpu& cpu, const Code& code);
bool CmpLe(Cpu& cpu, const Code& code);
bool Push(Cpu& cpu, const Code& code);
bool Pop(Cpu& cpu, const Code& code);
bool Jmp(Cpu& cpu, const Code& code);
bool Jz(Cpu& cpu, const Code& code);
bool Var(Cpu& cpu, const Code& code);
bool Call(Cpu& cpu, const Code& code);
bool Ret(Cpu& cpu, const Code& code);
bool Exit(Cpu& cpu, const Code& code);

// Do not use MAX as item, just as array size.
inline const std::array<InstructionInfo, static_cast<size_t>(InstructionType::MAX)> instructionInfos = {
    InstructionInfo{ InstructionType::NIL, "", nullptr },
    InstructionInfo{ InstructionType::ADD, "add", Add },
    InstructionInfo{ InstructionType::SUB, "sub", Sub },
    InstructionInfo{ InstructionType::MUL, "mul", Mul },
    InstructionInfo{ InstructionType::DIV, "div", Div },
    InstructionInfo{ InstructionType::MOD, "mod", Mod },
    InstructionInfo{ InstructionType::NEG, "neg", Neg },
    InstructionInfo{ InstructionType::NOT, "not", Not },
    InstructionInfo{ InstructionType::AND, "and", And },
    InstructionInfo{ InstructionType::OR, "or", Or },
    InstructionInfo{ InstructionType::BITAND, "bitand", BitAnd },
    InstructionInfo{ InstructionType::BITOR, "bitor", BitOr },
    InstructionInfo{ InstructionType::BITXOR, "bitxor", BitXor },
    InstructionInfo{ InstructionType::CMPEQ, "cmpeq", CmpEq },
    InstructionInfo{ InstructionType::CMPNE, "cmpne", CmpNe },
    InstructionInfo{ InstructionType::CMPGT, "cmpgt", CmpGt },
    InstructionInfo{ InstructionType::CMPLT, "cmplt", CmpLt },
    InstructionInfo{ InstructionType::CMPGE, "cmpge", CmpGe},
    InstructionInfo{ InstructionType::CMPLE, "cmple", CmpLe },
    InstructionInfo{ InstructionType::PUSH, "push", Push },
    InstructionInfo{ InstructionType::POP, "pop", Pop },
    InstructionInfo{ InstructionType::JMP, "jmp", Jmp },
    InstructionInfo{ InstructionType::JZ, "jz", Jz },
    InstructionInfo{ InstructionType::ARG, "arg", nullptr },
    InstructionInfo{ InstructionType::VAR, "var", Var },
    InstructionInfo{ InstructionType::CALL, "call", Call },
    InstructionInfo{ InstructionType::RET, "ret", Ret },
    InstructionInfo{ InstructionType::EXIT, "exit", Exit }
};

InstructionType GetInstructionType(const std::string& instructionStr);

bool IsIdentifier(const std::string& ident);

#endif
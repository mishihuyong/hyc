/**
 * @file executor.h
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright huyong Copyright (c) 2025
 * 
 */

#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <functional>

#include "instruction.h"

class Executor {
public:
    bool Run(const Code& code, var& ret);


    static bool Add(Cpu& cpu, const Code& code);
    static bool Sub(Cpu& cpu, const Code& code);
    static bool Mul(Cpu& cpu, const Code& code);
    static bool Div(Cpu& cpu, const Code& code);
    static bool Mod(Cpu& cpu, const Code& code);
    static bool Neg(Cpu& cpu, const Code& code);
    static bool Not(Cpu& cpu, const Code& code);
    static bool And(Cpu& cpu, const Code& code);
    static bool Or(Cpu& cpu, const Code& code);
    static bool BitAnd(Cpu& cpu, const Code& code);
    static bool BitOr(Cpu& cpu, const Code& code);
    static bool BitXor(Cpu& cpu, const Code& code);
    static bool CmpEq(Cpu& cpu, const Code& code);
    static bool CmpNe(Cpu& cpu, const Code& code);
    static bool CmpGt(Cpu& cpu, const Code& code);
    static bool CmpLt(Cpu& cpu, const Code& code);
    static bool CmpGe(Cpu& cpu, const Code& code);
    static bool CmpLe(Cpu& cpu, const Code& code);
    static bool Push(Cpu& cpu, const Code& code);
    static bool Pop(Cpu& cpu, const Code& code);
    static bool Jmp(Cpu& cpu, const Code& code);
    static bool Jz(Cpu& cpu, const Code& code);
    static bool Var(Cpu& cpu, const Code& code);
    static bool Call(Cpu& cpu, const Code& code);
    static bool Ret(Cpu& cpu, const Code& code);
    static bool Exit(Cpu& cpu, const Code& code);

    static inline std::map<InstructionType, std::function<bool(Cpu& cpu, const Code& code)>> instructionOpts = {
        { InstructionType::ADD, Add },
        { InstructionType::SUB, Sub },
        { InstructionType::MUL, Mul },
        { InstructionType::DIV, Div },
        { InstructionType::MOD, Mod },
        { InstructionType::NEG, Neg },
        { InstructionType::NOT, Not },
        { InstructionType::AND, And },
        { InstructionType::OR, Or },
        { InstructionType::BITAND, BitAnd },
        { InstructionType::BITOR, BitOr },
        { InstructionType::BITXOR, BitXor },
        { InstructionType::CMPEQ, CmpEq },
        { InstructionType::CMPNE, CmpNe },
        { InstructionType::CMPGT, CmpGt },
        { InstructionType::CMPLT, CmpLt },
        { InstructionType::CMPGE, CmpGe },
        { InstructionType::CMPLE, CmpLe },
        { InstructionType::PUSH, Push },
        { InstructionType::POP, Pop },
        { InstructionType::JMP, Jmp },
        { InstructionType::JZ, Jz },
        { InstructionType::VAR, Var },
        { InstructionType::CALL, Call },
        { InstructionType::RET, Ret },
        { InstructionType::EXIT, Exit },
    };

private:
    Cpu cpu_;
};

#endif
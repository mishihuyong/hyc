/**
 * @file assembler.h
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright huyong Copyright (c) 2025
 * 
 */

#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include "instruction.h"

class Assembler {
public:
    bool Assemble(const std::string& filePath, bool doMain = true, bool doExit = false);

    inline void Reset() {
        Clear();
    }

    inline void Clear() {
        code_.Clear();
    }

    inline const Code& GetCode() {
        return code_;
    }

private:
    bool CheckLabel(const std::string& label);
    Code code_;
};

 #endif
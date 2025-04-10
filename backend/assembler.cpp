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

#include "assembler.h"

#include <fstream>
#include <iostream>

#include "utils.h"

bool Assembler::Assemble(const std::string& filePath, bool hasMain) {

    std::ifstream file{ filePath };
    if (!file) {
        std::cerr << "[err]: Read " << filePath << " failed!" << std::endl;
        return false;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::string_view strippedLine = TrimView(line);

        std::string_view label;
        std::string_view instAndArg;
        bool sep = Partition(strippedLine, ":", label, instAndArg);
        if (sep) {
            std::string_view currentLabel;
        }
    }
    
    return true;
}

bool Assembler::CheckLabel(const std::string_view& label) {
    return true;
}
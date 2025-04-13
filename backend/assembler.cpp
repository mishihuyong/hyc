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
#include <string>

#include "utils.h"

const constexpr char *ENDFUNC_STR = "ENDFUNC";
constexpr size_t ENDFUNC_STR_SIZE = 7;
const constexpr char *ARG_STR = ".arg";
const constexpr char *VAR_STR = ".var";
constexpr size_t ARG_VAR_STR_SIZE = 4;

bool Assembler::Assemble(const std::string& filePath, bool doMain, bool doExit) {
    std::ifstream file{ filePath };
    if (!file) {
        std::cerr << "[err]: Read " << filePath << " failed!" << std::endl;
        return false;
    }

    if (doMain) {
        // use main if has main
        code_.irs.push_back({ "", InstructionType::CALL, "main" });
    }
    if (doExit) {
        // use exit if need exiting process
        code_.irs.push_back({ "", InstructionType::EXIT, "~" });
    }
    
    std::string label;
    std::string line;
    while (std::getline(file, line)) {
        std::string strippedLine = Utils::Trim(line);
        if (strippedLine.empty() || strippedLine[0] == ';' || strippedLine[0] == '#') {
            continue;
        }

        std::string currentLabel;
        std::string instAndArg;
        bool sep = Utils::Partition(strippedLine, ":", currentLabel, instAndArg);
        if (sep && 
            currentLabel.find("\"") == std::string::npos && 
            currentLabel.find("'") == std::string::npos) {
            // Process label of not ENDFUNC 
            if (!CheckLabel(currentLabel)) {
                std::cerr << "[err]: Wrong label: " << label << std::endl;
                return false;
            }
            // concat all label, because of the label hasing same ip
            label = label.empty() ? currentLabel : label + "," + currentLabel;
            if (instAndArg.empty() || instAndArg[0] == ';' || instAndArg[0] == '#') {
                // Ignore empty string and comment and to process label if concat
                continue;
            }
        } else if (strippedLine.size() >= ENDFUNC_STR_SIZE && 
            strippedLine.substr(0, ENDFUNC_STR_SIZE) == ENDFUNC_STR) {
            // Process label of ENDFUNC
            // concat all label, because of  the label hasing same ip
            label = label.empty() ? ENDFUNC_STR : label + "," + ENDFUNC_STR;

            // add ret instruction
            instAndArg = instructionInfos[static_cast<size_t>(InstructionType::RET)].str;
        } else {
            instAndArg = strippedLine;
        }

        std::string instStr;
        std::string arg;
        sep = Utils::Partition(instAndArg, " ", instStr, arg);
        // > ARG_VAR_STR_SIZE, because of  funcName.arg or funcName.var
        if (instStr.size() > ARG_VAR_STR_SIZE &&
            (instStr.substr(instStr.size() - ARG_VAR_STR_SIZE, ARG_VAR_STR_SIZE) == ARG_STR ||
            instStr.substr(instStr.size() - ARG_VAR_STR_SIZE, ARG_VAR_STR_SIZE) == VAR_STR)) {
            // .arg to arg  .var to var        
            instStr = instStr.substr(instStr.size() - ARG_VAR_STR_SIZE + 1, ARG_VAR_STR_SIZE);
        }

        InstructionType instType;
        instType = GetInstructionType(instStr);
        if (instType != InstructionType::NIL && instType != InstructionType::MAX) {
            code_.irs.push_back({ label, instType, arg });
        }
        
        label = "";
    }
    
    return true;
}

bool Assembler::CheckLabel(const std::string& label) {
    if (label.empty()) {
        return false;
    }
    std::string funcLabel;
    std::string funcName;
    bool sep = Utils::Partition(label, " @", funcLabel, funcName);
    if (sep) {
        // label of funcName
        if (funcLabel != "FUNC" ||
            !IsIdentifier(funcName) ||
            code_.funcMap.count(funcName) == 1) {
            return false;
        } else {
            code_.funcMap[funcName] = code_.irs.size();
        }
    } else {
        // label of not funcName
        if (!IsIdentifier(label) ||
            code_.funcMap.count(label) == 1 ||
            code_.labelMap.count(label) == 1) {
            return false;
        } else {
            code_.labelMap[label] = code_.irs.size();
        }
    }

    return true;
}
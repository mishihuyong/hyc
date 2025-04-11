/**
 * @file utils.h
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright huyong Copyright (c) 2025
 * 
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

namespace Utils {

// std::string_view TrimView(std::string_view s, const char* t = " \t\n\r\f\v");

std::string Trim(std::string str);

void FastTrim(std::string& s);

bool Partition(const std::string& str, const std::string& delimiter,
    std::string& first, std::string& second);

void Splite(const std::string& str, const std::string& delimiter, 
    std::vector<std::string>& tokens);

} // namespace Utils

#endif

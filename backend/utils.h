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
#include <string_view>
#include <vector>

std::string_view TrimView(std::string_view s, const char* t = " \t\n\r\f\v");

void FastTrim(std::string& s);

bool Partition(const std::string_view& str, const std::string_view& delimiter,
    std::string_view& first, std::string_view& second);

void Splite(const std::string_view& str, const std::string_view& delimiter, 
    std::vector<std::string_view>& tokens);

#endif

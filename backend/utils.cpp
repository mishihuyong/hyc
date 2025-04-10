/**
 * @file utils.cpp
 * @author Hu Yong (huyongcode@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-10
 * 
 * @copyright huyong Copyright (c) 2025
 * 
 */

 #include "utils.h"

#include <algorithm>

std::string_view TrimView(std::string_view s, const char* t) {
    s.remove_prefix(std::min(s.find_first_not_of(t), s.size()));
    s.remove_suffix(s.size() - std::min(s.find_last_not_of(t) + 1, s.size()));
    return s;
}

void FastTrim(std::string& s) {
     if (s.empty()) return;

     // 查找第一个非空白字符
     size_t start = 0;
     while (start < s.size() && std::isspace(s[start])) {
         ++start;
     }

     // 查找最后一个非空白字符
     size_t end = s.size();
     while (end > start && std::isspace(s[end - 1])) {
         --end;
     }

     // 原地修改字符串
     if (start > 0 || end < s.size()) {
         s = s.substr(start, end - start);
     }
}

bool Partition(const std::string_view& str, const std::string_view& delimiter, 
    std::string_view& first, std::string_view& second) {
    size_t pos = str.find(delimiter);
    if (pos == std::string_view::npos) {
        first = TrimView(str);
        return false;
    }

    first = TrimView(str.substr(0, pos));
    pos += delimiter.size();
    second = TrimView(str.substr(pos, str.size() - pos));
    return true;
}

void Splite(const std::string_view& str, const std::string_view& delimiter, 
    std::vector<std::string_view>& tokens) {
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != std::string_view::npos) {
        tokens.emplace_back(TrimView(str.substr(start, end - start)));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    
    tokens.emplace_back(str.substr(start));
}
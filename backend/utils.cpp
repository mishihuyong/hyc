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

namespace Utils {

// std::string TrimView(std::string s, const char* t) {
//     s.remove_prefix(std::min(s.find_first_not_of(t), s.size()));
//     s.remove_suffix(s.size() - std::min(s.find_last_not_of(t) + 1, s.size()));
//     return s;
// }

void FastTrim(std::string& s) {
     if (s.empty()) return;

     size_t start = 0;
     while (start < s.size() && std::isspace(s[start])) {
         ++start;
     }

     size_t end = s.size();
     while (end > start && std::isspace(s[end - 1])) {
         --end;
     }

     if (start > 0 || end < s.size()) {
         s = s.substr(start, end - start);
     }
}

std::string Trim(std::string str) {
    FastTrim(str);
    return str;
}

bool Partition(const std::string& str, const std::string& delimiter, 
    std::string& first, std::string& second) {
    size_t pos = str.find(delimiter);
    if (pos == std::string::npos) {
        first = Trim(str);
        return false;
    }

    first = Trim(str.substr(0, pos));
    pos += delimiter.size();
    second = Trim(str.substr(pos, str.size() - pos));
    return true;
}

void Split(const std::string& str, const std::string& delimiter, 
    std::vector<std::string>& tokens) {
    size_t start = 0;
    size_t end = str.find(delimiter);
    
    while (end != std::string::npos) {
        tokens.emplace_back(Trim(str.substr(start, end - start)));
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    
    tokens.emplace_back(Trim(str.substr(start)));
}

} // namespace Utils
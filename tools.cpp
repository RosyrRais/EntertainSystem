#include <iostream>
#include "tools.h"
int findNthOccurrence(const std::string& str, char target, int n) {
    int count = 0;
    size_t pos = 0;

    while (count < n && (pos = str.find(target, pos)) != std::string::npos) {
        ++count;
        if (count == n) {
            return pos;
        }
        ++pos; // 移动到下一个字符，以便继续查找
    }

    return -1; // 如果没有找到第n个目标字符，返回-1
}

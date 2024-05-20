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
        ++pos; // �ƶ�����һ���ַ����Ա��������
    }

    return -1; // ���û���ҵ���n��Ŀ���ַ�������-1
}

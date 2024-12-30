#include "../include/solution.h"
#include <string>

std::string solution(const std::string& line, int n, char old_value, char new_value) {
    std::string result = line;
    int occurrence_count = 0;

    if (n <= 0) {
        return result;
    }

    for (char& c : result) {
        if (c == old_value) {
            ++occurrence_count;
            if (occurrence_count % n == 0) {
                c = new_value;
            }
        }
    }

    return result;
}

#include <iostream>
#include "include/solution.h"
#include <string>


int main() {
    std::string line;
    int n;
    char old_value; 
    char new_value;

    std::cin >> line;
    std::cin >> n;
    std::cin >> old_value;
    std::cin >> new_value;

    std::string result = solution(line, n, old_value, new_value);

    std::cout << result << std::endl;

    return 0;
}
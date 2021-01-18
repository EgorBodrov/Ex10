// Copyright 2021 Bodrov Egor

#include <iostream>
#include "postfix.h"

int main() {
    std::string expr1 = "2 + 2 * 2";
    std::string expr2 = "(1 + (5 - 1)) * (2 * 3)";
    std::string expr3 = "15.5 / 3.2 + 1 * (2 + 10 * (10 - 1))";
    std::string expr4 = "5 * (5 - 1) * (4 - 1) * (3 - 1) * (2 - 1)";
    std::string expr5 = "((11.9 - 0.1) * (22.2 + 2.6) - 3) / (2.2 - 3.1 * 0.1)";

    std::cout << infix2postfix(expr1) << std::endl;  
    // 2 2 2 * +
    std::cout << infix2postfix(expr2) << std::endl;
    // 1 5 1 - + 2 3 * *
    std::cout << infix2postfix(expr3) << std::endl;  
    // 15.5 3.2 / 1 2 10 10 1 - * + * +
    std::cout << infix2postfix(expr4) << std::endl;  
    // 5 5 1 - * 4 1 - * 3 1 - * 2 1 - *
    std::cout << infix2postfix(expr5) << std::endl;
    // 11.9 0.1 - 22.2 2.6 + * 3 - 2.2 3.1 0.1 * - /

    return 0;
}

// Copyright 2021 Bodrov Egor

#include "postfix.h"

int priority(char c) {
    switch (c) {
    case '(': return 0;
    case ')': return 1;
    case '+': case '-': return 2;
    case '*': case '/': return 3;
    default: return -1;
    }
}

std::string infix2postfix(std::string infix) {
    MyStack <char> op(400);
    std::string out;
    std::string tmp;
    for (auto c : infix) {
        if (c >= '0' && c <= '9' || c == '.') {
            tmp.push_back(c);
            continue;
        }
        if (!tmp.empty()) {
            out += tmp;
            out.push_back(' ');
            tmp.clear(); 
        }

        int pr = priority(c);
        if (pr == 0 || pr > -1 && op.isEmpty() == true || pr > priority(op.get())) {
            op.push(c);
        } else if (pr == 1) {
            while (op.get() != '(') {
                out.push_back(op.pop());
                out.push_back(' ');
            }
            op.pop();

        } else if (pr > -1) {
            while (op.isEmpty() == false && priority(op.get()) >= pr) {
                out.push_back(op.pop());
                out.push_back(' ');
            }
            op.push(c);
        } 
        
    }
    if (!tmp.empty()) {
        out += tmp;
        out.push_back(' ');
    }
    while (op.isEmpty() == false) {
        out.push_back(op.pop());
        out.push_back(' ');
    }

    return out;
}

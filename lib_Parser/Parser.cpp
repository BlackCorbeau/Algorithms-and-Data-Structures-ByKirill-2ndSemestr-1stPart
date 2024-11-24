// Copyright 2024 Kirill Remizov

#include "../lib_Parser/Parser.h"
#include "../lib_Stack/Stack.h"

bool is_correct(const CString* exp) {
    Stack<char> st;
    const char* mass = exp->data();
    char module_bracket = '\0';
    
    for (size_t i = 0; i < exp->size() + 1; i ++) {
        if (mass[i] == '(' || mass[i] == '[' || mass[i] == '{') {
            st.push(mass[i]);
        } else if (mass[i] == '|') {
            if (module_bracket == '\0') {
                // Встретили открывающую скобку модуля
                module_bracket = '|';
            } else {
                // Встретили закрывающую скобку модуля
                if (module_bracket == '|') {
                    module_bracket = '\0'; // Сбрасываем переменную
                } else {
                    throw std::logic_error("Mismatched brackets found");
                }
            }
        } else if (mass[i] == ')' || mass[i] == ']' || mass[i] == '}') {
            if (st.empty()) {
                throw std::logic_error("Unmatched closing bracket found");
            } else {
                char top = st.top();
                st.pop();
                if ((mass[i] == ')' && top != '(') ||
                    (mass[i] == ']' && top != '[') ||
                    (mass[i] == '}' && top != '{')) {
                    throw std::logic_error("Mismatched brackets found");
                }
            }
        }
    }

    if (!st.empty() || module_bracket != '\0') {
        throw std::logic_error("Unmatched opening bracket found");
    }

    return true;
}

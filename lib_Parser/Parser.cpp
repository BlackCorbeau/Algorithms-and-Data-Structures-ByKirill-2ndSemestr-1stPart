// Copyright 2024 Kirill Remizov

#include "../lib_Parser/Parser.h"
#include "../lib_Stack/Stack.h"

bool is_correct(const CString* exp) {
    Stack<char> st;
    const char* mass = exp->data();
    for (size_t i = 0; i < exp->size() + 1; i ++) {
        if (mass[i] == '(' || mass[i] == '[' || mass[i] == '{') {
            st.push(mass[i]);
        } else if (mass[i] == ')' || mass[i] == ']' || mass[i] == '}') {
            if (st.empty()) {
                st.push(mass[i]);
            } else {
                st.pop();
            }
        }
    }

    if (st.empty()) {
        return true;
    } else if (st.empty() == true &&
    (st.top() == '(' || st.top() == '[' || st.top() == '{')) {
        std::cout << "Your string have unclosed '(' or '[' or '{'";
        return false;
    } else {
        std::cout << "Your string have unclosed ')' or ']' or '}'";
        return false;
    }
}

// Copyright 2024 Kirill Remizov
#pragma once
#ifndef LIB_STACK_LIB_CALCULTOR_HEDER_H_
#define LIB_STACK_LIB_CALCULTOR_HEDER_H_

#include <string>
#include <cmath>
#include "../lib_list/List.h"

enum LexemType {
    BRACKET,
    VARIABLE,
    OPERATION,
    FUNCTION,
    INT_CONST,
    FLOAT_CONST
};

bool is_number(char symbol);
bool is_alpha(char symbol);

class Lexem {
 protected:
    std::string _name;
    LexemType _type;
 public:
    Lexem(std::string name, LexemType type);

    void set_name(std::string name);
    void set_type(LexemType type);

    std::string name() const;
    LexemType type() const;

    friend std::ostream& operator<<(std::ostream& out, const Lexem& lexem);
};

class Expression {
    TList<Lexem> _expression;
    // <what type?> polish_record;
 public:
    explicit Expression(std::string exp);
    //void set_vars_values();
    //void calculate();
    void print();
    void check();

 private:
    void parse(std::string exp);
    void parse_bracket(const std::string& exp, int& curr_pos);
    void parse_variable_or_function(const std::string& exp, int& curr_pos);
    void parse_operation(const std::string& exp, int& curr_pos);
    void parse_number(const std::string& exp, int& curr_pos);
    //void build_polish_record();
};

enum TypeBrackets {
    OPEN,
    CLOSE
};

class FloatConst : public Lexem {
    float _value;
 public:
    explicit FloatConst(std::string exp) : Lexem(exp, FLOAT_CONST) {
        int curr_pos = 0;
        float result = 0;
        while (is_number(exp[curr_pos])) {
            result = result * 10 + (exp[curr_pos] - '0');
            curr_pos++;
        }
        if (exp[curr_pos] == '.') {
            curr_pos++;
            float float_part = 0.0;
            int accuracy = 0;
            while (is_number(exp[curr_pos])) {
                float_part = float_part * 10 + (exp[curr_pos] - '0');
                curr_pos++;
                accuracy++;
            }
            result += float_part * pow(10, -accuracy);
        }
        _value = result;
    }
};

class IntConst : public Lexem {
    int _value;
 public:
    explicit IntConst(std::string name) : Lexem(name, INT_CONST) {
        _value = std::stoi(name);
    }

    int value() const { return _value; }
};

class Bracket : public Lexem {
    TypeBrackets type;
    int priority;
 public:
    explicit Bracket(std::string name) : Lexem(name, BRACKET), priority(0) {
        if (name[0] == '(') {
            type = TypeBrackets::OPEN;
        } else {
            type = TypeBrackets::CLOSE;
        }
    }
    void setPriority(int priority) { this->priority = priority; }
};

class Variable : public Lexem {
    int value;
 public:
    explicit Variable(std::string name) : Lexem(name, VARIABLE), value(0) {}
    void setValue(int value) { this->value = value; }
};

class Operation : public Lexem {
    int priority;
 public:
    explicit Operation(std::string name) : Lexem(name, OPERATION), priority(0) {}
    void setPriority(int priority) { this->priority = priority; }
};

class Function : public Lexem {
    int priority;
 public:
    explicit Function(std::string name) : Lexem(name, FUNCTION), priority(0) {}
    void setPriority(int priority) { this->priority = priority; }
};

#endif  // LIB_STACK_LIB_CALCULTOR_HEDER_H_

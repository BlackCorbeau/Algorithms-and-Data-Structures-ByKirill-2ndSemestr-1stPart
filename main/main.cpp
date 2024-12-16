// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <chrono>
#include "../lib_LStack/LStack.h"
#include "../lib_Stack/Stack.h"


int main() {
    LStack<int> ls;
    Stack<int> s;

    std::cout << "push 1 int el in empy list stack:\n";
    auto startls1 = std::chrono::high_resolution_clock::now();
    ls.push(1000000000);
    auto endls1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1 = endls1 - startls1;
    std::cout << "Time taken: " << durationls1.count() << " milliseconds" << std::endl;

    std::cout << "push 1 int el in empty DMassiv stack:\n";
    auto starts1 = std::chrono::high_resolution_clock::now();
    s.push(1000000000);
    auto ends1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1 = ends1 - starts1;
    std::cout << "Time taken: " << durations1.count() << " milliseconds" << std::endl;

    std::cout << "push int el in 10 elemented list stack:\n";
    for (int i = 0; i < 9; i++) {
        ls.push(1000000000);
    }
    auto startls10 = std::chrono::high_resolution_clock::now();
    ls.push(1000000000);
    auto endls10 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10 = endls10 - startls10;
    std::cout << "Time taken: " << durationls10.count() << " milliseconds" << std::endl;

    std::cout << "push int el in 10 elemented DMassiv stack:\n";
    for (int i = 0; i < 9; i++) {
        s.push(1000000000);
    }
    auto starts10 = std::chrono::high_resolution_clock::now();
    s.push(1000000000);
    auto ends10 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10 = ends10 - starts10;
    std::cout << "Time taken: " << durations10.count() << " milliseconds" << std::endl;

    std::cout << "push int el in 100 elemented list stack:\n";
    for (int i = 0; i < 99; i++) {
        ls.push(1000000000);
    }
    auto startls100 = std::chrono::high_resolution_clock::now();
    ls.push(1000000000);
    auto endls100 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100 = endls100 - startls100;
    std::cout << "Time taken: " << durationls100.count() << " milliseconds" << std::endl;

    std::cout << "push int el in 100 elemented DMassiv stack:\n";
    for (int i = 0; i < 99; i++) {
        s.push(1000000000);
    }
    auto starts100 = std::chrono::high_resolution_clock::now();
    s.push(1000000000);
    auto ends100 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100 = ends100 - starts100;
    std::cout << "Time taken: " << durations100.count() << " milliseconds" << std::endl;

    std::cout << "push int el in 1000 elemented list stack:\n";
    for (int i = 0; i < 999; i++) {
        ls.push(1000000000);
    }
    auto startls1000 = std::chrono::high_resolution_clock::now();
    ls.push(1000000000);
    auto endls1000 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1000 = endls1000 - startls1000;
    std::cout << "Time taken: " << durationls1000.count() << " milliseconds" << std::endl;

    std::cout << "push int el in 1000 elemented DMassiv stack:\n";
    for (int i = 0; i < 999; i++) {
        s.push(1000000000);
    }
    auto starts1000 = std::chrono::high_resolution_clock::now();
    s.push(1000000000);
    auto ends1000 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1000 = ends1000 - starts1000;
    std::cout << "Time taken: " << durations1000.count() << " milliseconds" << std::endl;

    std::cout << "push in 10000 int el list stack:\n";
    for (int i = 0; i < 9999; i++) {
        ls.push(1000000000);
    }
    auto startls10000 = std::chrono::high_resolution_clock::now();
    ls.push(1000000000);
    auto endls10000 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10000 = endls10000 - startls10000;
    std::cout << "Time taken: " << durationls10000.count() << " milliseconds" << std::endl;

    std::cout << "push in 10000 int el DMassiv stack:\n";
    for (int i = 0; i < 9999; i++) {
        s.push(1000000000);
    }
    auto starts10000 = std::chrono::high_resolution_clock::now();
    s.push(1000000000);
    auto ends10000 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10000 = ends10000 - starts10000;
    std::cout << "Time taken: " << durations10000.count() << " milliseconds" << std::endl;

    std::cout << "push in 100000 int el list stack:\n";
    for (int i = 0; i < 99999; i++) {
        ls.push(1000000000);
    }
    auto startls100000 = std::chrono::high_resolution_clock::now();
    ls.push(1000000000);
    auto endls100000 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100000 = endls100000 - startls100000;
    std::cout << "Time taken: " << durationls100000.count() << " milliseconds" << std::endl;

    std::cout << "push in 100000 int el DMassiv stack:\n";
    for (int i = 0; i < 99999; i++) {
        s.push(1000000000);
    }
    auto starts100000 = std::chrono::high_resolution_clock::now();
    s.push(1000000000);
    auto ends100000 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100000 = ends100000 - starts100000;
    std::cout << "Time taken: " << durations100000.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1 int el list stack:\n";
    auto startls1pop = std::chrono::high_resolution_clock::now();
    ls.pop();
    auto endls1pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1pop = endls1pop - startls1pop;
    std::cout << "Time taken: " << durationls1pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1 int el DMassiv stack:\n";
    auto starts1pop = std::chrono::high_resolution_clock::now();
    s.pop();
    auto ends1pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1pop = ends1pop - starts1pop;
    std::cout << "Time taken: " << durations1pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10 int el list stack:\n";
    for (int i = 0; i < 9; i++) {
        ls.pop();
    }
    auto startls10pop = std::chrono::high_resolution_clock::now();
    ls.pop();
    auto endls10pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10pop = endls10pop - startls10pop;
    std::cout << "Time taken: " << durationls10pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10 int el DMassiv stack:\n";
    for (int i = 0; i < 9; i++) {
        s.pop();
    }
    auto starts10pop = std::chrono::high_resolution_clock::now();
    s.pop();
    auto ends10pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10pop = ends10pop - starts10pop;
    std::cout << "Time taken: " << durations10pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100 int el list stack:\n";
    for (int i = 0; i < 99; i++) {
        ls.pop();
    }
    auto startls100pop = std::chrono::high_resolution_clock::now();
    ls.pop();
    auto endls100pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100pop = endls100pop - startls100pop;
    std::cout << "Time taken: " << durationls100pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100 int el DMassiv stack:\n";
    for (int i = 0; i < 99; i++) {
        s.pop();
    }
    auto starts100pop = std::chrono::high_resolution_clock::now();
    s.pop();
    auto ends100pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100pop = ends100pop - starts100pop;
    std::cout << "Time taken: " << durations100pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1000 int el list stack:\n";
    for (int i = 0; i < 999; i++) {
        ls.pop();
    }
    auto startls1000pop = std::chrono::high_resolution_clock::now();
    ls.pop();
    auto endls1000pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1000pop = endls1000pop - startls1000pop;
    std::cout << "Time taken: " << durationls1000pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1000 int el DMassiv stack:\n";
    for (int i = 0; i < 999; i++) {
        s.pop();
    }
    auto starts1000pop = std::chrono::high_resolution_clock::now();
    s.pop();
    auto ends1000pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1000pop = ends1000pop - starts1000pop;
    std::cout << "Time taken: " << durations1000pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10000 int el list stack:\n";
    for (int i = 0; i < 9999; i++) {
        ls.pop();
    }
    auto startls10000pop = std::chrono::high_resolution_clock::now();
    ls.pop();
    auto endls10000pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10000pop = endls10000pop - startls10000pop;
    std::cout << "Time taken: " << durationls10000pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10000 int el DMassiv stack:\n";
    for (int i = 0; i < 9999; i++) {
        s.pop();
    }
    auto starts10000pop = std::chrono::high_resolution_clock::now();
    s.pop();
    auto ends10000pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10000pop = ends10000pop - starts10000pop;
    std::cout << "Time taken: " << durations10000pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100000 int el list stack:\n";
    for (int i = 0; i < 99999; i++) {
        ls.pop();
    }
    auto startls100000pop = std::chrono::high_resolution_clock::now();
    ls.pop();
    auto endls100000pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100000pop = endls100000pop - startls100000pop;
    std::cout << "Time taken: " << durationls100000pop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100000 int el DMassiv stack:\n";
    for (int i = 0; i < 99999; i++) {
        s.pop();
    }
    auto starts100000pop = std::chrono::high_resolution_clock::now();
    s.pop();
    auto ends100000pop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100000pop = ends100000pop - starts100000pop;
    std::cout << "Time taken: " << durations100000pop.count() << " milliseconds" << std::endl;

    s.~Stack();
    ls.~LStack();

    std::cout << "\n";

    LStack<char> lsChar;
    Stack<char> sChar;

    std::cout << "push in 1 char el list stack:\n";
    auto startls1Char = std::chrono::high_resolution_clock::now();
    lsChar.push('a');
    auto endls1Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1Char = endls1Char - startls1Char;
    std::cout << "Time taken: " << durationls1Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 1 char el DMassiv stack:\n";
    auto starts1Char = std::chrono::high_resolution_clock::now();
    sChar.push('a');
    auto ends1Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1Char = ends1Char - starts1Char;
    std::cout << "Time taken: " << durations1Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 10 char el list stack:\n";
    for (int i = 0; i < 9; i++) {
        lsChar.push('a');
    }
    auto startls10Char = std::chrono::high_resolution_clock::now();
    lsChar.push('a');
    auto endls10Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10Char = endls10Char - startls10Char;
    std::cout << "Time taken: " << durationls10Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 10 char el DMassiv stack:\n";
    for (int i = 0; i < 9; i++) {
        sChar.push('a');
    }
    auto starts10Char = std::chrono::high_resolution_clock::now();
    sChar.push('a');
    auto ends10Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10Char = ends10Char - starts10Char;
    std::cout << "Time taken: " << durations10Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 100 char el list stack:\n";
    for (int i = 0; i < 99; i++) {
        lsChar.push('a');
    }
    auto startls100Char = std::chrono::high_resolution_clock::now();
    lsChar.push('a');
    auto endls100Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100Char = endls100Char - startls100Char;
    std::cout << "Time taken: " << durationls100Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 100 char el DMassiv stack:\n";
    for (int i = 0; i < 99; i++) {
        sChar.push('a');
    }
    auto starts100Char = std::chrono::high_resolution_clock::now();
    sChar.push('a');
    auto ends100Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100Char = ends100Char - starts100Char;
    std::cout << "Time taken: " << durations100Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 1000 char el list stack:\n";
    for (int i = 0; i < 999; i++) {
        lsChar.push('a');
    }
    auto startls1000Char = std::chrono::high_resolution_clock::now();
    lsChar.push('a');
    auto endls1000Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1000Char = endls1000Char - startls1000Char;
    std::cout << "Time taken: " << durationls1000Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 1000 char el DMassiv stack:\n";
    for (int i = 0; i < 999; i++) {
        sChar.push('a');
    }
    auto starts1000Char = std::chrono::high_resolution_clock::now();
    sChar.push('a');
    auto ends1000Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1000Char = ends1000Char - starts1000Char;
    std::cout << "Time taken: " << durations1000Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 10000 char el list stack:\n";
    for (int i = 0; i < 9999; i++) {
        lsChar.push('a');
    }
    auto startls10000Char = std::chrono::high_resolution_clock::now();
    lsChar.push('a');
    auto endls10000Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10000Char = endls10000Char - startls10000Char;
    std::cout << "Time taken: " << durationls10000Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 10000 char el DMassiv stack:\n";
    for (int i = 0; i < 9999; i++) {
        sChar.push('a');
    }
    auto starts10000Char = std::chrono::high_resolution_clock::now();
    sChar.push('a');
    auto ends10000Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10000Char = ends10000Char - starts10000Char;
    std::cout << "Time taken: " << durations10000Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 100000 char el list stack:\n";
    for (int i = 0; i < 99999; i++) {
        lsChar.push('a');
    }
    auto startls100000Char = std::chrono::high_resolution_clock::now();
    lsChar.push('a');
    auto endls100000Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100000Char = endls100000Char - startls100000Char;
    std::cout << "Time taken: " << durationls100000Char.count() << " milliseconds" << std::endl;

    std::cout << "push in 100000 char el DMassiv stack:\n";
    for (int i = 0; i < 99999; i++) {
        sChar.push('a');
    }
    auto starts100000Char = std::chrono::high_resolution_clock::now();
    sChar.push('a');
    auto ends100000Char = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100000Char = ends100000Char - starts100000Char;
    std::cout << "Time taken: " << durations100000Char.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1 char el list stack:\n";
    auto startls1Charpop = std::chrono::high_resolution_clock::now();
    lsChar.pop();
    auto endls1Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1Charpop = endls1Charpop - startls1Charpop;
    std::cout << "Time taken: " << durationls1Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1 char el DMassiv stack:\n";
    auto starts1Charpop = std::chrono::high_resolution_clock::now();
    sChar.pop();
    auto ends1Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1Charpop = ends1Charpop - starts1Charpop;
    std::cout << "Time taken: " << durations1Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10 char el list stack:\n";
    for (int i = 0; i < 9; i++) {
        lsChar.pop();
    }
    auto startls10Charpop = std::chrono::high_resolution_clock::now();
    lsChar.pop();
    auto endls10Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10Charpop = endls10Charpop - startls10Charpop;
    std::cout << "Time taken: " << durationls10Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10 char el DMassiv stack:\n";
    for (int i = 0; i < 9; i++) {
        sChar.pop();
    }
    auto starts10Charpop = std::chrono::high_resolution_clock::now();
    sChar.pop();
    auto ends10Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10Charpop = ends10Charpop - starts10Charpop;
    std::cout << "Time taken: " << durations10Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100 char el list stack:\n";
    for (int i = 0; i < 99; i++) {
        lsChar.pop();
    }
    auto startls100Charpop = std::chrono::high_resolution_clock::now();
    lsChar.pop();
    auto endls100Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100Charpop = endls100Charpop - startls100Charpop;
    std::cout << "Time taken: " << durationls100Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100 char el DMassiv stack:\n";
    for (int i = 0; i < 99; i++) {
        sChar.pop();
    }
    auto starts100Charpop = std::chrono::high_resolution_clock::now();
    sChar.pop();
    auto ends100Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100Charpop = ends100Charpop - starts100Charpop;
    std::cout << "Time taken: " << durations100Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1000 char el list stack:\n";
    for (int i = 0; i < 999; i++) {
        lsChar.pop();
    }
    auto startls1000Charpop = std::chrono::high_resolution_clock::now();
    lsChar.pop();
    auto endls1000Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1000Charpop = endls1000Charpop - startls1000Charpop;
    std::cout << "Time taken: " << durationls1000Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1000 char el DMassiv stack:\n";
    for (int i = 0; i < 999; i++) {
        sChar.pop();
    }
    auto starts1000Charpop = std::chrono::high_resolution_clock::now();
    sChar.pop();
    auto ends1000Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1000Charpop = ends1000Charpop - starts1000Charpop;
    std::cout << "Time taken: " << durations1000Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10000 char el list stack:\n";
    for (int i = 0; i < 9999; i++) {
        lsChar.pop();
    }
    auto startls10000Charpop = std::chrono::high_resolution_clock::now();
    lsChar.pop();
    auto endls10000Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10000Charpop = endls10000Charpop - startls10000Charpop;
    std::cout << "Time taken: " << durationls10000Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10000 char el DMassiv stack:\n";
    for (int i = 0; i < 9999; i++) {
        sChar.pop();
    }
    auto starts10000Charpop = std::chrono::high_resolution_clock::now();
    sChar.pop();
    auto ends10000Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10000Charpop = ends10000Charpop - starts10000Charpop;
    std::cout << "Time taken: " << durations10000Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100000 char el list stack:\n";
    for (int i = 0; i < 99999; i++) {
        lsChar.pop();
    }
    auto startls100000Charpop = std::chrono::high_resolution_clock::now();
    lsChar.pop();
    auto endls100000Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100000Charpop = endls100000Charpop - startls100000Charpop;
    std::cout << "Time taken: " << durationls100000Charpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100000 char el DMassiv stack:\n";
    for (int i = 0; i < 99999; i++) {
        sChar.pop();
    }
    auto starts100000Charpop = std::chrono::high_resolution_clock::now();
    sChar.pop();
    auto ends100000Charpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100000Charpop = ends100000Charpop - starts100000Charpop;
    std::cout << "Time taken: " << durations100000Charpop.count() << " milliseconds" << std::endl;

    sChar.~Stack();
    lsChar.~LStack();

    std::cout << "\n";

    LStack<std::string> lsString;
    Stack<std::string> sString;

    std::string largeString(1000, 'a'); // Строка размером 1000 символов

    std::cout << "push in 1 string el list stack:\n";
    auto startls1String = std::chrono::high_resolution_clock::now();
    lsString.push(largeString);
    auto endls1String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1String = endls1String - startls1String;
    std::cout << "Time taken: " << durationls1String.count() << " milliseconds" << std::endl;

    std::cout << "push in 1 string el DMassiv stack:\n";
    auto starts1String = std::chrono::high_resolution_clock::now();
    sString.push(largeString);
    auto ends1String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1String = ends1String - starts1String;
    std::cout << "Time taken: " << durations1String.count() << " milliseconds" << std::endl;

    std::cout << "push in 10 string el list stack:\n";
    for (int i = 0; i < 9; i++) {
        lsString.push(largeString);
    }
    auto startls10String = std::chrono::high_resolution_clock::now();
    lsString.push(largeString);
    auto endls10String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10String = endls10String - startls10String;
    std::cout << "Time taken: " << durationls10String.count() << " milliseconds" << std::endl;

    std::cout << "push in 10 string el DMassiv stack:\n";
    for (int i = 0; i < 9; i++) {
        sString.push(largeString);
    }
    auto starts10String = std::chrono::high_resolution_clock::now();
    sString.push(largeString);
    auto ends10String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10String = ends10String - starts10String;
    std::cout << "Time taken: " << durations10String.count() << " milliseconds" << std::endl;

    std::cout << "push in 100 string el list stack:\n";
    for (int i = 0; i < 99; i++) {
        lsString.push(largeString);
    }
    auto startls100String = std::chrono::high_resolution_clock::now();
    lsString.push(largeString);
    auto endls100String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100String = endls100String - startls100String;
    std::cout << "Time taken: " << durationls100String.count() << " milliseconds" << std::endl;

    std::cout << "push in 100 string el DMassiv stack:\n";
    for (int i = 0; i < 99; i++) {
        sString.push(largeString);
    }
    auto starts100String = std::chrono::high_resolution_clock::now();
    sString.push(largeString);
    auto ends100String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100String = ends100String - starts100String;
    std::cout << "Time taken: " << durations100String.count() << " milliseconds" << std::endl;

    std::cout << "push in 1000 string el list stack:\n";
    for (int i = 0; i < 999; i++) {
        lsString.push(largeString);
    }
    auto startls1000String = std::chrono::high_resolution_clock::now();
    lsString.push(largeString);
    auto endls1000String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1000String = endls1000String - startls1000String;
    std::cout << "Time taken: " << durationls1000String.count() << " milliseconds" << std::endl;

    std::cout << "push in 1000 string el DMassiv stack:\n";
    for (int i = 0; i < 999; i++) {
        sString.push(largeString);
    }
    auto starts1000String = std::chrono::high_resolution_clock::now();
    sString.push(largeString);
    auto ends1000String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1000String = ends1000String - starts1000String;
    std::cout << "Time taken: " << durations1000String.count() << " milliseconds" << std::endl;

    std::cout << "push in 10000 string el list stack:\n";
    for (int i = 0; i < 9999; i++) {
        lsString.push(largeString);
    }
    auto startls10000String = std::chrono::high_resolution_clock::now();
    lsString.push(largeString);
    auto endls10000String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10000String = endls10000String - startls10000String;
    std::cout << "Time taken: " << durationls10000String.count() << " milliseconds" << std::endl;

    std::cout << "push in 100000 string el list stack:\n";
    for (int i = 0; i < 99999; i++) {
        lsString.push(largeString);
    }
    auto startls100000String = std::chrono::high_resolution_clock::now();
    lsString.push(largeString);
    auto endls100000String = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100000String = endls100000String - startls100000String;
    std::cout << "Time taken: " << durationls100000String.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1 string el list stack:\n";
    auto startls1Stringpop = std::chrono::high_resolution_clock::now();
    lsString.pop();
    auto endls1Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1Stringpop = endls1Stringpop - startls1Stringpop;
    std::cout << "Time taken: " << durationls1Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1 string el DMassiv stack:\n";
    auto starts1Stringpop = std::chrono::high_resolution_clock::now();
    sString.pop();
    auto ends1Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1Stringpop = ends1Stringpop - starts1Stringpop;
    std::cout << "Time taken: " << durations1Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10 string el list stack:\n";
    for (int i = 0; i < 9; i++) {
        lsString.pop();
    }
    auto startls10Stringpop = std::chrono::high_resolution_clock::now();
    lsString.pop();
    auto endls10Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10Stringpop = endls10Stringpop - startls10Stringpop;
    std::cout << "Time taken: " << durationls10Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10 string el DMassiv stack:\n";
    for (int i = 0; i < 9; i++) {
        sString.pop();
    }
    auto starts10Stringpop = std::chrono::high_resolution_clock::now();
    sString.pop();
    auto ends10Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations10Stringpop = ends10Stringpop - starts10Stringpop;
    std::cout << "Time taken: " << durations10Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100 string el list stack:\n";
    for (int i = 0; i < 99; i++) {
        lsString.pop();
    }
    auto startls100Stringpop = std::chrono::high_resolution_clock::now();
    lsString.pop();
    auto endls100Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100Stringpop = endls100Stringpop - startls100Stringpop;
    std::cout << "Time taken: " << durationls100Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100 string el DMassiv stack:\n";
    for (int i = 0; i < 99; i++) {
        sString.pop();
    }
    auto starts100Stringpop = std::chrono::high_resolution_clock::now();
    sString.pop();
    auto ends100Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations100Stringpop = ends100Stringpop - starts100Stringpop;
    std::cout << "Time taken: " << durations100Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1000 string el list stack:\n";
    for (int i = 0; i < 999; i++) {
        lsString.pop();
    }
    auto startls1000Stringpop = std::chrono::high_resolution_clock::now();
    lsString.pop();
    auto endls1000Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls1000Stringpop = endls1000Stringpop - startls1000Stringpop;
    std::cout << "Time taken: " << durationls1000Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 1000 string el DMassiv stack:\n";
    for (int i = 0; i < 999; i++) {
        sString.pop();
    }
    auto starts1000Stringpop = std::chrono::high_resolution_clock::now();
    sString.pop();
    auto ends1000Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durations1000Stringpop = ends1000Stringpop - starts1000Stringpop;
    std::cout << "Time taken: " << durations1000Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 10000 string el list stack:\n";
    for (int i = 0; i < 9999; i++) {
        lsString.pop();
    }
    auto startls10000Stringpop = std::chrono::high_resolution_clock::now();
    lsString.pop();
    auto endls10000Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls10000Stringpop = endls10000Stringpop - startls10000Stringpop;
    std::cout << "Time taken: " << durationls10000Stringpop.count() << " milliseconds" << std::endl;

    std::cout << "pop from 100000 string el list stack:\n";
    for (int i = 0; i < 99999; i++) {
        lsString.pop();
    }
    auto startls100000Stringpop = std::chrono::high_resolution_clock::now();
    lsString.pop();
    auto endls100000Stringpop = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> durationls100000Stringpop = endls100000Stringpop - startls100000Stringpop;
    std::cout << "Time taken: " << durationls100000Stringpop.count() << " milliseconds" << std::endl;

    sString.~Stack();
    lsString.~LStack();

    return 0;
}

#endif  // EASY_EXAMPLE

#include <iostream>
#include <vector>

#include "debug.h"

using namespace std;

Debug::Debug() {}

std::vector<debugable_struct> Debug::data = std::vector<debugable_struct>();

void Debug::add(debugable_class* ref, std::string name) {
    name = name[0] == '&' ? name.substr(1, name.size() - 1) : name;
    debugable_struct debugable = {ref, name};
    Debug::data.push_back(debugable);
}

void Debug::breakPoint(bool split) {
    if (!split) std::cout << "|  ";
    for (auto d : Debug::data) {
        std::cout << d.name << ": { ";
        d.debugable->print();
        std::cout << " }";
        if (split)
            std::cout << std::endl;
        else
            std::cout << "\t|\t";
    }
    getchar();
}
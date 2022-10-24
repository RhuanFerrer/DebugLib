#include "debug.h"

Debug::Debug() {}

void Debug::add(debugable_class* ref, std::string name) {
    name = name[0] == '&' ? name.substr(1, name.size() - 1) : name;
    data.push_back({ref, name});
}

void Debug::breakPoint(bool split) {
    if (!split) std::cout << "|  ";
    for (auto d : data) {
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
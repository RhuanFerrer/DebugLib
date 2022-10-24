#ifndef DEBUG_H
#define DEBUG_H

#include <functional>
#include <iostream>
#include <string>
#include <vector>

class debugable_class {
   private:

   public:
    virtual void print() = 0;
};

template <typename T>
class debugable : public debugable_class {
   public:
    
    debugable(T* value) : t(value) {}
    
    ~debugable() {}
    
    void print() {
        std::cout <<  *t;
    }
    
    std::string getName() {
        return name;
    }

   private:
    std::string name;
    T *t;
};

typedef struct debugable_struct{
    debugable_class* debugable;
    std::string name;
} debugable_struct;

class Debug {
   private:
    std::vector<debugable_struct> data;

   public:
    Debug() {}

    void add(debugable_class* ref, std::string name) {
        name = name[0] == '&' ? name.substr(1, name.size() - 1) : name;
        data.push_back({ref, name});
    }

    void breakPoint(bool split) {
        for (auto d : data) {
            std::cout << d.name << ": { ";
            d.debugable->print();
            std::cout << " }";
            if(split) std::cout << std::endl;
            else std::cout << "  |  ";
        }
        getchar();
    }
};

#endif
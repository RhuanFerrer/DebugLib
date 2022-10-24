#include <iostream>

#include "debug.h"

using namespace std;

class teste : public debugable_class {
   public:
    teste(int a, int b) : a(a), b(b) {}
    void increment() {
        a++;
        b--;
    }

    void print() { cout << "a: " << a << ", b: " << b; }

   private:
    int a;
    int b;
};

int main() {
    Debug debug;

    teste t(10, 10);

    int a = 10;
    int b = 10;

    debug.add(&t, "t");
    debug.add(new debugable<int>(&a), "a");
    debug.add(new debugable<int>(&b), "b");

    for (int i = 0; i < 10; i++) {
        t.increment();
        a++;

        debug.breakPoint(false);
    }

    return 0;
}
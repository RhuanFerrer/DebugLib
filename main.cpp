#include <iostream>

#include "debug.h"

using namespace std;

class teste : public debugable_class {
   public:
    teste(int a) : a(a) {}

    void print() {
        cout << a << endl;
    }

   private:
    int a;
};

int main() {
    
    Debug debug;

    teste t(10);

    int a = 10;

    // addVarDebug(debug, &t);
    debug.add(&t, "t");
    debug.add(new debugable<int>(a), "a");

    debug.breakPoint();

    return 0;
}
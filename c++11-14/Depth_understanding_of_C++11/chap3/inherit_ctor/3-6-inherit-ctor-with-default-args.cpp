#include <iostream>
using namespace std;

struct A {
    A(int a = 3, double = 2.4) {}
};
struct B : A {
    using A::A;
};

void t1() {
    A a1(3, 2.3);
    A a2(12);
    A a3(a1); // default copy ctor
    A a4;     // default ctor
}

void t2() {
    B b1(3, 2.3);
    B b2(12);
    B b3(b1); // default copy ctor
    B b4;     // default ctor
}

int main(int argc, char *argv[]) {
    t1();
    t2();
    return 0;
}

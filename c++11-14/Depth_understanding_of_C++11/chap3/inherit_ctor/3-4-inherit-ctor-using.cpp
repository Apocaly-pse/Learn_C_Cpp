#include <iostream>
using namespace std;

struct A {
    A() { cout << "A::A()\n"; }
    A(int i) { cout << "A::A(int)\n"; }
    A(double d, int i) { cout << "A::A(double, int)\n"; }
    A(float f, int i, const char* c) {}
    // ...
};
struct B : A {
    using A::A; // 继承构造函数
    // ...
    virtual void ExtraInterface() {}
};

void t1() {
    A a(1);
    B b(1.2, 1);
    /* A::A(int) */
    /* A::A(double, int) */
}
int main(int argc, char* argv[]) {
    t1();
    return 0;
}

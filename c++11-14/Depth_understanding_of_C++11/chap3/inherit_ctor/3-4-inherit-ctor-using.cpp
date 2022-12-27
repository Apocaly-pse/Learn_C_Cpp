#include <iostream>
using namespace std;

struct A {
    A(int i) {}
    A(double d, int i) {}
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
}
int main(int argc, char* argv[]) {
    t1();
    return 0;
}

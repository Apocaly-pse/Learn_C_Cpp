#include <iostream>
using namespace std;

struct A {
    A(int) {}
};
struct B {
    B(int) {}
};

struct C : A, B {
    using A::A;
    using B::B;
    C(int) {}
};
/*如果基类的构造函数被声明为私有成员函数，或者派生类是从基类中虚继承的，那么就不能够在派生类中声明继承构造函数。此外，如果一旦使用了继承构造函数，编译器就不会再为派生类生成默认构造函数了*/
void t1() {}
int main(int argc, char *argv[]) {
    t1();
    return 0;
}

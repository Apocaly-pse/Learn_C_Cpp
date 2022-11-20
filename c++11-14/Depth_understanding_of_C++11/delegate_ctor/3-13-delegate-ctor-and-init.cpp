#include <iostream>
using namespace std;
class Info {
public:
    Info() : Info(1) {}           // 委派构造函数
    Info(int i) : Info(i, 'a') {} // 既是目标构造函数，也是委派构造函数
    Info(char e) : Info(1, e) {}
    void print() { cout << type << " " << name << endl; }

private:
    Info(int i, char e) : type(i), name(e) { /* 其他初始化 */
        type += 1;
    } // 目标构造函数
    int type;
    char name;
    // ...
};
// 编译选项:g++ -c -std=c++11 3-2-5.cpp
void t1() {
    Info i1;
    i1.print();
    Info i2(2);
    i2.print();
    Info i3('x');
    i3.print();
    /* 1 a */
    /* 2 a */
    /* 1 x */
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}

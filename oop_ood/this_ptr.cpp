#include <iostream>

using namespace std;
// this指针隐含贼每一个非静态成员函数内

// 用途:
// 1 形参和成员函数同名时候, 使用this指针区分  -> 解决对象冲突
// 2 在类的非静态成员函数中返回对象本身: `return *this`  -> 返回对象本身*this

class P {
public:
    P(int a) { this->a = a; }

    int a;

    // 以引用的方式进行返回
    P &add(P &p) {
        this->a += p.a;
        return *this;
    };
};

int main(int argc, char const *argv[]) {
    /* code */
    // P p(19);
    // cout<<p.a<<endl;

    P p1(1);
    P p2(2);
    p2.add(p1).add(p1);
    cout << p2.a << endl;
    return 0;
}
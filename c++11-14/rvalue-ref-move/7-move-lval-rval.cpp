#include <iostream>
#include <vector>

using namespace std;

void t1() {
    int &&rr1 = 42;
    // int &&rr2 = rr1;//error
    int &&rr3 = std::move(rr1);
    cout << rr1 << std::endl; // 42
    cout << rr3 << std::endl; // 42
}

void t2() {
    int a = 10;
    int &&b = std::move(a);
    cout << b << endl; // 10
}

void t3() {
    int &&c = std::move(10);
    cout << c << endl; // 10
}

int main(int argc, char const *argv[]) {
    t1();
    t2();
    t3();
    return 0;
}
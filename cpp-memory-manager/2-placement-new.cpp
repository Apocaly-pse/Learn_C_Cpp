#include <complex>
#include <iostream>
#include <new> //包含<new>
using namespace std;

/*placement-new 允许我们将对象 建构在allocated memory(已分配好的内存)中,
但是没有placement-delete, 因为并没有额外分配内存,
或者可以称呼与placement-new对应的是placement-delete.
placement-new:等同于调用构造函数.
*/
void t1() {
    char* buf = new char[sizeof(complex<int>) * 3];
    complex<int>* pc = new (buf) complex<int>(1, 2); //这里其实调用了下面的:
    // static void* operator new(size_t size, void* start);
    // //标准库提供的placement new()重载
    delete[] pc;
}
int main(int argc, char const* argv[]) {
    t1();
    return 0;
}

#include <iostream>
#include <memory>
using namespace std;
void t1() {
    int* p1 = new int(100);
    int* p2 = new int(200);
    p1 = p2;
    cout << p1 << " " << *p1 << endl;
    cout << p2 << " " << *p2 << endl;
    /*
    0x600003684050 200
0x600003684050 200*/
}

void t2() {
    auto p1 = make_shared<int>(100);
    auto p2 = make_shared<int>(200);
    p1 = p2;
    cout << p1 << " " << *p1 << endl;
    cout << p2 << " " << *p2 << endl;
    /*
    0x600000f70030 200
0x600000f70030 200*/
}

int main(int argc, char const* argv[]) {
    // t1();
    t2();
    return 0;
}
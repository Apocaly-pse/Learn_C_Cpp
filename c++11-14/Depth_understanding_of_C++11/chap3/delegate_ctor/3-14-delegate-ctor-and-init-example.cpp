#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

class TDConstructed {
    template <class T>
    TDConstructed(T first, T last) : l(first, last) {}
    list<int> l;

public:
    TDConstructed(vector<short> &v) : TDConstructed(v.begin(), v.end()) {}
    TDConstructed(deque<int> &d) : TDConstructed(d.begin(), d.end()) {}
};

void t1() {
    vector<short> v1;
    TDConstructed t1(v1);

    deque<int> d1;
    TDConstructed t2(d1);
}

int main(int argc, char *argv[]) {
    t1();
    return 0;
}

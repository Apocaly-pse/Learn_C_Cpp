#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>
using namespace std;
using ll = long long;

// just for gcc
template <typename T, template <typename> class Container>
ostream &operator<<(ostream &os, const Container<T> v) {
    for (auto i : v) os << i << " ";
    return os;
}


void t1() {
    list<int> a{1, 2, 3};
    cout << a;
}
void t2() {
    ll a = 1;
    cout << a;
}


int main(int argc, char *argv[]) {
    // t1();
    t2();
    return 0;
}

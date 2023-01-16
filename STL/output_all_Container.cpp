#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

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


int main(int argc, char *argv[]) {
    t1();
    return 0;
}

#include <iostream>
using namespace std;

template <typename T>
class NamedObj {
public:
    NamedObj(string& name, const T& val);
    // copy assign
    /* NamedObj<T> &operator=(const NamedObj& no) { */
    /*     this->nameVal = no.nameVal; */
    /*     this->objVal = no.objVal; */
    /*     return *this; */
    /* } */
    /* // copy ctor */
    /* NamedObj<T>(const NamedObj& no) { */
    /*     const int tmp = 1; */
    /*     this->nameVal = no.nameVal; */
    /*     this->objVal = tmp; */
    /* } */

private:
    string& nameVal;
    const T objVal;
};

void t1() {
    string newDog("p");
    string oldDog("S");
    NamedObj<int> p(newDog, 2);
    NamedObj<int> s(oldDog, 9);
    NamedObj<int> r(p);
    /* p = s; */
}
int main(int argc, char* argv[]) {
    t1();
    return 0;
}

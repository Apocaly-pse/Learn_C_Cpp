#include <string>
#include <cstring>
#include <iostream>
#include <typeinfo>
using namespace std;


int main() {
    std::string s{"Hello world!\n"};

    char a[20]; // storage for a C-style string
    std::strcpy(a, std::data(s));
    // [s.data(), s.data() + s.size()] is guaranteed to be an NTBS since C++11
    cout << typeid(s.data()).name() << endl;
    cout << typeid(data(s)).name() << endl;
    std::cout << a;
}
#include <bits/stdc++.h>
using namespace std;

void t1() {
    // C 风格的char-array, size=4
    cout << typeid("abc").name() << endl;
    cout << typeid("a").name() << endl;
    cout << typeid('a').name() << endl;
    // ----------------------------------
    cout << typeid(string("abc")).name() << endl;
    cout << typeid(string("a")).name() << endl;
    // cout << typeid(string('a')).name() << endl; //error cannot conversion
    // from char to string

    cout << max({"abb", "bcc", "aaa"}) << endl;
}

int main(int argc, char const *argv[]) {
    t1();
    return 0;
}
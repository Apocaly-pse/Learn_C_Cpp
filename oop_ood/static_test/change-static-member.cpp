#include <bits/stdc++.h>
using namespace std;

class P {
public:
    static char x;
};
char P::x = 'a';

int main(int argc, char const *argv[]) {
    P p1, p2;
    cout << p1.x << endl; // a
    p1.x += 5;
    cout << p2.x << endl; // f
    return 0;
}
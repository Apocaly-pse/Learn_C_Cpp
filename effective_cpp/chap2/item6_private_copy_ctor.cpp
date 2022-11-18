#include <iostream>
using namespace std;

class P {
public:
    P() = default;

private:
    P(const P&);
    P& operator=(const P&);
};

void t1() {
    P p;
    P q(p);
}
int main(int argc, char* argv[]) {
    t1();
    return 0;
}

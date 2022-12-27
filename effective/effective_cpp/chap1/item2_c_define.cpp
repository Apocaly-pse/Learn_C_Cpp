#include <iostream>
#define f(a, b) ((a > b) ? (a) : (b))
using namespace std;


int main(int argc, char const *argv[]) {
    int a = 5, b = 0;
    cout << f(++a, b) << endl;
    cout << f(++a, b + 10) << endl;
    /*
    7
10*/
    return 0;
}

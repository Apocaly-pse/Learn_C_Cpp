#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[]) {
    cout << sizeof(list<string>) << endl; // 24, 2指针
    return 0;
}
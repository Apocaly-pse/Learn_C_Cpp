#include <iostream>
using namespace std;
class Info {
public:
    Info() : type(1), name('a') { InitRest(); }
    Info(int i) : type(i), name('a') { InitRest(); }
    Info(char e) : type(1), name(e) { InitRest(); }

private:
    void InitRest() { /* 其他初始化 */
    }
    int type;
    char name;
    // ...
};
// 编译选项:g++ -c 3-2-1.cpp
void t1() { Info i1; }

int main(int argc, char *argv[]) {
    t1();
    return 0;
}

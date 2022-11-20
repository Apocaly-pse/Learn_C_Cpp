#include <iostream>
using namespace std;
class DCExcept {
public:
    DCExcept(double d) try : DCExcept(1, d) {
        // 此处并没有执行
        cout << "Run the body." << endl;
        // 其他初始化
    } catch (...) {
        cout << "caught exception." << endl;
    }

private:
    // 目标构造函数中throw
    DCExcept(int i, double d) {
        cout << "going to throw!" << endl;
        throw 0;
    }
    int type;
    double data;
};
int main() { DCExcept a(1.2); }
// 编译选项:g++ -std=c++11 3-2-7.cpp
/* going to throw! */
/* caught exception. */
/* terminate called after throwing an instance of 'int' */

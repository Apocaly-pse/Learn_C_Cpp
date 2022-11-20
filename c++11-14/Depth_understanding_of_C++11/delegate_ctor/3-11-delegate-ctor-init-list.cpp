/* 在初始化列表中调用“基准版本”的构造函数为委派构造函数（delegating
 * constructor），而被调用的“基准版本”则为目标构造函数（target constructor） */

class Info {
public:
    Info() { InitRest(); }              // 目标ctorj
    Info(int i) : Info() { type = i; }  // delegating ctor
    Info(char e) : Info() { name = e; } // delegating ctor

private:
    void InitRest() { /* 其他初始化 */
    }
    int type{1};
    char name{'a'};
    // ...
};
// 编译选项:g++ -c -std=c++11 3-2-3.cpp

#include <thread>
#include <memory>
#include <mutex>
#include <iostream>
#include <stack>
#include <exception>
using namespace std;


struct empty_stack : exception {
    const char* what() const throw();
};

template <typename T>
class threadsafe_stack {
    stack<T> data;
    mutable mutex m;

public:
    threadsafe_stack() {}
    // 可被复制
    threadsafe_stack(const threadsafe_stack& other) {
        // lock_guard lock(other.m);
        lock_guard<mutex> lock(other.m);
        data = other.data;
    }
    // 栈本身不可赋值
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;
    void push(T new_val) {
        lock_guard lock(m);
        // data.emplace(new_val);
        data.push(move(new_val));
    }
    shared_ptr<T> pop() {
        lock_guard lock(m);
        // 弹出前检查是否为空栈
        if (data.empty()) throw empty_stack();
        // 改动栈元素前设置返回值
        shared_ptr<T> const res(make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T& val) {
        lock_guard lock(m);
        if (data.empty()) throw empty_stack();
        val = data.top();
        data.pop();
    }
    bool empty() const {
        lock_guard lock(m);
        return data.empty();
    }
};

void t1() {}

int main(int argc, char const* argv[]) {
    t1();
    return 0;
}
#include <iostream>
#include <thread>

void hello() { std::cout << "Hello concurrent world" << std::endl; }

int main(int argc, char const *argv[]) {
    std::thread t(hello);
    t.join(); //令main主线程等待子线程
    return 0;
}
#include <iostream>
#include <thread>

using namespace std;

void foo(thread& t) {
    t.join();
    cout << "foo done" << endl;
}

int main() {
    thread t1(foo, ref(t2));
    t2 = thread(foo, ref(t1));
    t1.join();
    t2.join();
    return 0;
}

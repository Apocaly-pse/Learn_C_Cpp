#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char const* argv[]) {
    int* pia = new int[12];
    unique_ptr<int[]> up(new int[10]);
    up.release();
    //如果使用共享指针, 则需要自定义删除器
    shared_ptr<int> sp(new int[10], [](int* p) { delete[] p; });
    //并且只能用`get()`访问数组元素
    for (size_t i = 0; i != 10; ++i) *(sp.get() + i) = i;
    sp.reset();//这会调用刚才写好的lambda删除器
    return 0;
}

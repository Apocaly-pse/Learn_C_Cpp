#include <iostream>

using namespace std;

void create_2darray(int d1, int d2) {
    int data[d1][d2]; // ok
    /* int *data1 = new int[d1][d2]; */
    // error: array size is not a constant expression
}

void t1() {
    int data[20][20]; // ok
    create_2darray(1, 2);
}

template <class T>
class Array_2Dim {
public:
    Array_2Dim(int dim1, int dim2);
};

void create_by_template(int d1, int d2) {
    Array_2Dim<int> data(d1, d2);               // ok
    auto data1 = new Array_2Dim<float>(d1, d2); // ok
}

void t2() {
    Array_2Dim<int> data(10, 20);
    Array_2Dim<double> *data1 = new Array_2Dim<double>(20, 30);
}

// 重载两次(嵌套的)operator[]完成二维数组创建操作
template <class T>
class Array2D {
public:
    Array2D(int d1, int d2) {}
    // 此即代理类
    class Array1D {
    public:
        T &operator[](int index);
        const T &operator[](int index) const;
    };
    Array1D operator[](int index);
    const Array1D operator[](int index) const;
};

void t3() {
    /* Array2D<int> data(10, 20); */
    /* cout << data[3][5] << endl; */
}

// 引用计数的string类
/* class */

int main(int argc, char *argv[]) {
    t1();
    return 0;
}

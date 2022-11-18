#include <stdio.h>

int add(int, int);
int func(int, int, int (*)(int, int));


int main(int argc, char *argv[]) {
    int a = 3, b = 3;
    int ans = func(a, b, add);
    printf("ans=%d \n", ans); // ans=6
    return 0;
}

int add(int a, int b) { return a + b; }
int func(int x, int y, int (*f1)(int, int)) { return f1(x, y); }

// Type your code here, or load an example.
#include <stdio.h>

[[gnu::pure, gnu::optimize(1)]]
int square(int num) {
    return num * num;
}

int main(void) {
    int a = square(3);
    printf("%d;%d\n", a, b);
}
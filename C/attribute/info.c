#include <stdio.h>

[[gnu::deprecated("Use square_bis instead.")]]
int square(int num) {
    return num * num;
}

int square_bis(int num) {
    return num * num;
}


int main(void) {
    int a = square(3);
    int b = square(3);
    printf("%d;%d\n", a, b);
}
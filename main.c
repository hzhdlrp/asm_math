#include <stdio.h>

extern int add(int a, int b);

int main(int argc, char *argv[]) {
    printf("hello\n%d\n", add(15, 65));
    return 0;
}
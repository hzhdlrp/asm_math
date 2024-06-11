#include <stdio.h>

extern double f1(double x);
extern double f2(double x);
extern double f3(double x);
// extern int add(int x, int y);

int main(int argc, char *argv[]) {

    printf("hello\n %d \n", f1(4.0));
    return 0;
}
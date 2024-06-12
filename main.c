#include <stdio.h>
#include "lib/integral.h"
#include "lib/root.h"

extern double f1(double); // e^(-x) + 3
extern double f2(double); // 2x - 2
extern double f3(double); // 1/x
extern double f1_d(double);
extern double f2_d(double);
extern double f3_d(double);

int main(int argc, char *argv[]) {
    double roots[3];

    // f1 and f2 intersects on the segment [1, 3], because 
    // in 1 f1 = 0, and f2 > 0
    // in 3 f1 = 4, and f2 < 4
    
    roots[0] = root(f1, f2, f1_d, f2_d, 1, 3, 0.001);
    printf("%lf\n", roots[0]);
    return 0;
}
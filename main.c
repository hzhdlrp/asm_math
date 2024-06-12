#include <stdio.h>
#include <getopt.h>
#include "lib/integral.h"
#include "lib/root.h"

extern double f1(double); // e^(-x) + 3
extern double f2(double); // 2x - 2
extern double f3(double); // 1/x
extern double f1_d(double);
extern double f2_d(double);
extern double f3_d(double);
double F1(double x) {
    return f1(x) - f3(x);
}
double F2(double x){
    return f1(x) - f2(x);
}

int main(int argc, char *argv[]) {
    double roots[3]; // points of intersections

    // f1 and f2 intersects on the segment [1, 3], because 
    // in 1 f1 = 0, and f2 > 0
    // in 3 f1 = 4, and f2 < 4
    
    roots[0] = root(f1, f2, f1_d, f2_d, 1, 3, 0.0001);

    // f1 and f3 intersects on the segment [0.1, 1], because 
    // in 0.1 f1 < 4, and f3 = 10
    // in 1 f1 > 3, and f3 = 1

    roots[1] = root(f1, f3, f1_d, f3_d, 0.1, 1, 0.0001);

    // f2 and f3 intersects on the segment [0.1, 1], because 
    // in 0.1 f2 = 2.2, and f3 = 10
    // in 1 f1 = 4, and f3 = 1

    roots[2] = root(f2, f3, f2_d, f3_d, 0.1, 1, 0.0001);

    // printf("f1 intersects f2 in %lf\n", roots[0]);
    // printf("f1 intersects f3 in %lf\n", roots[1]);
    // printf("f2 intersects f3 in %lf\n", roots[2]);

    double area = 0; // he area of a figureб bounded by graphs of functions
    area += integral(F1, roots[1], roots[2], 0.0001);
    area += integral(F2, roots[2], roots[0], 0.0001);
    printf("\narea of the figure = %lf\n", area);

    const struct option long_options[] = {
		{ "root", no_argument, &flag_a, 1 },
		{ "optb", no_argument, &flag_b, 10 },
		{ "optc", no_argument, &flag_c, -121 },
		{ NULL, 0, NULL, 0}
	};

    return 0;
}
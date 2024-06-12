#include <stdbool.h>
#include <stdio.h>
#include "root.h"

int iterations = 0;
int get_iterations(void) {
    return iterations;
}
void reset_iterations(void) {
    iterations = 0;
}
typedef enum points {
    A,
    B,
} points;

double diff(double x, afunc *f, afunc *g) {
    return f(x) - g(x);
} 

double root(afunc *f, afunc *g, afunc *f_, afunc *g_, double a, double b, double eps1) {
    points d; // A or B, defines the point to which the tangent is drawn
    double c; // approximation to the root
    _Bool first_flag, second_flag; // flags for defining the sign of F'(x)*F''(x)
                                   // where F(x) = f(x) - g(x)

    if (diff(a, f, g) > 0) {
        first_flag = true;
    }
    else first_flag = false;
    if (diff((a + b)/2, f, g) > (diff(a, f, g) + diff(b, f, g))/2) {
        second_flag = true;
    } else second_flag = false;

    if (first_flag == second_flag) {
        d = B;
    } else d = A;
    if (d == A) {
        c = a - diff(a, f, g) / diff(a, f_, g_);
        if (diff(c, f, g) * diff(c + eps1, f, g) > 0) {
            c = root(f, g, f_, g_, c, b, eps1);
        } 
    } else {
        c = b - diff(b, f, g) / diff(b, f_, g_);
        if (diff(c, f, g) * diff(c - eps1, f, g) > 0) {
            c = root(f, g, f_, g_, a, c, eps1);
        } 
    }
    iterations++;
    return c;
}
// 2.36788
// 0.632121
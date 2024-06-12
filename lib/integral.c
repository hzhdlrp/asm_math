#include <math.h>
#define P (1/3)
typedef double afunc(double);

double In(afunc *F, int n, double a, double b) {
    double h = (b - a) / n;
    double In = 0;

    for (int i = 0; i < n; ++i) {
        In += F(a + (i + 0.5) * h);
    }
    In *= h;
    return In;
}

double integral(afunc *F, double a, double b, double eps2) {
    int n = 100;
    double eps = 1;
    while(eps > eps2) {
        eps = P * fabs(In(F, n, a, b) - In(F, 2*n, a, b));
        n *= 2;
    }
    return In(F, n, a, b);
}
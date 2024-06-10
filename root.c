#include <stdbool.h>

typedef double afunc(double);
typedef enum points {
    A,
    B,
} points;

double diff(double x, afunc *f, afunc *g) {
    return f(x) - g(x);
}

double root(afunc *f, afunc *g, afunc *f_, afunc *g_, double a, double b, double eps1) {
    points d;
    double c;
    _Bool first_flag, second_flag;

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

    if (a == A) {
        c = a - diff(a, f, g) / diff(a, f_, g_);
        if (diff(c, f, g) * diff(c + eps1, f, g) < 0) {
            c = root(f, g, f_, g_, c, b, eps1);
        } else return c;
    } else {
        c = b - diff(b, f, g) / diff(b, f_, g_);
        if (diff(c, f, g) * diff(c - eps1, f, g) < 0) {
            c = root(f, g, f_, g_, a, c, eps1);
        } else return c;
    }
}

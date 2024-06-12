#include <stdio.h>
#include <math.h>
#include "lib/integral.h"
#include "lib/root.h"

extern double test1(double); // x^3
extern double test2(double); // (5-x)/2
extern double test3(double); // ln(x) + 4
extern double test1_d(double);
extern double test2_d(double);
extern double test3_d(double);
double F1(double x) {
    return test1(x) - test2(x);
}
double F2(double x) {
    return test1(x) - test3(x);
}
double F3(double x) {
    return test3(x) - test2(x);
}

void ROOT_TEST(int i, afunc *f1, afunc *f2, afunc *f1_d, afunc *f2_d, double a, double b, double eps, double correct_ans) {
    double ans = root(f1, f2, f1_d, f2_d, a, b, eps);
    printf("test number %d:\nans: %lf   correct ans: %lf   f(ans): %lf   g(ans): %lf\n\n", i, ans, correct_ans, f1(ans), f2(1));

    if (fabs(ans - correct_ans)/correct_ans <= eps) {
        printf("DONE\n\n");
    } else printf("FAILED\n\n");
}

void INTEGRAL_TEST(int i, afunc *f, double a, double b, double eps, double correct_ans) {
    double ans = integral(f, a, b, eps);
    printf("test number %d:\nans: %lf   correct ans: %lf\n\n", i, ans, correct_ans);

    if (fabs(ans - correct_ans)/correct_ans <= eps) {
        printf("DONE\n\n");
    } else printf("FAILED\n\n");
}

int main(int argc, char *argv[]) {
    printf("root function tests:\n\n");

    ROOT_TEST(1, test1, test2, test1_d, test2_d, 1, 2, 0.001, 1.23477);
    ROOT_TEST(2, test1, test3, test1_d, test3_d, 1, 2, 0.001, 1.65114);
    ROOT_TEST(3, test2, test3, test2_d, test3_d, 0.1, 1, 0.001, 0.20172);

    printf("integral function tests:\n\n");

    INTEGRAL_TEST(1, F1, 2, 3, 0.001, 15);
    INTEGRAL_TEST(2, F2, 2, 2.5, 0.001, 3.36119);
    INTEGRAL_TEST(3, F3, 2, 3, 0.001, 3.65954);
    return 0;
}
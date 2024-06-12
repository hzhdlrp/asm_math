#include <stdio.h>
#include <getopt.h>
#include <math.h>
#include "lib/integral.h"
#include "lib/root.h"

extern double f1(double); // e^(-x) + 3
extern double f2(double); // 2x - 2
extern double f3(double); // 1/x
extern double f1_d(double);
extern double f2_d(double);
extern double f3_d(double);
extern int iterations;

afunc *functions[3] = {f1, f2, f3};
afunc *derivatives[3] = {f1_d, f2_d, f3_d};
typedef struct root_option_args {
    int f_num1;
    int f_num2;
    double a;
    double b;
    double eps;
    double answer;
} root_option_args;
typedef struct integral_option_args {
    int f_num;
    double a;
    double b;
    double eps;
    double answer;
} integral_option_args;

double F1(double x) {
    return f1(x) - f3(x);
}
double F2(double x) {
    return f1(x) - f2(x);
}

int main(int argc, char *argv[]) {
    double roots[3]; // points of intersections
    reset_iterations();
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

    double area = 0; // he area of a figureб bounded by graphs of functions
    area += integral(F1, roots[1], roots[2], 0.0001);
    area += integral(F2, roots[2], roots[0], 0.0001);
    printf("\narea of the figure = %lf\n\n", area);

    int res = 0;
    const char* short_options = "rhiR:I:";
    const struct option long_options[] = {
		{ "root", no_argument, NULL, 'r'},
		{ "help", no_argument, NULL, 'h'},
		{ "test-root", required_argument, NULL, 'R'},
        { "test-integral", required_argument, NULL, 'I'},
        { "iterations", no_argument, NULL, 'i'},
		{ NULL, 0, NULL, 0}
	};

    while ((res = getopt_long(argc, argv, short_options,
		long_options, NULL))!=-1) {
        switch (res) {
            case 'r':
                printf("f1 intersects f2 in %lf\n", roots[0]);
                printf("f1 intersects f3 in %lf\n", roots[1]);
                printf("f2 intersects f3 in %lf\n\n", roots[2]);
                break;
            

            case 'h':
                printf("--help -h\n--root -r\n--iterationt -i\n");
                printf("--test-root -R\n--test-integral -I\n\n");
                break;
            
            case 'i':
                printf("number of iterations: %d\n", get_iterations());
                break;
            
            case 'R':
                root_option_args r_args;
                if (sscanf(optarg, "%d:%d:%lf:%lf:%lf:%lf", 
                           &r_args.f_num1, &r_args.f_num2, &r_args.a, &r_args.b, &r_args.eps, &r_args.answer) == 6) {
                    if (r_args.f_num1 >= 1 && r_args.f_num1 <= 3 && r_args.f_num2 >= 1 && r_args.f_num2 <= 3) {
                        double root_ans = root(functions[r_args.f_num1],
                                            functions[r_args.f_num2],
                                            derivatives[r_args.f_num1],
                                            derivatives[r_args.f_num2],
                                            r_args.a,
                                            r_args.b,
                                            r_args.eps);
                        double absolut = fabs(root_ans - r_args.answer);
                        double relative = absolut / r_args.answer;
                        printf("%lf %lf %lf\n", root_ans, absolut, relative);
                    } else {
                        printf("error in arguments\n");
                    }
                } else {
                        printf("error in arguments\n");
                }
                break;
            
            case 'I':
                integral_option_args i_args;
                if (sscanf(optarg, "%d:%lf:%lf:%lf:%lf", 
                           &i_args.f_num, &i_args.a, &i_args.b, &i_args.eps, &i_args.answer) == 5) {
                    printf("%d:%lf:%lf:%lf:%lf\n", i_args.f_num, i_args.a, i_args.b, i_args.eps, i_args.answer);
                    if (i_args.f_num >= 1 && i_args.f_num <= 3) {
                        double integral_ans = integral(functions[i_args.f_num],
                                            i_args.a,
                                            i_args.b,
                                            i_args.eps);
                        double absolut = fabs(integral_ans - i_args.answer);
                        double relative = absolut / i_args.answer;
                        printf("%lf %lf %lf\n", integral_ans, absolut, relative);
                    } else {
                        printf("error in arguments\n");
                    }
                } else {
                        printf("error in arguments\n");
                }
                break;

            default:
                break;
                
            }
    }
    return 0;
}
#pragma once
typedef double afunc(double);
double root(afunc *, afunc *, afunc *, afunc *, double, double, double);
int get_iterations(void);
void reset_iterations(void);
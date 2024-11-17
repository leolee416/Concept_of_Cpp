#ifndef MATH_OPERATIONS_HPP
#define MATH_OPERATIONS_HPP
#define ZERO_DIVISION_RESULT 0
#define SUBSTRACTION_DISABLED
int add(int a, int b); //Addition Function

#ifdef SUBSTRACTION_DISABLED
int subtract(int a, int b);
#endif

int multiply(int a, int b); //Multiplication Funtion
double divide(int a, int b); //Dividion Function
// Inline function to return 42

inline int get42() {
    return 42;
}
#endif
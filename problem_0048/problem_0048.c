/*
Self powers

The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
*/

#include <stdio.h>

unsigned long long solution_1(int, int);

int main()
{
    int upper_limit = 1000, digits = 10;
    unsigned long long s1;

    s1 = solution_1(upper_limit, digits);

    printf("s1: %llu\n", s1);
    return 0;
}
/*
Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

#include <stdio.h>

unsigned long long solution_1(int);

int main()
{
    int upper_limit = 2000000;
    unsigned long long s1;

    s1 = solution_1(upper_limit);

    printf("s1: %llu\n", s1);
    return 0;
}
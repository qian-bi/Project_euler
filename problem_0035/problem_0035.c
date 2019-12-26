/*
Circular primes

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719,
are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?
*/

#include <stdio.h>

int solution_1(int);
int solution_2(int);

int main()
{
    int upper_limit = 1000000;
    int s1, s2;

    s1 = solution_1(upper_limit);
    s2 = solution_2(upper_limit);

    printf("s1: %d, s2: %d\n", s1, s2);
    return 0;
}
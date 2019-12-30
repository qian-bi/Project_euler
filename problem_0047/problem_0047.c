/*
Distinct primes factors

The first two consecutive numbers to have two distinct prime factors are:
14 = 2 × 7
15 = 3 × 5
The first three consecutive numbers to have three distinct prime factors are:
644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.
Find the first four consecutive integers to have four distinct prime factors each.
What is the first of these numbers?
*/


#include <stdio.h>

int solution_1(int);

int main()
{
    int cnt = 4;
    int s1;

    s1 = solution_1(cnt);

    printf("s1: %d\n", s1);
    return 0;
}
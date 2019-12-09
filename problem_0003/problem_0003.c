/*
Largest prime factor

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>

unsigned long long solution_1(unsigned long long);
unsigned long long solution_2(unsigned long long);

int main()
{
    unsigned long long num = 600851475143;
    unsigned long long s1, s2;

    s1 = solution_1(num);
    s2 = solution_2(num);

    printf("s1: %llu, s2: %llu\n", s1, s2);
    return 0;
}
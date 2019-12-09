/*
Largest palindrome product

A palindromic number reads the same both ways. The largest palindrome made from
the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>

int solution_1(int);
int solution_2(int);
int solution_3(int);

int main()
{
    int upper_limit = 1000;
    int s1, s2, s3;

    s1 = solution_1(upper_limit);
    s2 = solution_2(upper_limit);
    s3 = solution_3(upper_limit);

    printf("s1: %d, s2: %d, s3: %d\n", s1, s2, s3);
    return 0;
}
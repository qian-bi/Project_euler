/*
Pandigital prime

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once.
For example, 2143 is a 4-digit pandigital and is also prime.
What is the largest n-digit pandigital prime that exists?
*/

#include <stdio.h>

int solution_1();

int main()
{
    int s1;

    s1 = solution_1();

    printf("s1: %d\n", s1);
    return 0;
}
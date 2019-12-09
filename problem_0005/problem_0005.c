/*
Smallest multiple

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int solution_1(int);
int solution_2(int);

int main()
{
    int upper_limit = 20;
    int s1, s2;

    s1 = solution_1(upper_limit);
    s2 = solution_2(upper_limit);

    printf("s1: %d, s2: %d\n", s1, s2);
    return 0;
}
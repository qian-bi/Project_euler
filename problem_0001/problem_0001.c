/*
Multiples of 3 and 5

If we list all the natural numbers below 10 that are multiples of 3 or 5,
we get 3, 5, 6 and 9. The sum of these multiples is 23.
Find the sum of all the multiples of 3 or 5 below 1000.
*/
#include <stdio.h>

unsigned long solution_1(unsigned long);
unsigned long solution_2(unsigned long);
unsigned long solution_3(unsigned long);
unsigned long solution_4(unsigned long);

int main()
{
    unsigned long upper_limit = 1000;
    unsigned long s1, s2, s3, s4;

    s1 = solution_1(upper_limit);
    s2 = solution_2(upper_limit);
    s3 = solution_3(upper_limit);
    s4 = solution_4(upper_limit);
    printf("s1: %d, s2: %d, s3: %d, s4: %d\n", s1, s2, s3, s4);
    return 0;
}

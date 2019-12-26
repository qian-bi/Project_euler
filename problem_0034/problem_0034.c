/*
Digit factorials

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
Find the sum of all numbers which are equal to the sum of the factorial of their digits.
Note: as 1! = 1 and 2! = 2 are not sums they are not included.
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
/*
Power digit sum

2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
*/

#include <stdio.h>

int solution_1(int);

int main()
{
    int p = 1000;
    int s1;

    s1 = solution_1(p);

    printf("s1: %d\n", s1);
    return 0;
}
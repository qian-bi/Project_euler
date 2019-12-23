/*
Number spiral diagonals

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral
is formed as follows:
            21 22 23 24 25
            20  7  8  9 10
            19  6  1  2 11
            18  5  4  3 12
            17 16 15 14 13
It can be verified that the sum of the numbers on the diagonals is 101.
What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/

#include <stdio.h>

int solution_1(int);

int main()
{
    int upper_limit = 1001;
    int s1;

    s1 = solution_1(upper_limit);

    printf("s1: %d\n", s1);
    return 0;
}
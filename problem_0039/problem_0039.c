/*
Integer right triangles

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c},
there are exactly three solutions for p = 120.
{20,48,52}, {24,45,51}, {30,40,50}
For which value of p ≤ 1000, is the number of solutions maximised?
*/

#include <stdio.h>

int solution_1(int);

int main()
{
    int upper_limit = 1000;
    int s1;

    s1 = solution_1(upper_limit);

    printf("s1: %d\n", s1);
    return 0;
}
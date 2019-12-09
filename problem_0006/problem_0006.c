/*
Sum square difference

The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers
and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers
and the square of the sum.
*/

#include <stdio.h>

int solution_1(int);
int solution_2(int);
int solution_3(int);

int main()
{
    int upper_limit = 100;
    int s1, s2, s3;

    s1 = solution_1(upper_limit);
    s2 = solution_2(upper_limit);
    s3 = solution_3(upper_limit);

    printf("s1: %d, s2: %d, s3: %d\n", s1, s2, s3);
    return 0;
}
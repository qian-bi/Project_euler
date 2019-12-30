/*
Coded triangle numbers

The nth term of the sequence of triangle numbers is given by, tn = n(n+1)/2; so the first ten
triangle numbers are:
1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
By converting each letter in a word to a number corresponding to its alphabetical position and
adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10.
If the word value is a triangle number then we shall call the word a triangle word.
Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand
common English words, how many are triangle words?
*/

#include <stdio.h>

int solution_1(FILE *);

int main()
{
    FILE *fp;
    int s1;

    fp = fopen("problem_0042/words.txt", "r");
    s1 = solution_1(fp);
    fclose(fp);

    printf("s1: %d\n", s1);
    return 0;
}
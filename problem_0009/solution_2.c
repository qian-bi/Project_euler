#include <math.h>

int solution_2(int sum)
{
    int a, b, c;
    int s = 0;
    for (a = 3; a < sum / 3; a++)
    {
        b = (sum - 2 * a) * sum / (2 * sum - 2 * a);
        c = sum - a - b;
        if (a * a + b * b == c * c)
        {
            s = a * b * c;
            break;
        }
    }
    return s;
}
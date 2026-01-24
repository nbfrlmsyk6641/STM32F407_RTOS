#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, sum;

    i = 0;
    sum = 0;

    while (i <= 100)
    {
        sum = sum + i;

        i = i + 1;
    }

    printf("i = %d\n", i);
    printf("sum = %d\n", sum);

    return 0;
}

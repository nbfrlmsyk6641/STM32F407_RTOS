#include <stdio.h>
#include <math.h>
#include <string.h>

/* 自增运算符 */

int main()
{
    int i, j;

    i = 5;
    j = ++ i;

    printf("i = %d, j = %d\n", i, j);

    i = 5;
    j = i ++;

    printf("i = %d, j = %d\n", i, j);

    return 0;
}

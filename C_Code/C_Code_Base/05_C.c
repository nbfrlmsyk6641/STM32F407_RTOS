#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int i, j, k;
    float n;

    i = 1 + 2;

    j = 1 + 2 * 3;

    k = i + j + -1 + pow(2,3);

    n = 2.0;

    printf("%d\n",i);
    printf("%d\n",j);
    printf("%d\n",k);
    printf("%.2f\n",n + i);
    printf("%d\n",(int)(n + i));

    return 0;
}

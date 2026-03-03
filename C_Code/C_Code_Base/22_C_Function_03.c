#include <stdio.h>
#include <math.h>
#include <string.h>

/* 函数的址传递 */

void Swap(int *a, int *b);
void Get_Array(int a[]);

int main ()
{
    int x, y, i;
    int a[5] = {0, 1, 2, 3, 4};
    
    x = 10;
    y = 20;

    printf ("x is %d, y is %d\n",x, y);

    Swap(&x, &y);

    printf ("x is %d, y is %d\n",x, y);

    Get_Array(a);

    printf ("\n");

    for (i = 0; i < 5; i ++)
    {
        printf ("a[%d] is %d ", i, a[i]);
    }

    return 0;
}

void Swap(int *a, int *b)
{
    int x;
    x = 0;
    x = *a;
    *a = *b;
    *b = x;

    printf ("a is %d, b is %d\n", *a, *b);
}

void Get_Array(int a[])
{
    int i;

    a[2] = 100;

    for (i = 0; i < 5; i++)
    {
        printf ("a[%d] is %d ", i, a[i]);
    }
}

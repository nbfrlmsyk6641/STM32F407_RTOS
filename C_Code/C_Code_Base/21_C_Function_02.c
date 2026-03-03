#include <stdio.h>
#include <math.h>
#include <string.h>

/* 函数的值传递 */

void swap(int a, int b);

int main ()
{
    int x, y;
    
    x = 3;
    y = 5;

    printf ("x is %d, y is %d\n",x, y);

    swap(x, y);

    printf ("x is %d, y is %d\n",x, y);

    return 0;
}

void swap(int a, int b)
{
    int x;
    x = 0;
    x = a;
    a = b;
    b = x;

    printf ("a is %d, b is %d\n", a, b);

}

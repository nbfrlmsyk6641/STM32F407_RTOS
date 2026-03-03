#include <stdio.h>
#include <math.h>
#include <string.h>

/* 指向指针的指针 */

int main ()
{
    int num = 100;

    int *p = &num;
    int **pp = &p;

    printf ("value of num is %d \n", *p);
    printf ("value of num is %d \n", **pp);

    printf ("add of p is %p\n", p);
    printf ("add of num is %p\n", &num);
    printf ("add of pp is %p\n", *pp);

    return 0;
}

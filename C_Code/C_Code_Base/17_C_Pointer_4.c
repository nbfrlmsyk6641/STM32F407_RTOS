#include <stdio.h>
#include <math.h>
#include <string.h>

/* void与NULL */

int main()
{
    int a = 100;
    char b[] = "ABC";

    int *p = NULL;
    void *q;

    p = &a;
    q = p;

    printf ("add of p is %p, add of q is %p\n", p, q);
    printf ("value of p is %d\n", *p);
    printf ("value of q is %d\n", *(int *)q);

    q = b;
    printf ("add of b is %p, add of q is %p\n", b, q);
    printf ("value of b is %s\n", b);
    printf ("value of q is %s\n", (char *)q);

    return 0;
}

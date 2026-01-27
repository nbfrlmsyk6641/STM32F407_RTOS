#include <stdio.h>
#include <math.h>
#include <string.h>

/* 指针与数组 */

int main()
{
    char a[] = "ABCDEF";
    int b[] = {1, 2, 3, 4, 5};
    float c[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    char *p = NULL;
    int *q = NULL;

    p = a;
    q = b;

    /* 打印数组元素的地址 */
    printf ("a[0]->%p, a[1]->%p, a[2]->%p, a[3]->%p\n", &a[0], &a[1], &a[2], &a[3]);
    printf ("b[0]->%p, b[1]->%p, b[2]->%p, b[3]->%p\n", &b[0], &b[1], &b[2], &b[3]);
    printf ("c[0]->%p, c[1]->%p, c[2]->%p, c[3]->%p\n", &c[0], &c[1], &c[2], &c[3]);

    /* 利用指针索引数组元素 */
    printf ("*p = %c, *(p+1) = %c, *(p+2) = %c, *(p+3) = %c\n", *p, *(p+1), *(p+2), *(p+3));
    printf ("*q = %d, *(q+1) = %d, *(q+2) = %d, *(q+3) = %d\n", *q, *(q+1), *(q+2), *(q+3));

    return 0;
}

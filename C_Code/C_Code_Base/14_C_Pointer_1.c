#include <stdio.h>
#include <math.h>
#include <string.h>

/* 指针的基本操作 */

int main()
{   
    /* 定义指针 */
    char *pa = NULL;
    int *pb = NULL;

    char a;
    int b;

    a = 'a';
    b = 123;

    /* 将变量地址赋值给指针 */
    pa = &a;
    pb = &b;

    /* 取出指针所指向地址中所指向的数值 */
    printf ("%c, %d\n", *pa, *pb);
    printf ("size pa = %d,size pb = %d\n", sizeof(pa), sizeof(pb));

    /* 通过指针修改变量值 */
    *pa = 'b';
    *pb = *pb + 1;
    printf ("%c, %d\n", *pa, *pb);

    /* 打印指针存放的值(打印地址类型数据用%p) */
    printf ("add of pa is %p, add of pb is %p\n", pa, pb);

    return 0;
}

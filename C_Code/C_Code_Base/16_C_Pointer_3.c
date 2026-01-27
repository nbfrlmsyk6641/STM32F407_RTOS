#include <stdio.h>
#include <math.h>
#include <string.h>

/* 利用指针手搓实现strlen函数 */

int main()
{
    char str[] = "ABCDEFG";
    int count = 0;

    char *s = NULL;

    s = str;

    /* 写成*s ++也是可以的，因为自增运算符的优先级高于取值运算符，所以地址会先自增，再被取值 */
    while (*(s ++) != '\0')
    {
        count ++;
    }

    printf ("The lenth of str is %d\n", count);

    return 0;
}

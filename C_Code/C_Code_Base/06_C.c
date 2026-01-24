#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int a, b;

    a = 5;
    b = 3;

    printf("%d\n",a < 5);
    printf("%d\n",a < b);
    printf("%d\n",a > b);

    a = b = 3;

    /* 短路求值原则 */

    /* 逻辑与要求左边和右边同时成立才为真，所以左边为真才会继续运算到右边 */
    (a = 0) && (b = 5);
    printf("a = %d, b = %d\n",a , b);

    /* 逻辑或要求左边和右边有一个为真即可，所以左边满足就不继续运算到右边 */
    (a = 1) || (b = 5);
    printf("a = %d, b = %d\n",a , b);

    return 0;
}

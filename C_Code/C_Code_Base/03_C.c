#include <stdio.h>
#include <math.h>

/* sizeof运算结果的单位是字节 */

int main()
{
    unsigned int a;
    char b;
    float c;
    double d;

    a = 520;
    b = 'F';
    c = 3.14;
    d = 3.14159;

    printf("%d\n",a);
    printf("%d\n",sizeof(a));
    printf("%c\n",b);
    printf("%d\n",sizeof(b));
    printf("%f\n",c);
    printf("%d\n",sizeof(c));
    printf("%.3f\n",d);
    printf("%d\n",sizeof(d));

    a = pow(2,32) - 1;
    printf("%u\n",a);

    return 0;
}

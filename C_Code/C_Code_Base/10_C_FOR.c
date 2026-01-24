#include <stdio.h>
#include <math.h>
#include <string.h>

/* 计算0+1+2+...+100 */

// int main()
// {
//     int i, sum;

//     sum = 0;

//     for (i = 0; i <= 100; i = i + 1)
//     {
//         sum = sum + i;
//     }

//     printf("i = %d\n", i);
//     printf("sum = %d\n", sum);

//     return 0;
// }

/* 判断一个数是不是素数 */
// int main()
// {
//     int i, num, flag;

//     num = 23;

//     flag = 1;

//     for (i = 2; i < num/2; i ++)
//     {
//         if (num % i == 0)
//         {   
//             flag = 0;
//         }
//     }

//     if (flag)
//     {
//         printf("YES\n");
//     }
//     else
//     {
//         printf("NO\n");
//     }

//     return 0;
// }

/* 循环嵌套 */
int main()
{
    int i, j;

    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 3; j ++)
        {
            printf("i = %d, j = %d\n",i, j);
        }
    }

    printf("OVER\n");

    return 0;
}

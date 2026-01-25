#include <stdio.h>
#include <math.h>
#include <string.h>

/* 数组Array */

// #define NUM 10

/* 一维数组 */
// int main()
// {
//     int s[NUM] = {0};

//     int i, sum;

//     i = 0;
//     sum = 0;

//     for (i = 0; i < 10; i ++)
//     {
//         printf("%d\n",s[i]);
//     }

//     for (i = 0; i < 10; i ++)
//     {
//         s[i] = 100;

//         sum = sum + s[i];
//     }

//     printf("sum = %d, avg_sum = %d\n",sum, sum/NUM);
//     printf("size = %d\n",sizeof(s));

//     return 0;
// }

/* 二维数组 */
int main()
{   
    int a[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int i, j;
    
    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 4; j ++)
        {
            printf ("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf ("size = %d\n",sizeof(a));

    return 0;
}

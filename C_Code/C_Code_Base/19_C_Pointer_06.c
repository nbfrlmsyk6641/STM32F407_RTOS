#include <stdio.h>
#include <math.h>1
#include <string.h>

/* 用指针指向二维数组 */

int main ()
{
    int array[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    /* 此时p指向的是一个4个指针元素的一维数组 */
    int (*p)[4] = array;
    int i, j;
    
    /* array + 1是行数加1，列数用数组指针去遍历 */
    for (i = 0; i < 3; i ++)
    {
        for (j = 0; j < 4; j ++)
        {
            printf ("%2d ", *(*(p + i) + j));
        }
        printf ("\n");
    }

    return 0;
}

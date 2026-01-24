#include <stdio.h>
#include <math.h>
#include <string.h>

// int main()
// {
//     int i;

//     i = 20;

//     if (i > 100)
//     {
//         printf("i = %d\n", i);
//     }
//     else
//     {
//         i = 50;
//         printf("i = %d\n", i);
//     }

//     return 0;
// }

int main()
{
    int a, b;

    a = 10;
    b = 100;

    if (a != b)
    {
        if (a > b)
        {
            printf("a > b \n");
        }
        else
        {
            printf("a < b \n");
        }
    }
    else
    {
        printf("a = b \n");
    }

    return 0;
}

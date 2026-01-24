#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    int i;

    i = 100;

    switch (i)
    {
        case 10: printf("i = %d\n", i); break;
        case 100: printf("i = %d\n", i - 100); break;
        default: printf("Error\n"); break;
    }

    return 0;
}

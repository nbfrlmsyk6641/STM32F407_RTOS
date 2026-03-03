#include <stdio.h>
#include <math.h>
#include <string.h>

int Sum_Function(int n);
int Max_Founction(int n, int m);

int main ()
{
    int num, value;
    int n1, n2;

    value = 0;
    num = 100;
    n1 = 200;
    n2 = 200;

    value = Sum_Function(num);

    printf ("value is %d\n", value);

    value = Max_Founction(n1, n2);

    printf ("value is %d\n", value);

    return 0;
}

int Sum_Function(int n)
{
    int i, sum;
    sum = 0;

    for (i = 0; i <= n; i ++)
    {
        sum = sum + i;
    }

    return sum;
}

int Max_Founction(int n, int m)
{
    int max;

    max = -1;

    if (n != m)
    {
        if (n > m)
        {
            max = n;
        }
        else
        {
            max = m;
        }
    }
    else
    {
        max = 0;
    }

    return max;

}



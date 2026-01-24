#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
    char a = 'C';

    unsigned char Heigt = 170;

    char s1[4] = {'a','b','c'};
    char s2[] = {'H','e','l','l','o','\0'};
    char s3[] = {"World"};


    printf("%d\n%c\n",a,a);

    printf("%u\n",Heigt);

    printf("%s, %d\n",s1,sizeof(s1));
    printf("%s, %d\n",s2,sizeof(s2));
    printf("%s, %d\n",s3,sizeof(s3));

    return 0;
}

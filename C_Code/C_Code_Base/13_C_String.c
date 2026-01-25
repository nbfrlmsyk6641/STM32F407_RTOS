#include <stdio.h>
#include <math.h>
#include <string.h>

/* 字符串处理库函数 */

int main()
{
    char str1[] = "String_1";
    char str2[] = "String_2";
    char str3[20];

    /* 使用strlen进行字符串长度计算不会计算结束符 */
    printf("size = %d\n",sizeof(str1));
    printf("str lenth = %d\n",strlen(str1));

    /* 使用库函数进行字符串拷贝 */
    strcpy(str1, str2);
    strcpy(str3, "String_3");
    printf ("%s\n",str1);
    printf ("%s\n",str2);
    printf ("%s\n",str3);

    /* 使用库函数进行字符串连接 */
    strcat(str1, str2);
    strcat(str3, str2);
    printf ("%s\n",str1);
    printf ("%s\n",str3);

    return 0;
}

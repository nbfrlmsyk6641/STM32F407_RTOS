#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* 在结构体中用指针指向另一个结构体，就可以实现相互引用 *//

struct person
{
    char *name;
    int age;
    int sex;
    struct person *couple;
};

struct person w;
struct person h;

int main()
{
    w.name = "w";
    w.age = 30;
    w.couple = &h; //* 指向结构体的指针，赋值的时候就要赋某个结构体的地址 *//

    h.name = "h";
    h.age = 25;
    h.couple = &w; //* 指向结构体的指针，赋值的时候就要赋某个结构体的地址 *//

    printf("w's couple name: %s, age: %d\n", w.couple->name, w.couple->age); //* 通过指针访问结构体成员用 -> 运算符 *//
    printf("h's couple name: %s, age: %d\n", h.couple->name, h.couple->age); //* 通过指针访问结构体成员用 -> 运算符 *//
}

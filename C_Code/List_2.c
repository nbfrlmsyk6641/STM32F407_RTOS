#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* 创建基本的链表，并添加链表节点 *//

struct person
{
    char *name;
    int age;
    int sex;
    struct person *next;
};

struct List
{
    char *name; //* 链表名 *//
    struct person *next; //* 指向某一个节点的指针，通过指向某个节点，又可以继续指向下一个节点 *//
};

int main()
{
    struct List FirstList;
    struct person p1;

    //* 初始化链表，假设这个链表一开始是空的 *//
    FirstList.name = "FirstList";
    FirstList.next = NULL;

    //* 创建第一个节点 *//
    p1.name = "FistPerson";
    p1.next = NULL;

    //* 把第一个节点加入到链表中 *//
    FirstList.next = &p1;

    //* 访问结构体本身用 . 运算符 *//
    printf("First_List_Node: %s\n", FirstList.next->name); //* 通过链表指针访问第一个节点 *//
}

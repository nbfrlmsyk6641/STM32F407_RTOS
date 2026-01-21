#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//* 创建基本的链表，并实现链表的基本操作 *//

struct person
{
    char *name;
    int age;
    int sex;
    struct person *next;
};

struct List
{
    char *name;
    struct person *next; 
};

void InitList(struct List *plist, char *list_name);
void AddListNode(struct List *plist, struct person *new_person);
void DeleteListNode(struct List *plist, struct person *person);
void PrintList(struct List *plist);

int main()
{
    int i = 0;

    struct List FirstList;

    struct person p[] = {
        {"Person_1", 20, 1, NULL},
        {"Person_2", 22, 0, NULL},
        {"Person_3", 24, 1, NULL},
        {"Person_4", 26, 0, NULL},
        {"Person_5", 28, 1, NULL},
        {"Person_6", 30, 0, NULL},
        {"Person_7", 32, 1, NULL},
        {"Person_8", 34, 0, NULL},
        {NULL, 0, 0, NULL}
    };

    //* 初始化链表 *//
    InitList(&FirstList, "FirstList");

    while (p[i].name != NULL)
    {
        //* 添加节点到链表中 *//
        AddListNode(&FirstList, &p[i]);

        i ++;
    }

    //* 打印链表 *//
    PrintList(&FirstList);

    printf("---- 删除链表节点 ----\n");

    //* 从链表中删除指定节点 *//
    DeleteListNode(&FirstList, &p[10]);

    //* 打印删除后的链表 *//
    PrintList(&FirstList);
}

//* 初始化链表函数 *//
void InitList(struct List *plist, char *list_name)
{
    plist->name = list_name;
    plist->next = NULL;
}

//* 添加节点到链表函数 *//
void AddListNode(struct List *plist, struct person *new_person)
{   
    //* 结构体指针，指向一个结构体变量 *//
    struct person *last;

    //* 判断一下原链表是不是空链表 *//
    if (plist->next == NULL)
    {
        //* 原链表是空链表，直接将新节点作为链表的第一个节点 *//
        plist->next = new_person;
        new_person->next = NULL;
        return;
    }

    //* 原链表非空 *//
    last = plist->next;

    // * 找到链表的最后一个节点 *//
    while (last->next != NULL)
    {
        last = last->next;
    }

    //* 将新节点加入到链表的最后 *//
    last->next = new_person;

    new_person->next = NULL;
}

//* 删除链表节点函数 *//
void DeleteListNode(struct List *plist, struct person *person)
{
    //* 结构体指针，指向一个结构体变量 *//
    struct person *p = plist->next;
    struct person *prev = NULL;
    
    //* 找出要删除的节点和要删除节点的前一个节点 *//
    while (p != NULL && p != person)
    {
        prev = p;
        p = p->next;
    }

    //* 判断一下因为什么退出循环的 *//
    if (p == NULL)
    {
        //* 没有找到要删除的节点 *//
        printf("DeleteListNode: Person not found!\n");
        return;
    }

    //* 找到要删除的节点，判断一下要删除的节点是否是第一个节点 *//
    if (prev == NULL)
    {
        //* 要删除的是第一个节点，原链表的头指针指向要删除节点的下一个节点 *//
        plist->next = p->next;
    }
    else
    {
        //* 要删除的不是第一个节点，前一个节点的 next 指针指向要删除节点的下一个节点 *//
        prev->next = p->next;
    }
}

//* 打印链表函数 *//
void PrintList(struct List *plist)
{
    int i = 0;

    //* 结构体指针，指向一个结构体变量 *//
    struct person *last;

    //* 指针赋值 *//
    last = plist->next;

    //* 循环打印链表 *//
    while (last != NULL)
    {
        //* 通过指针访问结构体成员，使用 -> 运算符 *//
        printf("Name: %s, Age: %d, Sex: %d\n", last->name, last->age, last->sex);

        last = last->next;

        i ++;
    }
}

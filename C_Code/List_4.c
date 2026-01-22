#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* 自己写的通用单链表以及单链表操作 */

/* 宏定义，从节点指针算出结构体指针，从而操作结构体 */
/* 使用offsetof计算出某个成员在某个类型的结构体中的偏移量 */
/* 用一个指针减去偏移量来获取结构体的起始地址 */
/* 然后将其转换为某个类型的结构体指针 */
/* 这样就可以通过这个指针访问包含该节点的结构体成员 */
#define CONTAINER_OF(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

/* 链表节点结构体定义 */
struct ListNode
{
    struct ListNode *next;
};

/* 链表头结构体定义 */
struct List
{
    char *name;
    struct ListNode *next;
};

/* 链表成员结构体定义 */
struct person
{
    char *name;
    int age;
    int sex;
    struct ListNode list_node;
};

/* 类型定义 */
typedef int (*CompareFunc)(struct ListNode *node1, struct ListNode *node2);

/* 函数声明 */
void InitList(struct List *plist, char *list_name);
void AddListNode(struct List *plist, struct ListNode *new_node);
void DeleteListNode(struct List *plist, struct ListNode *del_node);
void PrintList(struct List *plist);
int CompareByAge(struct ListNode *node1, struct ListNode *node2);
void SortList(struct List *plist, CompareFunc compare);

int main()
{
    int i = 0;

    /* 初始化链表头 */
    struct List FirstList;

    /* 初始化链表成员数组 */
    struct person p[] = {
        {"Person_1", 40, 1, {NULL}},
        {"Person_2", 22, 0, {NULL}},
        {"Person_3", 29, 1, {NULL}},
        {"Person_4", 26, 0, {NULL}},
        {"Person_5", 27, 1, {NULL}},
        {"Person_6", 55, 0, {NULL}},
        {"Person_7", 32, 1, {NULL}},
        {"Person_8", 34, 0, {NULL}},
        {NULL, 0, 0, {NULL}}
    };

    /* 初始化链表 */
    InitList(&FirstList, "FirstList");

    /* 向链表中添加节点 */
    while (p[i].name != NULL)
    {
        AddListNode(&FirstList, &p[i].list_node);
        i++;
    }

    /* 打印链表 */
    PrintList(&FirstList);

    printf("---- 链表排序后 ----\n");

    /* 链表排序 */
    SortList(&FirstList, CompareByAge);
    PrintList(&FirstList);

    printf("---- 删除链表节点 ----\n");

    /* 从链表中删除指定节点 */
    DeleteListNode(&FirstList, &p[2].list_node);

    /* 打印删除后的链表 */
    PrintList(&FirstList);

}

/* 初始化链表函数 */
void InitList(struct List *plist, char *list_name)
{
    plist->name = list_name;
    plist->next = NULL;
}

//* 添加节点函数 *//
void AddListNode(struct List *plist, struct ListNode *new_node)
{
    struct ListNode *last;

    /* 判断链表是否为空 */
    if (plist->next == NULL)
    {
        plist->next = new_node;
        new_node->next = NULL;
        return;
    }

    /* 链表非空，找到最后一个节点 */
    last = plist->next;

    while (last->next != NULL)
    {   
        /* 移动到下一个节点 */
        last = last->next;
    }

    last->next = new_node;
    new_node->next = NULL;
}

/* 删除节点函数 */
void DeleteListNode(struct List *plist, struct ListNode *del_node)
{
    struct ListNode *p = plist->next;
    struct ListNode *prev = NULL;

    /* 查找要删除的节点 */
    while (p != NULL && p != del_node)
    {
        prev = p;
        p = p->next;
    }

    /* 没找到要删除的节点 */
    if (p == NULL) return;

    /* 找到了，但要删除的节点是头节点 */
    if (prev == NULL)
    {
        plist->next = p->next;
    }
    else
    {
        prev->next = p->next;
    }
}

/* 链表打印函数 */
void PrintList(struct List *plist)
{
    int i = 0;

    /*通过链表节点遍历并打印信息*/
    struct ListNode *tmp_node;
    struct person *tmp_person;

    tmp_node = plist->next;
    

    while (tmp_node != NULL)
    {
        tmp_person = CONTAINER_OF(tmp_node, struct person, list_node);
        printf("Name: %s, Age: %d\n", tmp_person->name, tmp_person->age);
        tmp_node = tmp_node->next;
    }

}

/* 年龄比较函数 */
int CompareByAge(struct ListNode *node1, struct ListNode *node2)
{
    struct person *p1 = CONTAINER_OF(node1, struct person, list_node);
    struct person *p2 = CONTAINER_OF(node2, struct person, list_node);

    if (p1->age > p2->age) 
    {
        return 1;
    }
    return 0;
}

void SortList(struct List *plist, CompareFunc compare)
{
    int swapped;
    struct ListNode *prev;
    struct ListNode *curr;
    struct ListNode *next;
    struct ListNode *end = NULL;

    /* 判断是否为空链表或单节点链表 */
    if (plist->next == NULL || plist->next->next == NULL)
    {
        return;
    }

    /* 开始执行冒泡排序 */
    do
    {
        swapped = 0;
        prev = NULL;
        curr = plist->next;

        while (curr->next != end)
        {
            /* 移动节点 */
            next = curr->next;

            /* 比较节点，当前节点大于下一个节点就需要交换 */
            if (compare(curr, next))
            {
                curr->next = next->next;
                next->next = curr;

                if (prev == NULL)
                {
                    plist->next = next;
                }
                else
                {
                    prev->next = next;
                }

                swapped = 1;

                prev = next;
            }
            else
            {
                prev = curr;
                curr = next;
            }
        }

        end = curr;

    } while (swapped);
}


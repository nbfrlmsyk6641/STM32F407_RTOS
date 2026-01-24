#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 看韦东山的课写的单链表以及单链表操作 */

struct person
{
    char *name;
    int age;
    struct person *next;
};

struct List
{
    char *name;
    struct person head; 
};

/* 函数声明 */
void InitList(struct List *plist, char *list_name);
void AddListNode(struct List *plist, struct person *new_node);
void PrintList(struct List *plist);
void DeleteListNode(struct List *plist, struct person *del_person);
void AddListNodeAfter(struct person *prev, struct person *new_person);
void SortList(struct List *plist);

int main()
{
    int i = 0;

    struct List MyList;

    struct person p[] = {
        {"Person_1", 40, NULL},
        {"Person_2", 22, NULL},
        {"Person_3", 29, NULL},
        {"Person_4", 26, NULL},
        {"Person_5", 27, NULL},
        {"Person_6", 55, NULL},
        {"Person_7", 32, NULL},
        {"Person_8", 34, NULL},
        {NULL, 0, NULL}
    };

    /* 初始化链表 */
    InitList(&MyList, "MyList");

    /* 添加节点至链表 */
    while (p[i].name != NULL)
    {
        AddListNode(&MyList, &p[i]);

        i ++;
    }

    /* 添加完成打印链表 */
    PrintList(&MyList);

    printf("---- 链表排序后 ----\n");

    SortList(&MyList);

    PrintList(&MyList);

    printf("---- 删除链表节点 ----\n");

    DeleteListNode(&MyList, &p[2]);

    PrintList(&MyList);
}

/* 初始化链表函数 */
void InitList(struct List *plist, char *list_name)
{
    plist->name = list_name;
    plist->head.next = NULL;
}

/* 添加节点函数 */
void AddListNode(struct List *plist, struct person *new_node)
{
    struct person *last = &plist->head;

    /* 开始查找最后一项 */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 跳出循环代表找出最后一项 */
    last->next = new_node;
    new_node->next = NULL;
}

/* 打印链表函数 */
void PrintList(struct List *plist)
{
    struct person *p;
    p = plist->head.next;

    while (p != NULL)
    {
        printf("Name: %s, Age: %d\n", p->name, p->age);
        p = p->next;
    }
}

/* 删除节点函数 */
void DeleteListNode(struct List *plist, struct person *del_person)
{
    struct person *prev;

    prev = &plist->head;

    while (prev != NULL && prev->next != del_person)
    {
        prev = prev->next;
    }

    if (prev == NULL)
    {
        return;
    }
    else
    {
        prev->next = del_person->next;
    }
}

/* 在指定节点后面添加节点 */
void AddListNodeAfter(struct person *prev, struct person *new_person)
{
    new_person->next = prev->next;
    prev->next = new_person;
}

/* 链表排序函数（冒泡排序），写的比较复杂 */
void SortList(struct List *plist)
{
    struct person *prev1;
    struct person *prev2;
    struct person *curr;
    struct person *next;
    struct person *temp;

    prev1 = &plist->head;
    curr = prev1->next;

    while (curr)
    {
        prev2 = curr;
        next = curr->next;

        while (next)
        {
            if (curr->age > next->age)
            {
                /* 交换节点 */
                DeleteListNode(plist, curr);
                DeleteListNode(plist, next);
                AddListNodeAfter(prev1, next);
                if (prev2 == curr)
                {
                    AddListNodeAfter(next, curr);
                }
                else
                {
                    AddListNodeAfter(prev2, curr);
                }

                /* 交换指针 */
                temp = curr;
                curr = next;
                next = temp;
            }

            prev2 = next;
            next = next->next;
        }

        prev1 = curr;
        curr = curr->next;
    }
}

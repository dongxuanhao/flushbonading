#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LNode *GetKthNode(LinkList L, int k)
{
    if (L == NULL || k <= 0)
        return NULL;

    LNode *p = L->next;
    int count = 1;

    while (p != NULL && count < k)
    {
        p = p->next;
        count++;
    }

    return p;
}

void CreateList(LinkList *L, int n)
{
    *L = malloc(sizeof(LNode));
    if (*L == NULL)
    {
        printf("内存分配失败\n");
        exit(-1);
    }

    (*L)->next = NULL;
    LNode *tail = *L;

    for (int i = 1; i <= n; i++)
    {
        LNode *newNode = malloc(sizeof(LNode));
        if (newNode == NULL)
        {
            printf("内存分配失败\n");
            exit(-1);
        }

        printf("请输入第%d个元素的值:", i);
        scanf("%d", &newNode->data);

        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void DestroyList(LinkList L)
{
    LNode *p = L;
    while (p != NULL)
    {
        LNode *temp = p;
        p = p->next;
        free(temp);
    }
}

void InsertKthList(LinkList *L, int k, ElemType e)
{
    if (*L == NULL || k <= 0)
    {
        printf("插入位置不合法\n");
        return;
    }

    LNode *pre;

    if (k == 1)
    {
        pre = *L;
    }
    else
    {
        pre = GetKthNode(*L, k - 1);
        if (pre == NULL)
        {
            printf("插入位置不合法\n");
            return;
        }
    }

    LNode *newNode = malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        printf("内存分配失败\n");
        exit(-1);
    }

    newNode->data = e;
    newNode->next = pre->next;
    pre->next = newNode;
}

void PrintList(LinkList L)
{
    LNode *p = L->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    LinkList L = NULL;
    CreateList(&L, 5);

    InsertKthList(&L, 3, 99);
    PrintList(L);

    DestroyList(L);
    return 0;
}
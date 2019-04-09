#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int ElemType;


//InintList 初始化
//ListEmpty 是否为空
//ClearList 清空链表
//DestroyList 销毁链表
//GetElem(L，i， *e)
//LocateElem(L, e)
//ListInsert(L, i, e)
//ListDelete(L, i, *e)
//ListLength()

typedef struct node {
    ElemType data;
    struct node *next;
} LinkNode, *LinkNodePtr; 


Status InintList(LinkNodePtr *L)
{
    *L = (LinkNodePtr) malloc(sizeof(LinkNode));

    if (!(*L)) {
        return ERROR;
    }

    (*L)->next = NULL;

    int i;

    return OK;
}

Status ListEmpty(LinkNodePtr L)
{
    if (L->next)
    {
        return FALSE;
    } else
    {
        return TRUE;
    }
}

int ListLength(LinkNodePtr L)
{
    LinkNodePtr p;

    int i = 0;

    p = L->next;

    while(p)
    {
        i++;
        p = p->next;
    }

    return i;
}

Status ListInsert(LinkNodePtr L, ElemType i, ElemType e)
{
    int j = 1;

    LinkNodePtr p, q;
    p = L;

    while(p && j < i )
    {
        p = p->next;
        j++;
    }

    if (!p || j > i)
    {
        return ERROR;
    }
    q = (LinkNodePtr)malloc(sizeof(LinkNode));
    q->next = p->next;
    p->next = q;
    q->data = e;

    return OK;
}

Status ClearList(LinkNodePtr L) 
{
    LinkNodePtr p,q;
    p = L->next;

    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL;

    return OK;
}


Status DestroyList(LinkNodePtr L)
{
    ClearList(L);

    if (L->next == NULL)
    {
        free(L);

        return OK;
    }

    return ERROR;
}

void ListTraverse(LinkNodePtr L)
{
    LinkNodePtr p;
    p = L->next;

    while(p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}


int main(int argc, char const *argv[])
{

    LinkNodePtr L;

    int i;

    InintList(&L);

    //printf("is ListEmpty %d\n", ListEmpty(&L));

    printf("Len is %d\n", ListLength(L));

    for (i = 1; i < 5; ++i)
    {
        printf("elem %d is %d\n", i, ListInsert(L, i, i));
    }


    printf("Len is %d\n", ListLength(L));

    ListTraverse(L);

    ClearList(L);

    printf("is ListEmpty %d\n", ListEmpty(L));

    DestroyList(L);

    return 0;
}
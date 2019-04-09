#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int Status;
typedef int ElemType;


//InintList 初始化
//ListEmpty 是否为空
//ClearList 清空列表
//GetElem(L，i， *e)
//LocateElem(L, e)
//ListInsert(L, i, e)
//ListDelete(L, i, *e)
//ListLength()

typedef struct list
{
    ElemType a[MAXSIZE];
    ElemType len;
} SqList;


Status InintList(SqList *L)
{
    L->len = 0;

    return OK;
}

Status ListEmpty(SqList L)
{
    if (L.len == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

Status GetElem(SqList L, ElemType i, ElemType *e)
{
    if (i > L.len || i < 1 || L.len == 0)
    {
        return ERROR;
    }

    *e = L.a[i-1];

    return OK;
}

Status LocateElem(SqList L, ElemType e)
{
    ElemType len = L.len;
    int i;

    for (i = 0; i < len; i++)
    {
        if (L.a[i] == e)
        {
            return OK;
        }
    }

    return ERROR;
}

Status ListInsert(SqList *L, ElemType i, ElemType e)
{
    if (i > MAXSIZE)
    {
        return ERROR;
    }

    if (i < 1 && i > (L->len + 1))
    {
        return ERROR;
    }
    int j;
    for (j = (L->len - 1); j > i; j--)
    {
        L->a[j+1] = L->a[j];
    }

    L->a[i-1] = e;
    L->len++;

    return OK;
}

Status ListDelete(SqList *L, ElemType i, ElemType *e)
{

    if (i > MAXSIZE)
    {
        return ERROR;
    }

    if (i > (L->len + 1))
    {
        return ERROR;
    }
    *e = L->a[i-1];
    int j;

    for (j = (i - 1); j < L->len;  j++) {
        L->a[j] = L->a[j + 1];
    } 

    L->len--;
    return OK;
}


ElemType ListLength(SqList L)
{
    return L.len;
}


void ListTraverse(SqList L)
{
    int i ;

    for (i = 0; i < L.len; ++i)
    {
        printf("%d\n", L.a[i]);
    }
}

int main(int argc, char const *argv[])
{
    SqList L;
    InintList(&L);
    int i, e;

    for (i = 1; i < 5 ; ++i)
    {
        ListInsert(&L, i, i);
    }

    GetElem(L, 3, &e);
     printf("GetElem is %d\n", e);
    ListDelete(&L, 2, &e);
    printf("Delete ELem is %d\n", e);

    ListTraverse(L);

}
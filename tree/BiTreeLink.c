#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char ElemType;

typedef struct node {
    ElemType data;
    struct node *lchild, *rchild;
} BTree, *BTreePtr;

//InitTree(*T)
//ClearTree(*T)
//DestroyTree(*T)
//CreateTree(*T)
//TreeEmpty(*T)

void InitTree(BTreePtr *T) {
    *T = NULL;
}

void CreateTree(BTreePtr *T) {

    char c;

    scanf("%c", &c);

    if (c == '#') {
        *T = NULL;
    } else {
        *T = (BTreePtr)malloc(sizeof(BTree));
        if(!T) {
            printf("开辟内存失败\n");
            exit(1);
        }
        (*T)->data = c;//给T赋值
        CreateTree(&(*T)->lchild);
        CreateTree(&(*T)->rchild);
    }
}


Status BiTreeEmpty(BTreePtr T)
{ 
    if(T)
        return FALSE;
    else
        return TRUE;
}

void DestroyTree(BTreePtr T) {
    if (T)
    {
        if (T->lchild)
        {
            DestroyTree(T->lchild);
        }

        if(T->rchild)
        {
            DestroyTree(T->rchild);
        }

        free(T);
        T = NULL;
    }
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(BTreePtr T)
{
    int i,j;
    if(!T)
        return 0;
    if(T->lchild)
        i=BiTreeDepth(T->lchild);
    else
        i=0;
    if(T->rchild)
        j=BiTreeDepth(T->rchild);
    else
        j=0;
    return i>j?i+1:j+1;
}


void PreOrderTraverse(BTreePtr T)//前序遍历二叉树
{

    if (T == NULL) return;

    if(T)
    {
        printf("%c ",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
 
}


int main(int argc, char const *argv[])
{
    BTreePtr T;
    InitTree(&T);
    CreateTree(&T);
    PreOrderTraverse(T);
    printf(" \n");
    printf("Dep is %d\n", BiTreeDepth(T));
    DestroyTree(T);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

// InitStack(*s)
// DestroyStack(*s)
// ClearStack(*s)
// StackEmpty(*s)
// GetTop(*s, *e)
// Push(*s, e)
// Pop(*s, *e)
// StackLength(S)

typedef int Status; 

typedef struct StackNode {
	 int data;
	 struct StackNode *next;
} StackNode, *StackNodePtr;


typedef struct LinkStack {
	StackNodePtr top;
	int count;
} LinkStack, *LinkStackPtr;


/* 初始化栈 */
Status InitStack(LinkStack *S)
{
	S->top = NULL;
	S->count = 0;

	return OK;
}

/*  是否是空栈  */
Status StackEmpty(LinkStack *S)
{
	if (S->count == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**
 入栈
*/
Status Push(LinkStack *S, int e)
{
	StackNodePtr node;
	node = (StackNodePtr) malloc (sizeof(StackNode));

	if (!node) {
		return ERROR;
	}
	node->next = S->top;
	node->data = e;
	S->top = node;
	S->count++;

	return OK;
}

/**
 出栈
*/
Status Pop(LinkStack *S, int *e)
{
	if (StackEmpty(S)) 
	{
		return ERROR;
	}
	StackNodePtr p;
	p = S->top;
	*e = p->data;
	S->top = p->next;
	S->count--;
	free(p);

	return OK;
}

/**
 清空栈
*/
Status ClearStack(LinkStack *S)
{
	if (StackEmpty(S)) {
		return OK;
	}

	StackNodePtr p,q;
	p = S->top;

	while(p)
	{
		q = p;
		free(p);
		p = q->next;
	}
	S->count = 0;

	return OK;
}


int main()
{
	LinkStack S;
	int e;

	InitStack(&S);

	for (int i = 0; i < 10; ++i)
	{
		Push(&S, i);
	}

	Pop(&S, &e);

	printf("%d\n", e);

	ClearStack(&S);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(&S));
    
    return 0;
}
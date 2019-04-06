#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
	 char data;
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
Status Push(LinkStack *S, char e)
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
char Pop(LinkStack *S)
{
	char e;

	if (StackEmpty(S)) 
	{
		return ERROR;
	}
	StackNodePtr p;
	p = S->top;
	e = p->data;
	S->top = p->next;
	S->count--;
	free(p);

	return e;
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
		printf("%c\n", p->data);
		free(p);
		p = q->next;
	}
	S->count = 0;

	return OK;
}

char GetTop(LinkStack *S)
{
	if (StackEmpty(S)) {
		return ERROR;
	}

	return S->top->data;
}

int Level(char c)
{
	switch(c){
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '%':
		return 3;
	case '^':
		return 4;
	case '(':
		return 5;
	default:
		return -1;
	}
}


char Calc(char num1,char opt,char num2){
	int a = num1-'0';
	int b = num2-'0';
	int i =0;
	int re = 1;
	switch(opt){
	case '+':
		return a+b+'0';
	case '-':
		return a-b+'0';
	case '*':
		return a*b+'0';
	case '/':
		return a/b+'0';
	case '%':
		return a%b+'0';
	case '^':
		for(i=0;i<b;i++)
			re *=a;
		return re+'0';
	default:
		return 0+'0';
	}
}

int convert(char c)
{
	int a ;

	a = c - '0';

	return a;
}


int main()
{
	LinkStack opS, numS;
	char c, num1, num2;
	InitStack(&opS);
	InitStack(&numS);

	char *str = "3+4*2-6/2";

    int preLevel = 0, curLevel = 0;

	while(*str)
	{
		c = *str++;

		if (isdigit(c))
		{
			Push(&numS, c);
		}
		else
		{

			if (StackEmpty(&opS))
			{
				Push(&opS, c);
				preLevel = Level(c);
			}
			else
			{
				curLevel = Level(c);


				if (preLevel >= curLevel)
				{
					do {
						char result;
						num2 = Pop(&numS);
						num1 = Pop(&numS);
						result = Calc(num1, Pop(&opS), num2);
						Push(&numS, result);
						char op = GetTop(&opS);

						//
						preLevel = Level(op);

					} while((!StackEmpty(&opS)) && preLevel >= curLevel);
				}
				else
				{
					preLevel = curLevel;
				}
				Push(&opS, c);
			}
		}
	}

	while(!StackEmpty(&opS))
	{
		num2 = Pop(&numS);
		num1 = Pop(&numS);
		Push(&numS, Calc(num1, Pop(&opS), num2));
	}

	printf("%c\n", Pop(&numS));
	printf("%c\n", Pop(&opS));
	// printf("%d\n", e);

	ClearStack(&opS);
	ClearStack(&numS);
	// printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(&S));
    
    return 0;
}
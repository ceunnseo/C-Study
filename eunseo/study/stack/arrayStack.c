#include <stdlib.h>
#include <stdio.h>
#include "arrayStack.h"

void stackInit(struct stack * s)
{
	s->pos = -1;
}

int empty(struct stack* s)
{
	if (s->pos == -1) return 1; //텅 빈 경우 1 반환
	else return 0;
}

void push(struct stack* s, int value)
{
	if (s->pos == SIZE - 1)
	{
		printf("stack is full!\n");
		return;
	}
	s->arr[++(s->pos)] = value;
}

int pop(struct stack* s)
{
	if (s->pos == -1)
	{
		printf("stack is empty!\n");
		return -1;
	}
	return s->arr[(s->pos)--];
}

int size(struct stack* s)
{
	return s->pos + 1;
}

int top(struct stack* s)
{
	return s->arr[s->pos];
}

void printStack(struct stack* s)
{
	if (s->pos == -1)
	{
		printf("stack is empty!\n");
		return;
	}
	printf("stack의 모든 원소 출력 :");
	for (int i = 0; i < s->pos; i++)
	{
		printf("%d > ", s->arr[i]);
	}
	printf("%d (= top) \n", s->arr[s->pos]);
}

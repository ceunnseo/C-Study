//언어 c99, 메모리 1116KB, 시간 4ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
typedef struct stack
{
	int pos;
	int arr[SIZE];
};

void stackInit(struct stack* s)
{
	s->pos = -1;
}

void push(struct stack* s, int value)
{
	s->arr[++(s->pos)] = value;
}

int pop(struct stack *s)
{
	// 스택이 비어있다면
	if (s->pos == -1) return -1;
	return s->arr[(s->pos)--];

}

int size(struct stack* s)
{
	return s->pos + 1;
}

int empty(struct stack* s)
{
	if (s->pos == -1) return 1;
	return 0;
}

int top(struct stack* s)
{
	if (s->pos == -1) return -1;
	return s->arr[s->pos];
}


int main(void)
{
	struct stack mystack;
	stackInit(&mystack);


	int n;
	int num;
	char command[5] = {0, };

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			push(&mystack, num);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop(&mystack));
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size(&mystack));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty(&mystack));
		}
		else if (strcmp(command, "top") == 0)
		{
			printf("%d\n", top(&mystack));
		}
	}
}

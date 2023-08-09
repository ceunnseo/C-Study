//언어 c99, 메모리 1380KB, 시간 4ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;
typedef struct stack
{
	struct node* head;
	int stackSize;
};
typedef struct node
{
	Data data;
	struct node* next;
};

void stackInit(struct stack* s)
{
	s->head = NULL;
	s->stackSize = 0;
}

void push(struct stack* s, int value)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;

	newnode->next = s->head;
	s->head = newnode;
	s->stackSize += 1;
}

int pop(struct stack *s)
{
	// 스택이 비어있다면
	if (s->head == NULL) return -1;
	struct node* delNode;
	Data x;
	delNode = s->head;
	x = s->head->data;
	s->head = s->head->next;
	free(delNode);
	s->stackSize -= 1;
	return x;
}

int size(struct stack* s)
{
	return s->stackSize;
}

int empty(struct stack* s)
{
	if (s->head == NULL) return 1;
	return 0;
}

int top(struct stack* s)
{
	// 스택이 비어있다면
	if (s->head == NULL) return -1;
	return s->head->data;
}


int main(void)
{
	struct stack mystack;
	stackInit(&mystack);


	int n;
	int num;
	char command[6];

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

//언어 c99, 메모리 1380KB, 시간 4ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000
typedef int Data;
typedef struct queue
{
	struct node* front;
	struct node* rear;
};
typedef struct node
{
	Data data;
	struct node* next;
};

void queueInit(struct queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}

void push(struct queue* q, int value)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	if (q->front == NULL)
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
}

Data pop(struct queue *q)
{
	
	if (q->front == NULL) return -1; // 큐가 비어있다면
	struct node* delNode = q->front;
	Data value = q->front->data;
	q->front = q->front->next;
	free(delNode);
	return value;
}

int size(struct queue* q)
{
	int cnt = 0;
	struct node* cur = q->front;
	while (cur != NULL)
	{
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

int empty(struct queue* q)
{
	if (q->front == NULL) return 1;
	return 0;
}

Data front(struct queue* q)
{
	// 큐가 비어있다면
	if (q->front == NULL) return -1;
	return q->front->data;
}
Data back(struct queue* q)
{
	if (q->front == NULL) return -1;
	return q->rear->data;
}

int main(void)
{
	struct queue myqueue;
	queueInit(&myqueue);


	int n;
	int num;
	char command[100];

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			push(&myqueue, num);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop(&myqueue));
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size(&myqueue));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty(&myqueue));
		}
		else if (strcmp(command, "front") == 0)
		{
			printf("%d\n", front(&myqueue));
		}
		else if (strcmp(command, "back") == 0)
		{
			printf("%d\n", back(&myqueue));
		}
	}
}

#include <stdlib.h>
#include <stdio.h>
#include "arrayQueue.h"

void queueInit(struct queue* q)
{
	q->front = 0;
	q->rear = 0; //큐 초기화
}
void enqueue(struct queue* q, Data x)
{
	if ((q->rear + 1) % SIZE == q->front)
	{
		printf("Queue is full\n");
		return;
	}
	q->rear = (q->rear + 1) % SIZE;
	q->arr[q->rear] = x;
}
Data dequeue(struct queue* q)
{
	if (q->front == q->rear) //queue가 empty일 때
	{
		printf("Queue is empty\n");
		exit(-1);
	}
	q->front = q->front + 1;
	return q->arr[q->front];
}
void printQueue(struct queue* q)
{
	if (q->front == q->rear)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("Queue : ");
	for (int i = q->front + 1; i != q->rear; i = (i + 1) % SIZE)
	{
		printf("%d ", q->arr[i]);
	}
	printf("%d ", q->arr[q->rear]);
	printf("\n================\n");
	printf("\n");
}
int is_emtpy(struct queue* q)
{
	if (q->front == q->rear)
	{
		return 1; //큐가 비었으면 1 리턴
	}
	return 0; // 아니면 0 리턴
}
int is_full(struct queue* q)
{
	if ((q->front + 1) % SIZE == q->rear)
	{
		return 1; //큐가 가득 찼으면 1 리턴
	}
	return 0; //아니면 0 리턴
}
int queueSize(struct queue* q)
{
	if (q->rear >= q->front)
	{
		return (q->rear - q->front);
	}
	return (q->front - q->rear);
}
Data front(struct queue* q)
{
	if (q->front == q->rear)
	{
		printf("Queue is empty\n");
		exit(-1);
	}
	return q->arr[(q->front + 1) % SIZE];
}

Data back(struct queue* q)
{
	if (q->front == q->rear)
	{
		printf("Queue is empty\n");
		exit(-1);
	}
	return q->arr[q->rear];
}

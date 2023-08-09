#include <stdlib.h>
#include <stdio.h>
#include "linkedListQueue.h"

void queueInit(struct queue* q)
{
	q->front = NULL;
	q->rear = NULL;
}

void enqueue(struct queue* q, int value)
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	if (q->front == NULL) //큐가 비어있는 경우 -> 방금 만든 노드가 첫 노드
	{
		q->front = newnode;
		q->rear = newnode;
	}
	else //큐에 원소가 있는 경우 -> 뒤에 이어주면 됨
	{
		q->rear->next = newnode; //마지막 노드가 새 노드를 가리킴
		q->rear = newnode; //rear가 새 노드를 가리킴
	}
}

Data dequeue(struct queue* q)
{

	if (q->front == NULL) //큐가 비어있다면
	{
		printf("Queue is empty!\n");
		exit(-1);
	}
	struct node* delNode = q->front; //삭제할 노드의 주소값을 저장
	Data value = q->front->data; //반환할 값 저장
	q->front = q->front->next; //front가 삭제할 노드의 다음 노드를 가리키게 하고
	free(delNode); //메모리 해제
	return value; //값 반환
}

void printQueue(struct queue* q)
{
	struct node* cur = q->front;
	if (cur == NULL)
	{
		printf("Queue is empty!\n");
		return;
	}
	printf("Queue: ");
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n=======================\n");
}

int is_empty(struct queue* q)
{
	if (q->front == NULL)
	{
		return 1;
	}
	return 0;
}

int queueSize(struct queue* q)
{
	int cnt = 0;
	struct node* cur = q->front;
	while (cur != NULL)
	{
		cnt += 1;
		cur = cur->next;
	}
	return cnt;

}

Data front(struct queue* q)
{
	// 큐가 비어있다면
	if (q->front == NULL)
	{
		printf("Queue is empty\n");
		exit(-1);
	}
	return q->front->data;
}
Data back(struct queue* q)
{
	if (q->front == NULL)
	{
		printf("Queue is empty\n");
		exit(-1);
	}
	return q->rear->data;
}

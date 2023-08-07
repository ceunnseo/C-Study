#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QUE_LEN 10000

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

typedef struct _lQueue
{
  Node *front;
  Node *rear;
  int queArr[QUE_LEN]
} Queue;

void QueueInit(Queue *pq)
{
  pq->front = NULL;
  pq->rear = NULL;
}

int empty(Queue *pq)
{
  if (pq->front == NULL)
    return 1;
  else
    return 0;
}

void push(Queue *pq, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  if (empty(pq))
  {
    pq->front = newNode;
    pq->rear = newNode;
  }
  else
  {
    pq->rear->next = newNode;
    pq->rear = newNode;
  }
}

int pop(Queue *pq)
{
  if (empty(pq))
    return -1;

  Node *rNode = pq->front;
  int rdata = pq->front->data;
  pq->front = pq->front->next;
  free(rNode);
  return rdata;
}

int front(Queue *pq)
{
  if (empty(pq))
    return -1;
  return pq->front->data;
}

int back(Queue *pq)
{
  if (empty(pq))
    return -1;

  return pq->rear->data;
}

int size(Queue *pq)
{
  int index = 0;
  Node *cNode = pq->front;
  while (cNode != NULL)
  {
    cNode = cNode->next;
    index++;
  }
  return index;
}

int main(void)
{
  Queue q;
  QueueInit(&q);
  char cmd[6];
  int n;

  scanf("%d", &n);
  while (n--)
  {
    scanf("%s", cmd);
    if (!strcmp(cmd, "push"))
    {
      int data;
      scanf("%d", &data);
      push(&q, data);
    }
    else if (!strcmp(cmd, "front"))
    {
      printf("%d\n", front(&q));
    }
    else if (!strcmp(cmd, "pop"))
    {
      printf("%d\n", pop(&q));
    }
    else if (!strcmp(cmd, "empty"))
    {
      printf("%d\n", empty(&q));
    }
    else if (!strcmp(cmd, "size"))
    {
      printf("%d\n", size(&q));
    }
    else if (!strcmp(cmd, "back"))
    {
      printf("%d\n", back(&q));
    }
  }

  return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VERTEX 1001
#define MAX_EDGE 10001

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

typedef struct _linkedList
{
  Node *head;
  Node *cur;
  Node *before;
  int numOfData;
  int (*comp)(int d1, int d2);
} List;

typedef struct _queue
{
  int front;
  int rear;
  int queArr[MAX_VERTEX];
} Queue;

typedef struct _stack
{
  int stackArr[MAX_VERTEX];
  int topIndex;
} Stack;

typedef struct _graph
{
  int numV;
  int numE;
  List *adjList;
  int *visitInfo;
} Graph;

int WhoIsPrecede(int data1, int data2)
{
  if (data1 < data2)
    return 0;
  else
    return 1;
}

void ListInit(List *list)
{
  list->head = (Node *)malloc(sizeof(Node));
  list->head->next = NULL;
  list->comp = NULL;
  list->numOfData = 0;
}

void LInsert(List *list, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *pred = list->head;
  newNode->data = data;

  while (pred->next != NULL &&
         list->comp(data, pred->next->data) != 0)
  {
    pred = pred->next;
  }

  newNode->next = pred->next;
  pred->next = newNode;

  (list->numOfData)++;
}

int LFirst(List *list, int *data)
{
  if (list->head->next == NULL)
    return 0;

  list->before = list->head;
  list->cur = list->head->next;

  *data = list->cur->data;
  return 1;
}

int LNext(List *list, int *data)
{
  if (list->cur->next == NULL)
    return 0;

  list->before = list->cur;
  list->cur = list->cur->next;

  *data = list->cur->data;
  return 1;
}

void StackInit(Stack *stack)
{
  stack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
  if (pstack->topIndex == -1)
    return 1;
  else
    return 0;
}

void SPush(Stack *pstack, int data)
{
  pstack->topIndex++;
  pstack->stackArr[pstack->topIndex] = data;
}
int SPop(Stack *pstack)
{
  int rIdx;
  if (SIsEmpty(pstack))
    return 0;

  rIdx = pstack->topIndex;
  pstack->topIndex--;

  return pstack->stackArr[rIdx];
}

void QueueInit(Queue *pq)
{
  pq->front = 0;
  pq->rear = 0;
}
int QIsEmpty(Queue *pq)
{
  if (pq->front == pq->rear)
    return 1;
  else
    return 0;
}

int NestPosIdx(int pos)
{
  if (pos == MAX_VERTEX - 1)
    return 0;
  else
    return pos + 1;
}

int Enqueue(Queue *pq, int data)
{
  if (NestPosIdx(pq->rear) == pq->front)
    return 0;

  pq->rear = NestPosIdx(pq->rear);
  pq->queArr[pq->rear] = data;
  return 1;
}

int Dequeue(Queue *pq)
{
  if (QIsEmpty(pq))
    return 1;
  pq->front = NestPosIdx(pq->front);
  return pq->queArr[pq->front];
}

void SetSortRule(List *plist, int (*comp)(int d1, int d2))
{
  plist->comp = comp;
}
void GraphInit(Graph *pg, int nv)
{
  int i;

  pg->adjList = (List *)malloc(sizeof(List) * nv);
  pg->numV = nv;
  pg->numE = 0;

  for (i = 0; i < nv; i++)
  {
    ListInit(&(pg->adjList[i]));
    SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
  }

  pg->visitInfo = (int *)malloc(sizeof(int) * pg->numV);
  memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(Graph *pg)
{
  if (pg->adjList != NULL)
    free(pg->adjList);

  if (pg->visitInfo != NULL)
    free(pg->visitInfo);
}

void AddEdge(Graph *pg, int fromV, int toV)
{
  LInsert(&(pg->adjList[fromV]), toV);
  LInsert(&(pg->adjList[toV]), fromV);
  pg->numE += 1;
}

int VisitVertex(Graph *pg, int visitV)
{
  if (pg->visitInfo[visitV] == 0)
  {
    pg->visitInfo[visitV] = 1;
    printf("%d ", visitV + 1);
    return 1;
  }

  return 0;
}
void DFShowGraphVertex(Graph *pg, int startV)
{
  Stack stack;
  int visitV = startV - 1;
  int nextV;

  StackInit(&stack);

  VisitVertex(pg, visitV);
  SPush(&stack, visitV);

  while (LFirst(&(pg->adjList[visitV]), &nextV) == 1)
  {
    int visitFlag = 0;

    if (VisitVertex(pg, nextV) == 1)
    {
      SPush(&stack, visitV);
      visitV = nextV;
      visitFlag = 1;
    }
    else
    {
      while (LNext(&(pg->adjList[visitV]), &nextV) == 1)
      {
        if (VisitVertex(pg, nextV) == 1)
        {
          SPush(&stack, visitV);
          visitV = nextV;
          visitFlag = 1;
          break;
        }
      }
    }

    if (visitFlag == 0)
    {
      if (SIsEmpty(&stack) == 1)
        break;
      else
        visitV = SPop(&stack);
    }
  }

  memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void BFShowGraphVertex(Graph *pg, int startV)
{
  Queue queue;
  int visitV = startV - 1;
  int nextV;

  QueueInit(&queue);
  VisitVertex(pg, visitV);
  while (LFirst(&(pg->adjList[visitV]), &nextV))
  {
    if (VisitVertex(pg, nextV))
      Enqueue(&queue, nextV);
    while (LNext(&(pg->adjList[visitV]), &nextV))
    {
      if (VisitVertex(pg, nextV))
        Enqueue(&queue, nextV);
    }

    if (QIsEmpty(&queue))
      break;
    else
      visitV = Dequeue(&queue);
  }

  memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
void ShowGraphEdgeInfo(Graph *pg)
{
  int i;
  int vx;

  for (i = 0; i < pg->numV; i++)
  {
    printf("%d와 연결된 정점: ", i + 1);

    if (LFirst(&(pg->adjList[i]), &vx))
    {
      printf("%d ", vx + 1);

      while (LNext(&(pg->adjList[i]), &vx))
        printf("%d ", vx + 1);
    }
    printf("\n");
  }
}

int main(void)
{
  Graph graph;
  int N, M, V;
  int from, to;
  scanf("%d %d %d", &N, &M, &V);
  GraphInit(&graph, N);
  for (int i = 0; i < M; i++)
  {
    scanf("%d %d", &from, &to);
    AddEdge(&graph, from - 1, to - 1);
  }
  // ShowGraphEdgeInfo(&graph);
  DFShowGraphVertex(&graph, V);
  printf("\n");
  BFShowGraphVertex(&graph, V);
  GraphDestroy(&graph);
}
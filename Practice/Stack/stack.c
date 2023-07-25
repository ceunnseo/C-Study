#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void StackInit(Stack *stack)
{
  stack->head = NULL;
}
void Push(Stack *stack, Data data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  newNode->next = stack->head;
  stack->head = newNode;
}

Data Pop(Stack *stack)
{
  int rdata;
  Node *rNode = (Node *)malloc(sizeof(Node));

  if (Empty(stack))
    return -1;
  else
    rNode = stack->head;
  rdata = stack->head->data;

  stack->head = stack->head->next;
  free(rNode);
  return rdata;
}
int Size(Stack *stack)
{
  int index = 0;
  Node *cNode = NULL;
  cNode = stack->head;

  while (cNode != NULL)
  {
    // printf("%d", index);
    cNode = cNode->next;
    index++;
  }

  return index;
}
int Empty(Stack *stack)
{
  if (stack->head == NULL)
    return 1;
  else
    return 0;
}
Data Top(Stack *stack)
{
  if (Empty(stack))
    return -1;
  else
    return stack->head->data;
}
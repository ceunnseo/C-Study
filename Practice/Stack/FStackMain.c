#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

typedef struct _linkedStack
{
  Node *head;
} LinkedStack;

int Size(LinkedStack *stack)
{
  int index = 0;
  Node *cNode = NULL;
  cNode = stack->head;

  while (cNode != NULL)
  {
    cNode = cNode->next;
    index++;
  }

  return index;
}

int Empty(LinkedStack *stack)
{
  if (stack->head == NULL)
    return 1;
  else
    return 0;
}
void Push(LinkedStack *stack, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;

  newNode->next = stack->head;
  stack->head = newNode;
}

int Pop(LinkedStack *stack)
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

int Top(LinkedStack *stack)
{
  if (Empty(stack))
    return -1;
  else
    return stack->head->data;
}
void StackInit(LinkedStack *stack)
{
  stack->head = NULL;
}
int main(void)
{
  LinkedStack stack;
  StackInit(&stack);

  char cmd[10];
  int n;
  scanf("%d", &n);
  while (n--)
  {
    scanf("%s", cmd);
    if (!strcmp(cmd, "push"))
    {
      int data;
      scanf("%d", &data);
      Push(&stack, data);
    }
    else if (!strcmp(cmd, "pop"))
    {
      printf("%d\n", Pop(&stack));
    }
    else if (!strcmp(cmd, "empty"))
    {
      printf("%d\n", Empty(&stack));
    }
    else if (!strcmp(cmd, "size"))
    {
      printf("%d\n", Size(&stack));
    }
    else if (!strcmp(cmd, "top"))
    {
      printf("%d\n", Top(&stack));
    }
  }
  return 0;
}
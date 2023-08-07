#ifndef __STACK_PRACTICE__
#define __STACK_PRACTICE__
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
  Data data;
  struct _node *next;
} Node;

typedef struct _listStack
{
  Node *head;
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *stack);
void Push(Stack *stack, Data data);
Data Pop(Stack *stack);
Data Size(Stack *stack);
int Empty(Stack *stack);
Data Top(Stack *stack);

#endif
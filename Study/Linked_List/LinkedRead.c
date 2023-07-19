#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
  int data;
  struct _node *next;
} Node;

int main(void)
{
  Node *head = NULL;
  Node *tail = NULL;
  Node *cur = NULL;

  Node *newNode = NULL;
  int readData;

  while (1)
  {
    printf("자연수 입력 :");
    scanf("%d", &readData);
    if (readData < 1)
      break;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = readData;
    newNode->next = NULL;

    if (head == NULL)
      head = newNode;
    else
      tail->next = newNode;
    tail = newNode;
  }
  printf("\n");

  printf(" Print all Data ! \n");
  if (head == NULL)
  {
    printf("No data exists in the list.");
  }
  else
  {
    cur = head;
    printf("%d ", cur->data);
    while (cur->next != NULL)
    {
      cur = cur->next;
      printf("%d ", cur->data);
    }
  }
  printf("\n\n");

  if (head == NULL)
  {
    return 0;
  }
  else
  {
    Node *delNode = head;
    Node *delNextNode = head->next;

    printf("Delete %d \n", delNode->data);
    while (delNextNode != NULL)
    {
      delNode = delNextNode;
      delNextNode = delNextNode->next;

      printf("Delete %d \n", delNode->data);
      free(delNode);
    }
  }
  return 0;
}
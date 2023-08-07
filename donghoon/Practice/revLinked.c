#include <stdio.h>
#include <stdlib.h>

typedef int LData;

typedef struct ListNode
{
  int val;               // data node
  struct ListNode *next; // adress node
} Node;

Node *reverseListF(Node *head, Node *cur, Node *tail)
{
  // cur = head;
  // while (cur->next != tail)
  //   cur = cur->next;
  // printf("%d", tail->val);
  // tail->next = cur;
  // tail = cur;
  // printf(" >> ");

  // cur = head;
  // while (cur->next != tail)
  //   cur = cur->next;
  // printf("%d", tail->val);
  // tail->next = cur;
  // tail = cur;
  // printf(" >> ");

  // cur = head;
  // while (cur->next != tail)
  //   cur = cur->next;
  // printf("%d", tail->val);
  // tail->next = cur;
  // tail = cur;
  // printf(" >> ");

  // while (1)
  // {
  //   if (tail->val == head->val)
  //   {
  //     printf("%d", head->val);
  //     break;
  //   }
  //   cur = head;
  //   while (cur->next != tail)
  //     cur = cur->next;
  //   printf("%d", tail->val);
  //   tail->next = cur;
  //   tail = cur;
  //   printf(" >> ");
  // }

  if (tail->val == head->val)
  {
    printf("%d", head->val);
    return 0;
  }
  cur = head;
  while (cur->next != tail)
    cur = cur->next;
  printf("%d", tail->val);
  tail->next = cur;
  tail = cur;
  printf(" >> ");
  reverseListF(head, cur, tail);
}

int main(void)
{
  Node *head = NULL;
  Node *tail = NULL;
  Node *cur = NULL;
  Node *newNode = NULL;
  int readData;

  while (1)
  {
    printf("HEAD :");
    scanf("%d", &readData);
    if (readData == 0)
      break;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->val = readData;
    newNode->next = NULL;

    if (head == NULL)
      head = newNode;
    else
      tail->next = newNode;

    tail = newNode;
  }

  printf("===Print All Data===\n\n");
  if (head == NULL)
    printf("No data exists in the list.");
  else
  {
    cur = head;
    printf("%d", cur->val);
    while (cur->next != NULL)
    {
      printf(" >> ");
      cur = cur->next;
      printf("%d", cur->val);
    }
    printf("\n\n");
  }
  reverseListF(head, cur, tail);
}

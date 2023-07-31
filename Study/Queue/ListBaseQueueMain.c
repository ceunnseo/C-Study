#include <stdio.h>
#include "ListBaseQueue.h"
#include "ListBaseQueue.c"

int main(void)
{
  Queue q;
  QueueInit(&q);

  Enqueue(&q, 1);
  Enqueue(&q, 2);
  Enqueue(&q, 3);
  Enqueue(&q, 4);

  while (!QIsEmpty(&q))
    printf("%d ", Dequeue(&q));

  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack.c"

int main(void)
{
  Stack stack;
  StackInit(&stack);
  printf("size = %d \n", Size(&stack));

  Push(&stack, 1);
  Push(&stack, 2);
  Push(&stack, 3);
  Push(&stack, 4);
  Push(&stack, 5);

  printf("size = %d \n", Size(&stack));
  printf("pop = %d \n", Pop(&stack));
  printf("Top = %d \n", Top(&stack));

  while (!Empty(&stack))
    printf("%d ", Pop(&stack));
}
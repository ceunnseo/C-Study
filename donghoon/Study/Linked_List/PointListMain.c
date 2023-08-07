#include <stdio.h>
#include <stdlib.h>
#include "Point.h"
#include "Point.c"
#include "ArrayList.c"

int main(void)
{
  List list;
  Point comPos;
  Point *ppos;

  ListInit(&list);

  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 1);
  LInsert(&list, ppos);

  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 2, 2);
  LInsert(&list, ppos);

  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 3, 1);
  LInsert(&list, ppos);

  ppos = (Point *)malloc(sizeof(Point));
  SetPointPos(ppos, 3, 2);
  LInsert(&list, ppos);

  printf("current number of data: %d \n", LCount(&list));

  if (LFirst(&list, &ppos))
  {
    ShowPointPos(ppos);
    while (LNext(&list, &ppos))
      ShowPointPos(ppos);
  }

  printf("\n");
}
#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "NameCard.c"
#include "ArrayList.h"
#include "ArrayList.c"

int main(void)
{
  List list;
  NameCard *pcard;

  ListInit(&list);

  pcard = MakeNameCard("A", "010-1111-1111");
  LInsert(&list, pcard);
  pcard = MakeNameCard("B", "010-2222-2222");
  LInsert(&list, pcard);
  pcard = MakeNameCard("C", "010-3333-3333");
  LInsert(&list, pcard);

  if (LFirst(&list, &pcard))
  {
    if (!NameCompare(pcard, "A"))
      ShowNameCardInfo(pcard);
    else
    {
      while (LNext(&list, &pcard))
      {
        if (!NameCompare(pcard, "A"))
          ShowNameCardInfo(pcard);
        break;
      }
    }
  }

  if (LFirst(&list, &pcard))
  {
    if (!NameCompare(pcard, "B"))
      ChangePhoneNumber(pcard, "010-9999-9999");
    else
    {
      while (LNext(&list, &pcard))
      {
        if (!NameCompare(pcard, "B"))
          ChangePhoneNumber(pcard, "010-9999-9999");
        break;
      }
    }
  }

  if (LFirst(&list, &pcard))
  {
    if (!NameCompare(pcard, "C"))
    {
      pcard = LRemove(&list);
      free(pcard);
    }
    else
    {
      while (LNext(&list, &pcard))
      {

        if (!NameCompare(pcard, "C"))
        {
          pcard = LRemove(&list);
          free(pcard);
          break;
        }
      }
    }
  }

  printf("Current number of data : %d \n", LCount(&list));
  if (LFirst(&list, &pcard))
  {
    ShowNameCardInfo(pcard);

    while (LNext(&list, &pcard))
      ShowNameCardInfo(pcard);
  }
  return 0;
}
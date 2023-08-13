#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "Table.h"
#include "Table.c"
#include "Slot.h"

int GetSSN(Person *p)
{
  return p->ssn;
}

void ShowPerInfo(Person *p)
{
  printf("SSN : %d\n ", p->ssn);
  printf("NAME : %s\n ", p->name);
  printf("ADDR : %s\n ", p->addr);
}

Person *MakePersonData(int ssn, char *name, char *addr)
{
  Person *newP = (Person *)malloc(sizeof(Person));
  newP->ssn = ssn;
  strcpy(newP->name, name);
  strcpy(newP->addr, addr);
  return newP;
}

int MyHashFunction(int k)
{
  return k % 100;
}

int main(void)
{
  Table myTbl;
  Person *sp;
  Person *np;
  Person *rp;

  TBLInit(&myTbl, MyHashFunction);

  np = MakePersonData(20120003, "Lee", "Seoul");
  TBLInsert(&myTbl, GetSSN(np), np);
  np = MakePersonData(20120012, "KIM", "Jeju");
  TBLInsert(&myTbl, GetSSN(np), np);
  np = MakePersonData(20120049, "Han", "KangWon");
  TBLInsert(&myTbl, GetSSN(np), np);

  sp = TBLSearch(&myTbl, 2021003);
  if (sp != NULL)
    ShowPerInfo(sp);
  sp = TBLSearch(&myTbl, 2021012);
  if (sp != NULL)
    ShowPerInfo(sp);
  sp = TBLSearch(&myTbl, 2021049);
  if (sp != NULL)
    ShowPerInfo(sp);
  rp = TBLSearch(&myTbl, 2021003);
  if (rp != NULL)
    free(rp);
  rp = TBLSearch(&myTbl, 2021012);
  if (rp != NULL)
    free(rp);
  rp = TBLSearch(&myTbl, 2021049);
  if (rp != NULL)
    free(rp);
}
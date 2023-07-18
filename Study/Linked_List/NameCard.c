#include "NameCard.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NameCard *MakeNameCard(char *name, char *phone)
{
  NameCard *newCard = (NameCard *)malloc(sizeof(NameCard));
  strcpy(newCard->name, name);
  strcpy(newCard->phone, phone);
  return newCard;
}

void ShowNameCardInfo(NameCard *pcard)
{
  printf("Name : %s, Phone: %s \n", pcard->name, pcard->phone);
}

int NameCompare(NameCard *pcard, char *name)
{
  return strcmp(pcard->name, name);
}

void ChangePhoneNumber(NameCard *pcard, char *phone)
{
  strcpy(pcard->phone, phone);
}
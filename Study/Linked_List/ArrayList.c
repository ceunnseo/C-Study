#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
  (plist->numOfData) = 0;
  (plist->curPosition) = -1;
}
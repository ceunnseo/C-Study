#include <stdio.h>
#include <stdlib.h>

#define HEAP_LEN 100001
typedef int PriorityComp(int data1, int data2);
typedef struct _heap
{
  PriorityComp *comp;
  int numOfData;
  int heapArr[HEAP_LEN];
} Heap;

int idxPriority(int data1, int data2)
{
  return data2 - data1;
}

void heapInit(Heap *hp, PriorityComp pc)
{
  hp->comp = pc;
  hp->numOfData = 0;
}

int heapEmpty(Heap *hp)
{
  if (hp->numOfData == 0)
    return 1;
  else
    return 0;
}

int parentIdx(int idx)
{
  return idx / 2;
}

int RChildIdx(int idx)
{
  return idx * 2 + 1;
}

int LChildIdx(int idx)
{
  return idx * 2;
}

int priorityIdx(Heap *hp, int idx)
{
  // 자식 노드가 없음
  if (LChildIdx(idx) > hp->numOfData)
    return 0;
  // 자식 노드가 하나만 있음
  else if (LChildIdx(idx) == hp->numOfData)
    return LChildIdx(idx);
  // 자식 노드가 두  개
  else
  {
    // 최소 힙  -> 작은 값이 위로
    if (hp->comp(hp->heapArr[LChildIdx(idx)], hp->heapArr[RChildIdx(idx)]) < 0)
      return RChildIdx(idx);
    else
      return LChildIdx(idx);
  }
}

int HInsert(Heap *hp, int data)
{
  if (hp->numOfData + 1 > HEAP_LEN)
    return 0;
  int idx = hp->numOfData + 1;

  while (idx != 1)
  {
    if (hp->comp(data, hp->heapArr[parentIdx(idx)]) > 0)
    {
      hp->heapArr[idx] = hp->heapArr[parentIdx(idx)];
      idx = parentIdx(idx);
    }
    else
      break;
  }
  hp->heapArr[idx] = data;
  hp->numOfData += 1;
  return 1;
}
int HDelete(Heap *hp)
{
  if (heapEmpty(hp))
    return 0;
  int rheap = hp->heapArr[1];
  int lastIdx = hp->heapArr[hp->numOfData];

  int parentIdx = 1;
  int childIdx;

  while (childIdx = priorityIdx(hp, parentIdx))
  {
    if (hp->comp(lastIdx, hp->heapArr[childIdx]) >= 0)
      break;
    hp->heapArr[parentIdx] = hp->heapArr[childIdx];
    parentIdx = childIdx;
  }

  hp->heapArr[parentIdx] = lastIdx;
  hp->numOfData -= 1;
  return rheap;
}

int prData(int data1, int data2)
{
  return data2 - data1;
}

int main(void)
{
  int cmd, data;
  Heap hp;

  heapInit(&hp, prData);

  scanf("%d", &cmd);
  for (int i = 0; i < cmd; i++)
  {
    scanf("%d", &data);
    if (data == 0)
      printf("%d \n", HDelete(&hp));
    else
      HInsert(&hp, data);
  }
  return 0;
}
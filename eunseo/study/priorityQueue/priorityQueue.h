#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#define SIZE 10
typedef struct Heap//힙 구조체 선언
{
	int* arr;
	int size; //현재 heap의 크기
	int capacity; //힙의 최대 용량
}Heap;


void shiftdown(int* arr, int index, int size);
void heapify(Heap* p, int* a, int s);
int heapRemove(Heap* p);
void shiftup(int* arr, int index);
void printHeap(Heap* p);
int peek(Heap* p);
void heapAdd(Heap* p, int value);
#endif

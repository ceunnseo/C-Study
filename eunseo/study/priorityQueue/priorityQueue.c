#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"


void shiftdown(int* arr, int index, int size)
{
	int left = (2 * index) + 1;
	int right = left + 1;
	int large = -1;
	int temp;
	if (left < size)
		large = left;
	if (right < size && arr[left] < arr[right])
		large = right;
	if (large != -1 && arr[index] < arr[large])
	{
		temp = arr[large];
		arr[large] = arr[index];
		arr[index] = temp;
		shiftdown(arr, large, size);
	}
}

void heapify(Heap* p, int* a, int s)
{
	int i;
	p->arr = a;
	p->size = s;
	p->capacity = SIZE;

	for (i = (p->size / 2) - 1; i >= 0; i--)
	{
		shiftdown(p->arr, i, p->size);
	}
}

int heapRemove(Heap* p)
{
	if (p->size <= 0)
	{
		printf("힙에 저장된 데이터가 없습니다\n");
		exit(1);
	}
	int temp = p->arr[0];
	p->arr[0] = p->arr[p->size - 1];
	p->size--;
	shiftdown(p->arr, 0, p->size);
	return temp;
}

void shiftup(int* arr, int index)
{
	int temp;
	int parentIdx = (index - 1) / 2;
	if (parentIdx >= 0)
	{
		if (arr[index] > arr[parentIdx])
		{
			temp = arr[index];
			arr[index] = arr[parentIdx];
			arr[parentIdx] = temp;
			shiftup(arr, parentIdx);
		}
	}
}

void printHeap(Heap* p)
{
	if (p->size <= 0)
	{
		printf("출력할 데이터가 없습니다.\n");
		
	}
	else
	{
		printf("Heap 출력\n");
		for (int i = 0; i < p->size; i++)
		{
			printf("%d ", p->arr[i]);
		}
		printf("\n");
	}

}

int peek(Heap* p)
{
	return p->arr[0];
}

void heapAdd(Heap* p, int value)
{
	if (p->size == p->capacity)
	{
		printf("힙이 가득차있습니다.\n");
		exit(1);
	}
	p->arr[p->size] = value;
	p->size++;
	shiftup(p->arr, p->size - 1); //배열과 자식 인덱스 전달
}


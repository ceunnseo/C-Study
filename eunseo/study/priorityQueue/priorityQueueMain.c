#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"


int main(void)
{
	int a[SIZE];
	char command[100];
	int num;
	int n;
	Heap heap;

	scanf("%d", &n);
	if (n > SIZE)
	{
		printf("용량을 초과했습니다.\n");
		exit(1);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			a[i] = num;
		}
		heapify(&heap, a, n);
		printHeap(&heap);
	}

	while (1)
	{
		printf("명령을 입력하세요 : ");
		scanf("%s", command);

		if (strcmp(command, "enqueue") == 0) //enqueue 3
		{
			scanf("%d", &num);
			heapAdd(&heap, num);
		}
		if (strcmp(command, "peek") == 0)
		{
			printf("%d\n", peek(&heap));
		}
		else if (strcmp(command, "dequeue") == 0)
		{
			printf("remove : %d\n", heapRemove(&heap));
		}
		else if (strcmp(command, "print") == 0)
		{
			printHeap(&heap);
		}
		else if (strcmp(command, "exit") == 0)
		{
			printf("종료\n");
			exit(1);
		}
	}
}
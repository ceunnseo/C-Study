#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedListQueue.h"

int main(void)
{
	struct queue que;
	queueInit(&que);
	printf("is_empty : %d\n", is_empty(&que));
	printf("queue size : %d\n", queueSize(&que));

	enqueue(&que, 1);
	enqueue(&que, 2);
	enqueue(&que, 3);
	enqueue(&que, 4);
	printQueue(&que); // 1 2 3 4
	printf("is_empty : %d\n", is_empty(&que));
	printf("queue size : %d\n", queueSize(&que));
	printf("front : %d\n", front(&que));
	printf("back : %d\n", back(&que));

	dequeue(&que);
	dequeue(&que);
	printQueue(&que); // 3 4 
	printf("is_empty : %d\n", is_empty(&que));
	printf("queue size : %d\n", queueSize(&que));
	printf("front : %d\n", front(&que));
	printf("back : %d\n", back(&que));

	dequeue(&que);
	dequeue(&que);
	printQueue(&que); // 0
	printf("is_empty : %d\n", is_empty(&que));
	printf("queue size : %d\n", queueSize(&que));
	printf("front : %d\n", front(&que));
	printf("back : %d\n", back(&que));

	dequeue(&que);
}

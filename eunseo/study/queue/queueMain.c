#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayQueue.h"

int main(void)
{
	struct queue que;
	queueInit(&que);

	enqueue(&que, 1);
	enqueue(&que, 2);
	enqueue(&que, 3);
	enqueue(&que, 4);
	printf("front : %d\n", front(&que)); // 1
	printf("back : %d\n", back(&que)); // 4
	printf("size : %d\n", queueSize(&que)); //4
	printQueue(&que); // 1 2 3 4

	enqueue(&que, 5); //큐에 enqueue가 불가한 상황

	dequeue(&que); // 2 3 4
	printf("front : %d\n", front(&que)); // 1
	printf("back : %d\n", back(&que)); // 4
	printf("size : %d\n", queueSize(&que));
	printQueue(&que);

	dequeue(&que); // 3 4
	dequeue(&que); // 4
	printf("front : %d\n", front(&que)); // 1
	printf("back : %d\n", back(&que)); // 4
	printf("size : %d\n", queueSize(&que)); // 1
	printQueue(&que);

	dequeue(&que); //큐가 비어있음
	printf("front : %d\n", front(&que));
	printf("back : %d\n", back(&que));
	printf("size : %d\n", queueSize(&que));
	printQueue(&que);
	//실행 종료
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayStack.h"

int main(void)
{
	char command[12];
	struct stack s1;
	int num;
	stackInit(&s1); //스택 초기화
	while (1)
	{
		scanf("%s", command);
		if (strcmp(command, "exit") == 0)
		{
			printf("exit the program\n");
			break;
		}
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			push(&s1, num);
		}
		else if (strcmp(command, "pop") == 0)
		{
			printf("%d\n", pop(&s1));
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", size(&s1));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", empty(&s1));
		}
		else if (strcmp(command, "top") == 0)
		{
			printf("%d\n", top(&s1));
		}
		else if (strcmp(command, "printStack") == 0)
		{
			printStack(&s1);
		}
		else
		{
			printf("plz check the command\n");
		}
	}
}

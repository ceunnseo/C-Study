#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 10000
#define false 0
#define true 1

int arr[MAX_SIZE];

int top = -1;
int bot = -1;

int front()
{
	if (empty() == 1)
		return -1;
	else
		return arr[top + 1];
}

int back()
{
	if (empty() == 1)
		return -1;
	else
		return arr[bot];
}

int full() //push에 사용할 연산
{
	if (bot >= MAX_SIZE - 1)
		return true;
	else
		return false;
}

int empty()
{
	if (top == bot)
		return 1;
	else
		return 0;
}

void push(int x)
{ 
	bot = bot + 1; //초기값이 -1이므로
	arr[bot] = x;
}

int pop()
{
	if (empty() == 1)
		return -1;
	else
	{
		int val = arr[top + 1]; //초기값이 -1이므로
		top = top + 1;
		return val;
	}
}

int size()
{
	return (bot - top);
}

int main()
{
	int N, i, val;
	char COMMAND[6];

	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%s", &COMMAND);

		if (strcmp(COMMAND, "push") == 0)
		{
			scanf("%d", &val);
			push(val);
		}
		else if (strcmp(COMMAND, "pop") == 0)
			printf("%d\n", pop());

		else if (strcmp(COMMAND, "size") == 0)
			printf("%d\n", size());

		else if (strcmp(COMMAND, "empty") == 0)
			printf("%d\n", empty());

		else if (strcmp(COMMAND, "front") == 0)
			printf("%d\n", front());

		else if (strcmp(COMMAND, "back") == 0)
			printf("%d\n", back());
	}

	return 0;
}

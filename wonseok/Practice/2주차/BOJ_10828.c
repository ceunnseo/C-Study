#define _CRT_SECURE_NO_WARNINGS //scanf() 출력 문제 해결
#include <stdio.h>
#include <string.h>
#include <stdbool.h> //true와 false

#define MAX_SIZE 10000 //입력 최대 크기
int arr[MAX_SIZE]; //배열 생성
int high = -1; //고점 초기화

int full()
{
	if (high >= MAX_SIZE - 1)
		return true; // 1
	else
		return false; //0
}

int size()
{
	return (high + 1); //묶어주는 편이 양호
}

void push(int x)
{	
	high = high + 1;
	arr[high] = x;
}

int empty()
{
	if (high < 0)
		return true;
	else
		return false;
}

int pop()
{
	if (empty() == true)
		return -1;
	//else
		//return arr[high]; -> 리턴을 먼저하면 함수가 즉시 반환되기에
		//high = high - 1; -> 뒤의 고점을 빼는 부분이 실행이 안된다

	else
	{
		int val = arr[high]; //먼저 push로 입력받은 val값을 고점 값에 대입 후
		high = high - 1; //
		return val;
	}
}

int top()
{
	if (empty() == true)
		return -1;
	else
		return arr[high];
}

int main()
{	
	int N, i, val; //val은 push X 명령의 X에 해당하는 정수
	char COMMAND[6]; //매 줄마다 입력하는 명령 문자열
	scanf("%d", &N);
	for (i = 0; i < N; i++) //첫 줄 입력의 수만큼 명령을 매 줄마다 반복
	{
		scanf("%s", &COMMAND);
		
		if (strcmp(COMMAND, "push") == 0) //
		{
			scanf("%d", &val);
			push(val);
		}
		else if (strcmp(COMMAND, "pop") == 0) //
			printf("%d\n", pop());
		else if (strcmp(COMMAND, "size") == 0) //
			printf("%d\n", size());
		else if (strcmp(COMMAND, "empty") == 0) //
			printf("%d\n", empty());
		else if (strcmp(COMMAND, "top") == 0) //
			printf("%d\n", top());
	}
	
	return 0;
}

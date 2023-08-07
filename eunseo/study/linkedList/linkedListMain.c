#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

int main(void)
{
	char command[11];
	int x;
	int idx;
	while (1)
	{
		scanf("%s", command);
		if (strcmp(command, "exit") == 0)
		{
			printf("exit program\n");
			break;
		}
		else if (strcmp(command, "add") == 0)
		{
			scanf("%d", &x);
			printf("%d를 삽입합니다.\n", x);
			add(x);
		}
		else if (strcmp(command, "print_all") == 0)
		{
			printf("모든 노드를 출력합니다.\n");
			print_all();
		}
		else if (strcmp(command, "del") == 0)
		{
			scanf("%d", &x);
			printf("%d를 삭제합니다.\n", x);
			del(x);
		}
		else if (strcmp(command, "insert") == 0)
		{
			scanf("%d %d", &idx, &x);
			printf("%d번째에 %d값을 삽입합니다.\n", idx, x);
			insert(idx, x);
		}
		else if (strcmp(command, "delete_all") == 0)
		{
			printf("모든 노드를 삭제했습니다.\n");
			del_all();
		}
		else if (strcmp(command, "reverse") == 0)
		{
			printf("연결리스트를 역순으로 변경했습니다\n");
			reverse();
		}
		else
		{
			printf("명령어를 다시 확인해주세요\n");
		}
	}
}

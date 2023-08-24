#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct graph
{
	int verCount; //정점의 개수
	int** arr; //동적 할당 된 2차원 배열의 주소 저장
}graph;

void graphInit(graph* p, int count) //2차원 배열 생성
{
	int i;
	p->verCount = count;
	p->arr = (int**)malloc(sizeof(int*) * count);

	for (i = 0; i < count; i++)
	{
		p->arr[i] = (int*)calloc(count, sizeof(int)); 
		//calloc(개수, 바이트 크기) : '바이트크기'만큼 '개수'개의 메모리를 할당하여 0으로 초기화
	}
}
void addDirectedEdge(graph* p, int k1, int k2) //방향 그래프의 간선 weight 저장
{
	p->arr[k1][k2] = 1;
}

void addUndirectedEdge(graph* p, int k1, int k2) //무방향 그래프의 간선 weight(=1) 저장
{
	p->arr[k1][k2] = 1;
	p->arr[k2][k1] = 1;
}

void display(graph* p)
{
	int i, j;

	printf("\n\n *** 간선 연결 현황 ***\n\n");
	for (i = 0; i < p->verCount; i++) //vertex의 개수만큼 반복
	{
		printf("출발지 %d => ", i);
		for (j = 0; j < p->verCount; j++)
		{
			printf("%d ", p->arr[i][j]);
		}
		printf("\n");
	}
}

void memoryFree(graph* p)
{
	int i;
	for (i = 0; i < p->verCount; i++)
	{
		printf("%d행 동적 메모리 해제\n", i);
		free(p->arr[i]); //free(포인터); 포인터가 가리키는 메모리가 해제
	}

	free(p->arr);
	printf("포인터 배열 동적 메모리 해제\n");
}

int main()
{
	graph grp1; //무방향그래프
	graph grp2; //방향그래프

	graphInit(&grp1, 4); //구조체, 정점의 개수
	graphInit(&grp2, 4); //구조체, 정점의 개수

	addUndirectedEdge(&grp1, 0, 1); //vertex 0 - vertex 1 (무방향그래프)
	addUndirectedEdge(&grp1, 0, 2); //vertex 0 - vertex 2
	addUndirectedEdge(&grp1, 1, 2); //vertex 1 - vertex 2
	addUndirectedEdge(&grp1, 2, 3); //vertex 2 - vertex 3

	addDirectedEdge(&grp2, 0, 1); //vertex 0 -> vertex 1 (방향그래프)
	addDirectedEdge(&grp2, 0, 2); //vertex 0 -> vertex 2
	addDirectedEdge(&grp2, 1, 2); //vertex 1 -> vertex 2
	addDirectedEdge(&grp2, 2, 3); //vertex 2 -> vertex 3
  
	display(&grp1);
	display(&grp2);

	memoryFree(&grp1); //메모리 해제
	memoryFree(&grp2);

	return 0;
}

//언어 C99, 메모리 5032KB, 시간 12ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
int** arr;
int* map;
int n, m, v; //정점 개수, 간선 개수, 탐색 시작 정점 번호
int* visited; //방문정보
void BFS(int startNode)
{
	int queue[MAX];
	int front = 0;
	int rear = 0; //큐
	int vertex; //큐에서 꺼낸 노드
	
	visited = (int*)malloc(sizeof(int) * (n + 1));
	memset(visited, 0, sizeof(int) * (n + 1));

	//큐에 첫 노드 삽입 & 해당 노드 방문처리
	front += 1;
	queue[front % MAX] = v;
	visited[v] = 1;
	while (front != rear) //큐가 빌 때 까지
	{
		rear += 1;
		vertex = queue[rear % MAX];
		printf("%d ", vertex);
		//printf("front : %d rear : %d\n", front, rear);
		for (int i = 1; i <= n; i++)
		{
			//printf("arr : %d, visited : %d\n", arr[vertex][i], visited[i]);
			if (arr[vertex][i] == 1 && visited[i] == 0) // 연결이 되어있고 방문한 적이 없으면
			{
				front += 1;
				queue[front % MAX] = i;
				visited[i] = 1;
			}
		}
	}
	printf("\n");
}

void DFS(int startNode)
{
	int stack[MAX];
	int pos = -1;
	int vertex; //스택에서 꺼낸 노드
	int* check;
	visited = (int*)malloc(sizeof(int) * (n + 1));
	check = (int*)malloc(sizeof(int) * (n + 1));
	memset(visited, 0, sizeof(int) * (n + 1));
	memset(check, 0, sizeof(int) * (n + 1));
	//스택에 시작점 저장
	pos = pos + 1;
	stack[pos] = startNode;
	while (pos != -1) //스택이 빌 때 까지
	{
		vertex = stack[pos];
		pos = pos - 1;
		if (check[vertex] == 0)
		{
			printf("%d ", vertex);
			check[vertex] = 1;
		}
		for (int i = n; i >= 1; i--) //정점 번호가 작은 것 부터 방문하므로 큰 vertex부터 stack에 push
		{
			if (arr[vertex][i] == 1 && check[i] == 0)
			{
				pos = pos + 1;
				stack[pos] = i;
			}
		}
	}
	printf("\n");
}


int main(void)
{
	int v1, v2; //정점 번호
	scanf("%d %d %d", &n, &m, &v);
	arr = (int**)malloc(sizeof(int*) * (n + 1));
	map = (int*)malloc(sizeof(int) * (n + 1) * (n + 1)); // n+1 * n+1 의 배열 선언
	memset(map, 0, (n + 1) * (n + 1) * sizeof(int));
	for (int i = 0; i <= n; i++)
	{
		arr[i] = &map[i * (n + 1)];
	} 
	while (m--)
	{
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1; 
	} //2차원 배열을 이용하여 그래프 표현
	DFS(v);
	BFS(v);

  free(map);
  free(arr);
}

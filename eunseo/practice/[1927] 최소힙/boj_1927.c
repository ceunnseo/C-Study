//언어 C, 메모리 1388KB, 시간 20ms
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 100000

typedef struct heap
{
	int arr[MAX];
	int size;
}heap;

void heapInit(heap* h) //초기화
{
	h->size = 0;
}


/*추가 enqueue
* 1. 맨 마지막 노드에 새로운 데이터 추가
* 2. 부모노드 값을 비교하여 부모가 더 크면 부모와 자식 swap
* 3. 2를 반복
*/
void enqueue(heap * h, int value)
{
	int cur; //현재 노드
	int parent; //나와 비교할 부모 노드
	int temp; //swap을 위한 임시 변수
	if (h->size + 1 > MAX) return; //꽉 찬 경우
	h->arr[h->size] = value; //1.맨 마지막 노드에 새 데이터 추가
	cur = h->size; // 자식 노드의 idx 저장
	parent = (h->size - 1) / 2; //부모노드 idx 설정
	h->size += 1; //insert했으니까 크기 1 증가

	//부모노드 없을 때까지 & 부모노드 < 자식노드인 상황 만날 때 까지 swap 반복
	while (cur > 0 && h->arr[cur] < h->arr[parent]) 
	{
		temp = h->arr[cur];
		h->arr[cur] = h->arr[parent];
		h->arr[parent] = temp; //2. 부모 자식 교환

		cur = parent; //자식노드 idx 재설정
		parent = (parent - 1) / 2; //부모노드 idx 재설정
	}
}


/*힙 데이터의 삭제
* 1. 루트 노드 삭제
* 2. 맨 마지막 노드를 루트 노드 위치에 올려줌
* 3. 양쪽 자식 노드와 값을 비교하여, 더 작은 자식노드와 위치 변경
* 4. 3을 반복
* 5. 자식노드가 없거나 자식 노드가 작지 않은 경우 종료
*/
int dequeue(heap* h)
{
	int cur = 0; //현재 노드의 인덱스 (root부터)
	int res; //dequeue할 때 원소값
	int left, right; //양쪽 자식노드 인덱스
	int temp; //swap을 위한 임시 변수
	int small = 0; //왼쪽, 오른쪽 자식 중에 더 작은 노드의 idx를 저장할 변수
	if (h->size <= 0)
	{
		return 0;
	}
	res = h->arr[0]; //1. 루트 노드 삭제

	h->size -= 1; 
	h->arr[0] = h->arr[h->size]; //2. 맨 마지막 노드를 루트 노드 위치로

	left = (cur * 2) + 1;
	right = (cur*2) + 2;
	
	while (left < h->size) //자식노드가 있으면 swap 과정 반복
	{
		if (h->arr[left] < h->arr[small])
		{
			small = left;
		}
		if (h->arr[right] < h->arr[small])
		{
			small = right;
		} //왼쪽, 오른쪽 중에서 부모보다 더 작은 노드의 idx를 저장

		if (cur == small) break; //small이 변경 안 됐으면 swap 종료
		else //swap
		{
			temp = h->arr[cur];
			h->arr[cur] = h->arr[small];
			h->arr[small] = temp; //부모와 더 작은 자식 swap

			cur = small; //부모 idx 변경
			left = (cur * 2) + 1; //왼쪽 노드 idx 재설정
			right = left + 1; //오른쪽 idx 재설정
		}
	}
	return res;
}



int main(void)
{
	heap h;
	heapInit(&h);
	int n; //연산의 개수
	int x; //연산에 대한 정보
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &x);
		if (x == 0) //dequeue
		{
			printf("%d\n", dequeue(&h));
		}
		else //enqueue
		{
			enqueue(&h, x);
		}
	}
}

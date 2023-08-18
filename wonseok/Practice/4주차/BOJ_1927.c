#define _CRT_SECURE_NO_WARNINGS //visual studio 사용자 한정 추가

#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100001 //N의 범위

typedef struct
{
    int heap[MAX_HEAP_SIZE];
    int size;
} MinHeap; //구조체 설정

void swap(int* a, int* b)
{
    int tmp = *a; //임시 변수 통해서 값이 지워지는 경우 방지
    *a = *b; //포인터가 지칭하는 주소를 서로 바꾸기
    *b = tmp;
}

void push(MinHeap* heap, int value)
{    if (heap->size >= MAX_HEAP_SIZE)
    {
        printf("Heap is full.\n");
        return; //가득 차면 아무것도 넣지 말고 경고 메시지
    }

    heap->heap[heap->size] = value; //마지막 노드에 추가할 값 지정
    int current = heap->size;
    int parent = (current - 1) / 2; //부모노드 정의

    while (current > 0 && heap->heap[current] < heap->heap[parent]) //주소값 가져온 후 최소 힙에 맞게 부모>자식이면 바꿔야
    {
        swap(&heap->heap[current], &heap->heap[parent]); //위의 조건 내에서 바꾸기
        current = parent; //원래 부모 노드의 인덱스를 자식 순번으로 덮어써서 자식 노드의 순번을 변경
        parent = (current - 1) / 2; //역시 부모노드에 대한 순번 변경
    }

    heap->size++; //사이즈 추가
}
/*
1. 비어있으면, 경고문 출력
2. 아니면 채워넣기
    최소값을 찾아내는 과정 필요
    부모 자식 노드 정의하고 비교하는 과정 필요
*/
int pop(MinHeap* heap)
{
    if (heap->size <= 0) //비어있는 경우
    {
        printf("Heap is empty.\n");
        return 0;
    }

    int root = heap->heap[0]; //루트노드를 최소값으로 지정, 최소 힙 성질 이용
    heap->size--;
    heap->heap[0] = heap->heap[heap->size]; //마지막 노드를 삭제하는 힙의 성질 이용

    int current = 0;
    while (1) {
        int leftChild = current * 2 + 1; //좌측 자식 노드
        int rightChild = current * 2 + 2; //우측 자식 노드
        int smallest = current; //최소값 갱신

        if (leftChild < heap->size && heap->heap[leftChild] < heap->heap[smallest]) { //왼쪽 자식과 비교
            smallest = leftChild; //최소값 갱신
        }
        if (rightChild < heap->size && heap->heap[rightChild] < heap->heap[smallest]) { //오른쪽 자식과 비교
            smallest = rightChild; //최소값 갱신
        }

        if (smallest != current) {
            swap(&heap->heap[current], &heap->heap[smallest]);
            current = smallest;
        }
        else {
            break;
        }
    }

    return root;
}

int main()
{
    int N;
    scanf("%d", &N); // 첫 줄에 입력받을 줄 선택

    MinHeap heap;
    heap.size = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);

        if (x == 0) //0인 x에 대해서는 최소값에 삭제하기
        {
            if (heap.size == 0)
            {
                printf("0\n");
            } //비울게 없음
            else
            {
                printf("%d\n", pop(&heap));
            } //최소값 비워내기
        }
        else
        {
            push(&heap, x); //0이 아닌 x에 대해서는 힙에 추가하기
        }
    }

    return 0;
}

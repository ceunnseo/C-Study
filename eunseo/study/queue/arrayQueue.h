#define SIZE 1001 // 1000개 사용
typedef int Data;
typedef struct queue
{
	int front;
	int rear;
	Data arr[SIZE];
};
void queueInit(struct queue* q); //큐 초기화

void enqueue(struct queue* q, Data x); 
Data dequeue(struct queue* q); 

int queueSize(struct queue* q); //큐의 크기 리턴
int is_emtpy(struct queue* q); //큐가 비었으면 1, 아니면 0 리턴 
int is_full(struct queue* q); //큐가 꽉 찼으면 1, 아니면 0 리턴

Data front(struct queue* q); //큐의 front값 리턴
Data back(struct queue* q); //큐의 rear값 리턴
void printQueue(struct queue* q); //큐의 모든 원소 출력 함수


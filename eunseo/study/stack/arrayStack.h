#define SIZE 1000
typedef struct stack
{
	int pos;
	int arr[SIZE];
};
void stackInit(struct stack* s); //스택 초기화

void push(struct stack* s, int value); //값을 스택에 push하는 함수
int pop(struct stack* s); //pop 함수

int size(struct stack* s); //스택의 크기 리턴
int empty(struct stack* s); //스택이 비었으면 1, 아니면 0 리턴 

int top(struct stack* s); //스택의 최상단 값 리턴

void printStack(struct stack* s); //스택의 모든 원소 출력 함수

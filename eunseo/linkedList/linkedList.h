#pragma once
typedef struct node
{
	int data;
	struct node* next;
}node;
void add(int num); //data가 num인 노드를 삽입
void print_all(); //연결리스트의 모든 노드 출력
void del(int target); //target이라는 data를 가진 노드를 삭제
void insert(int idx, int number); //idx번째에 number라는 data를 가진 노드를 연결
void del_all(); //모든 노드 삭제
void reverse(); //연결리스트 노드를 역순으로 변경

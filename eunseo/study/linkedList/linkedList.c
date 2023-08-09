#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
struct node* head = NULL;
struct node* tail = NULL;
void add(int num)
{
	struct node* newnode = (struct node*)malloc(sizeof(node));
	newnode->data = num;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
		tail = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
}

void print_all()
{
	struct node* cur = head;
	if (head == NULL) printf("노드가 없어요\n");
	else
	{
		while (cur->next != NULL)
		{
			printf("%d\n", cur->data);
			cur = cur->next;
		}
		printf("%d\n", cur->data);
	}
}

void del(int target)
{
	struct node* cur = head;
	struct node* tmp;
	if (head->data == target) //맨 앞에를 지움
	{
		tmp = head;
		head = tmp->next;
		free(tmp);
	}
	else
	{
		cur = head;
		while (cur->next != NULL)
		{
			if (cur->next->data == target)
			{
				tmp = cur->next;
				cur->next = tmp->next;
				free(tmp);
				return;
			}
			cur = cur->next;
		}
	}
}

void insert(int idx, int number)
{
	int index = 0;
	struct node* newnode = (struct node*)malloc(sizeof(node));
	newnode->data = number;
	struct node* cur = head;
	if (idx == 0)
	{
		newnode->next = head;
		head = newnode;
		return;
	}
	else
	{
		while (cur->next != NULL)
		{
			index++;
			cur = cur->next;
			if (index == idx - 1)
			{
				newnode->next = cur->next;
				cur->next = newnode;
				return;
			}
		}
		newnode->next = cur->next;
		cur->next = newnode;
	}
}

void del_all()
{
	struct node* cur = head; //삭제할 노드를 가리킴
	if (head == NULL) return; //삭제할 게 없으니 종료
	while (head != NULL)
	{
		head = head->next;
		free(cur);
		cur = head;
	}
}

void reverse() 
{
	struct node* cur = head;
	struct node* prev = NULL;
	while (cur != NULL)
	{
		cur = head->next;
		head->next = prev;
		prev = head;
		head = cur;
	}
	head = prev;
}

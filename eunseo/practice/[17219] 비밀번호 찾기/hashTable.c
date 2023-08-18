/*
웹사이트(key)와 비밀번호(value)를 공백 기준으로 입력받고, 웹사이트에 따라 비밀번호를 출력해주는 프로그램
chaining 방식으로 hashTable 생성

언어 C99, 메모리 106524KB, 시간 448ms
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node //해시테이블을 구성할 slot 구조체 생성
{
	char key[500]; //웹사이트 
	char value[21]; //비밀번호
	struct node* next;
}node;
typedef struct hash //해시테이블 생성
{
	char** head;
	int size;
}hash;
void hashInit(hash* h, int size)
{
	h->head = (node**)calloc(size, sizeof(node));
	h->size = size;
}
int hashFunc(hash* h, const char* website)
{
	int tot = 0;
	for (int i = 0; i < strlen(website); i++)
	{
		tot += website[i];
	}
	return tot % h->size;
}
void hashAdd(hash* h, const char* website, const char * pw)
{
	int index = hashFunc(h, website);
	node* newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->key,website);
	strcpy(newnode->value, pw);
	newnode->next = NULL;
	if (h->head[index] == NULL)
	{
		h->head[index] = newnode;
		return;
	}
	newnode->next = h->head[index];
	h->head[index] = newnode;
	return;
}
void printAll(hash* h)
{
	node* cur;
	for (int i = 0; i < h->size; i++)
	{
		cur = h->head[i];
		printf("hash[%d] =>\n", i);
		while (cur != NULL)
		{
			printf("key : %s, value : %s\n", cur->key, cur->value);
			cur = cur->next;
		}
	}
}
void search(hash* h, const char* key)
{
	node* cur;
	int index = hashFunc(h, key);
	cur = h->head[index];
	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
		{
			printf("password : %s\n", cur->value);
			return;
		}
		cur = cur->next;
	}
}
int main(void)
{
	int n, m;
	char website[500];
	char pw[21];
	hash ht;
	scanf("%d %d", &n, &m);
	hashInit(&ht, n);

	for(int i = 0; i < n; i++)
	{
		scanf("%s %s", website, pw);
		hashAdd(&ht, website, pw);
	}

	for (int i = 0; i < m; i++)
	{
		scanf("%s", website);
		search(&ht, website);
	}
	
}

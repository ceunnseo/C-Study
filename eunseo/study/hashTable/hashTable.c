//chaining방식으로 구현한 hashTable

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char key[30]; //이름
	char value[30]; //전화번호
	struct node* next;
}node;
typedef struct hashTable
{
	node** head; // 포인터 배열의 주소를 저장할 변수
	int size;
}hashTable;

void hashInit(hashTable* p, int size)
{
	p->head = (node**)calloc(size, sizeof(node*));
	//모두 0으로 초기화
	p->size = size;
}

int hashFunction(const char* key, int size)
{
	int tot= 0;
	for (int i = 0; i < strlen(key); i++)
	{
		tot += key[i];
	}
	return tot%size;
}

void hashAdd(hashTable* p, const char* key, const char*value)
{
	int hashCode = hashFunction(key, p->size);
	node* newnode;
	newnode = (node*)malloc(sizeof(node));
	strcpy(newnode->key, key);
	strcpy(newnode->value, value);
	newnode->next = NULL; //새 노드 생성

	if (p->head[hashCode] == NULL)
	{
		p->head[hashCode] = newnode;
		return;
	}
	newnode->next = p->head[hashCode];
	p->head[hashCode] = newnode;
}


int hashFind(hashTable* p, const char* targetKey) //검색
{
	int idx = hashFunction(targetKey, p->size);
	node* cur;
	cur = p->head[idx];
	while (cur != NULL)
	{
		if (strcmp(cur->key,targetKey) == 0)
		{
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

void display(hashTable* p) //출력
{
	node* cur;
	for (int i = 0; i < p->size; i++)
	{
		cur = p->head[i];
		printf("head[%d]\n", i);
		while (cur != NULL)
		{
			printf("key : %s, value : %s\n", cur->key, cur->value);
			cur = cur->next;
		}
		printf("\n");
	}
}

void hashRemove(hashTable* p, const char* targetKey)
{
	int hashValue = hashFunction(targetKey, p->size);
	node* cur;
	node* del;
	if (p->head[hashValue] == NULL) //데이터 자체가 없는 경우
	{
		return;
	}

	cur = p->head[hashValue];
	if (strcmp(cur->key,targetKey) == 0) //맨 앞에 있는 경우
	{
		del = cur;
		p->head[hashValue] = p->head[hashValue]->next;
		free(del);
		return;
	}
	while (cur->next != NULL)
	{
		if (strcmp(cur->key, targetKey) == 0)
		{
			del = cur->next;
			cur->next = del->next;
			free(del);
			return;
		}
		cur = cur->next;
	}
}

void memoryFree(hashTable* p)
{
	node* del;
	for (int i = 0; i < p->size; i++)
	{
		while (p->head[i] != NULL)
		{
			del = p->head[i];
			p->head[i] = p->head[i]->next;
			free(del);
		}
	}
	free(p->head);
}

int main(void)
{
	hashTable ht;
	hashInit(&ht, 4); //사이즈가 7인 해시테이블 생성
	hashAdd(&ht, "sung", "010-1234-5678");
	hashAdd(&ht, "jin", "010-1111-1111");
	hashAdd(&ht, "hee", "010-2222-2222");
	hashAdd(&ht, "min", "010-3333-3333");
	display(&ht);

	if (hashFind(&ht, "kim"))
	{
		printf("존재함\n");
	}
	else
	{
		printf("존재하지 않음\n");
	}

	if (hashFind(&ht, "jin"))
	{
		printf("존재함\n");
	}
	else
	{
		printf("존재하지 않음\n");
	}

	hashRemove(&ht, "eunseo");
	hashRemove(&ht, "jin");
	hashRemove(&ht, "min");
	display(&ht);
	memoryFree(&ht); //전체 노드 free
	return 0;
}

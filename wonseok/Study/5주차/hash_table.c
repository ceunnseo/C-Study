#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct set
{
	int key;
	int data;
};

struct set* array; //10의 capacity를 가진 해시 테이블 임의로 생성
int capacity = 10;
int size = 0;

int hashFunction(int key)
{
	return (key % capacity); //0부터 capacity - 1 까지의 값이 주소로 설정됨
}

/*
0. n이 소수인지 확인하는 함수
1. 0이거나 1인 경우 -> 예외
2. 2부터 n의 제곱근까지 -> 소수 판별 기준
*/
int checkPrime(int n)
{
	int i;
	
  if (n == 1 || n == 0)
	{
		return 0;
	}
	
  for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)	
		{
			return 0;
		}

		return 1;
	}
}

int getPrime(int n)
{
	if (n % 2 == 0)
	{
		n++;
	}
	
  while (!checkPrime(n))
	{
		n += 2;
	}
	
  return n;
}

void init_array()
{
	capacity = getPrime(capacity);
	array = (struct set*)malloc(capacity* sizeof(struct set));
	
  for (int i = 0; i < capacity; i++)
	{
		array[i].key = 0;
		array[i].data = 0;
	}
}

void insert(int key, int data)
{
	int index = hashFunction(key);
	
  if (array[index].data == 0)
	{
		array[key].key = key;
		array[key].data = data;
		size++;
			printf("\n (%d) is inserted\n", key);
	}

	else if (array[index].key == key)
	{
		array[index].data = data;
	}

	else
	{
		printf("\n collision occured \n"); //해시 충돌 발생 => h(k1) == h(k3)..
	}
}

/*
1. 삭제할 값이 없는 경우
2. 있는 경우 삭제하고 사이즈 감소, 출력
*/
void remove_element(int key)
{
	int index = hashFunction(key);

	if (array[index].data == 0)
	{
		printf("\n This key does not exist \n");
	}

	else
	{
		array[index].key = 0;
		array[index].data = 0;
		size--;
		printf("\n Key (%d) has been removed \n", key);
	}
}

void display()
{
	int i;
	for (i = 0; i < capacity; i++)
	{
		if (array[i].data == 0)
		{
			printf("\n array[%d]: / ", i); //입력되지 않은 데이터에 대해서 보여주는 창
		}
		
    else
		{
			printf("\n key: %d array[%d]: %d \t", array[i].key, i, array[i].data);
		}
	}
}

int size_of_hashtable()
{
	return size;
}

int main()
{
	int choice, key, data, n;
	int c = 0; //입력값 초기화
	init_array(); //배열 초기화

	do //안내창 출력
	{
		printf("1.Insert item in the Hash Table"
			"\n2.Remove item from the Hash Table"
			"\n3.Check the size of Hash Table"
			"\n4.Display a Hash Table"
			"\n\n Please enter your choice: ");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1: //삽입

			printf("Enter key -:\t");
			scanf("%d", &key);
			printf("Enter data -:\t");
			scanf("%d", &data);
			insert(key, data);

			break;

		case 2: //삭제

			printf("Enter the key to delete-:");
			scanf("%d", &key);
			remove_element(key);

			break;

		case 3: //크기 출력

			n = size_of_hashtable();
			printf("Size of Hash Table is-:%d\n", n);

			break;

		case 4: //전체 해시 테이블 출력

			display();

			break;

		default: //잘못된 입력

			printf("Invalid Input\n");
		}

		printf("\nDo you want to continue (press 1 for yes): ");
		scanf("%d", &c);

	} while (c == 1); //1을 선택하면 위의 과정 다시 반복
}

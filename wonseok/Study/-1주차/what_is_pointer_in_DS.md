[교안] https://youtu.be/hWnLq-dg7B4<br>
* C언어 자료구조에서 포인터는?<br>
1. pointer는 메모리 주소를 저장하기 위한 변수이다.
2. 간접 지정 연산으로 대상 메모리에 접근한다.

* C언어 자료구조에서 함수의 포인터의 의미란?<br>
1. 함수 이름은 그 자체가 주소이다.
2. 간결한 코드를 만들 수 있다.
3. 공동 작업에서 포인터 함수는 기준을 정해준다.

```
/*함수포인터
*/
#include <stdio.h>

int test(int a)
{
	printf("test(): Hello World\n");
	return 0;
}

int main(void)
{
	//test(5);
	int (*pfTest)(int) = test; //함수 포인터 사용

	pfTest(5);
	return 0;
}
```

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binarytree.h"

int main(void)
{
	treenode* bt1 = makenode(1); //1이라는 값을 가진 트리 노드 bt1을 생성
	treenode* bt2 = makenode(17);
	treenode* bt3 = makenode(48);
	treenode* bt4 = makenode(5);
	treenode* bt5 = makenode(23);
	treenode* bt6 = makenode(37);
	treenode* bt7 = makenode(50);

	printf("%d \n", getData(bt1)); 


	setData(bt1, 30); //bt1의 트리 노드 값을 30으로 재설정

	makeLeftSubTree(bt1, bt2); //bt1의 왼쪽에 bt2를 연결
	makeRightSubTree(bt1, bt3); //bt1의 오른쪽에 bt3을 연결
	makeLeftSubTree(bt2, bt4);// bt2의 왼쪽에 bt4를 연결
	makeRightSubTree(bt2, bt5); //bt2의 오른쪽에 bt5 연결
	makeLeftSubTree(bt3, bt6); //bt3의 왼쪽에 bt6연결 
	makeRightSubTree(bt3, bt7); //bt3의 오른쪽에 bt7연결

	printf("%d\n", getData(bt1)); // bt1의 값 출력 -> 10
	printf("%d\n", getData(getLeftSubTree(bt1))); // bt1의 왼쪽 트리(bt2)의 값을 출력 -> 20
	printf("%d\n", getData(getRightSubTree(bt1))); // bt1의 오른쪽 트리 (bt3)의 값을 출력 -> 30
	printf("%d\n", getData(getLeftSubTree(getLeftSubTree(bt1)))); // bt4의 값 출력
	printf("%d\n", getData(getRightSubTree(getLeftSubTree(bt1)))); //bt5의 값 출력

	printf("전위 순회 : ");
	preorder(bt1);
	printf("\n");

	printf("중위 순회 : ");
	inorder(bt1);
	printf("\n");

	printf("후위 순회 : ");
	postorder(bt1);
	printf("\n");


	//bt1의 왼쪽 트리를 변경
	treenode* bt8 = makenode(50);
	treenode* bt9 = makenode(60);
	treenode* bt10 = makenode(70);
	makeLeftSubTree(bt8, bt9);
	makeRightSubTree(bt8, bt10);
	makeLeftSubTree(bt1, bt8);

	printf("전위 순회 : ");
	preorder(bt1);
	printf("\n");

	return 0;
}
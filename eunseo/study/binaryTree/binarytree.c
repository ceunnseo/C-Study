#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"

treenode* makenode(Data value) //트리의 노드를 만드는 함수
{
	treenode* node = (treenode*)malloc(sizeof(treenode));
	node->left = NULL;
	node->right = NULL;
	node->data = value;
	return node;
}
Data getData(treenode* t)//트리의 data값을 가져오는 함수
{
	return t->data;
}
void setData(treenode* t, Data data) //트리노드 t의 data값을 설정해주는 함수
{
	t->data = data;
}

treenode* getLeftSubTree(treenode* t) //트리노드의 왼쪽 트리를 리턴하는 함수
{
	return t->left;
}
treenode* getRightSubTree(treenode* t) //트리노드의 오른쪽 트리를 리턴하는 함수
{
	return t->right;
}

void makeLeftSubTree(treenode* mainTree, treenode* sub) //mainTree의 왼쪽에 sub 트리를 연결하는 함수
{
	if (mainTree->left != NULL)
	{
		//free(mainTree->left);
		delTree(mainTree->left); //왼쪽 트리 모두 삭제
	}
	mainTree->left = sub;
}

void makeRightSubTree(treenode* mainTree, treenode* sub) //mainTree의 오른쪽에 sub 트리를 연결하는 함수
{
	if (mainTree->right != NULL)
	{
		//free(mainTree->right);
		delTree(mainTree->right);
	}
	mainTree->right = sub;
}

void preorder(treenode* t) //전위 : root -> left -> right
{
	if (t == NULL)
	{
		return;
	}
	printf("%d ", t->data);
	preorder(t->left);
	preorder(t->right);
}
void inorder(treenode* t) //중위 : left -> root -> right
{
	if (t == NULL)
	{
		return;
	}
	inorder(t->left);
	printf("%d ", t->data);
	inorder(t->right);
}
void postorder(treenode* t) //후위 : left -> right -> root
{
	if (t == NULL)
	{
		return;
	}
	postorder(t->left);
	postorder(t->right);
	printf("%d ", t->data);
}

void delTree(treenode* t)
{
	if (t == NULL)
		return;
	delTree(t->left);
	delTree(t->right);
	printf("delete : %d \n", t->data);
	free(t);
}
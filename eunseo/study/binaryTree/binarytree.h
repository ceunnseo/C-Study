#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int Data;

typedef struct treenode
{
	Data data;
	struct treenode* left;
	struct treenode* right;
}treenode; //트리노드를 정의한 구조체 선언

treenode* makenode(Data value); //트리의 노드를 만드는 함수
Data getData(treenode* t); //트리의 data값을 가져오는 함수
void setData(treenode* t, Data data); //트리노드 t의 data값을 설정해주는 함수

treenode* getLeftSubTree(treenode* t); //트리노드의 왼쪽 트리를 리턴하는 함수
treenode* getRightSubTree(treenode* t); //트리노드의 오른쪽 트리를 리턴하는 함수

void makeLeftSubTree(treenode* mainTree, treenode* sub); //mainTree의 왼쪽에 sub 트리를 연결하는 함수
void makeRightSubTree(treenode* mainTree, treenode* sub); //mainTree의 오른쪽에 sub 트리를 연결하는 함수

void delTree(treenode* t); //이진트리 소멸 함수

void preorder(treenode* t); //전위순회 : root -> left -> right
void inorder(treenode* t); //중위순회 : left -> root -> right
void postorder(treenode* t); //후위순회 : left -> right -> root

#endif

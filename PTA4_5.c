#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode{
	int data;
	struct AVLNode *Left;
	struct AVLNode *Right;
	int Height;
}*AVLTree;
AVLTree SingleLeftRotation(AVLTree A);//左单旋，在左子节点上
AVLTree SingleRightRotation(AVLTree A);//右单旋，在右子节点上
AVLTree DoubleLeftRightRotation(AVLTree A);//左右双旋
AVLTree DoubleRightLeftRotation(AVLTree A);//右左双旋
int GetHeight(AVLTree T);
AVLTree Insert(AVLTree T, int X);
int Max(int a, int b);
int main()
{
	int N;
	scanf("%d", &N);
	int node;
	AVLTree T = NULL;
	for(int i=0; i<N; i++){
		scanf("%d", &node);
		T = Insert(T, node);
	}
	if(T){
		printf("%d\n", T->data);
	}
	return 0;
}

int Max(int a, int b)
{
	return a>b?a:b;
}

AVLTree SingleLeftRotation(AVLTree A){
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Left), A->Height) + 1;
	return B;
}

int GetHeight(AVLTree T)
{
	if(!T)
		return -1;
	return T->Height;
}

AVLTree SingleRightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
	B->Height = Max(GetHeight(B->Right), A->Height) + 1;
	return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
	A->Left = SingleRightRotation(A->Left);
	return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
	A->Right = SingleLeftRotation(A->Right);
	return SingleRightRotation(A);
}

AVLTree Insert(AVLTree T, int X)
{
	if(!T){
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->data = X;
		T->Left = T->Right = NULL;
		T->Height = 0;
	}
	else if(X < T->data){
		//插入左子树
		T->Left = Insert(T->Left, X);
		//如果需要左旋
		if(GetHeight(T->Left) - GetHeight(T->Right) == 2){
			if(X < T->Left->data)
				T = SingleLeftRotation(T);
			else
				T = DoubleLeftRightRotation(T);
		}
	}
	else if(X > T->data){
		T->Right = Insert(T->Right, X);
		if(GetHeight(T->Left) - GetHeight(T->Right) == -2){
			if(X > T->Right->data)
				T = SingleRightRotation(T);
			else
				T = DoubleRightLeftRotation(T);
		}
	}
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
	return T;
}

































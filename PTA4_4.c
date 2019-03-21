/*是否同一棵二叉搜索树*/
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int v;
	struct TreeNode *Left;
	struct TreeNode *Right;
	int flag;//用于判断
}*Tree;

Tree MakeTree(int N);//构造搜索树
Tree Insert(Tree T, int V);//往树上插入节点
Tree NewNode(int V);//新建结点
int check(Tree T, int V);//检查顺序访问结点是否相同
int Judge(Tree T, int N);//判断是否同一二叉搜索树
void ResetTree(Tree T);//重置树；
void FreeTree(Tree T);//释放树

int main()
{
	int N, L;
	Tree T;

	scanf("%d", &N);
	while(N){
		scanf("%d", &L);
		T = MakeTree(N);//构造搜索树
		for(int i=0; i<L; i++){
			if(Judge(T, N))//判别是不是其序列
				printf("Yes\n");
			else
				printf("No\n");
			ResetTree(T);
		}
		FreeTree(T);
		scanf("%d", &N);
	}
	return 0;

}

Tree MakeTree(int N)//N表示节点数
{
	Tree T;
	int V;
	scanf("%d", &V);
	T = NewNode(V);
	for(int i=1; i<N; i++){
		scanf("%d", &V);
		T = Insert(T, V);
	}
	return T;
}

Tree Insert(Tree T, int V)
{
	if(!T)
		T = NewNode(V);
	else{
		if(V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Left, V);
	}
	return T;
}

Tree NewNode(int V)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = NULL;
	T->Right = NULL;
	T->flag = 0;
	return T;
}

int check(Tree T, int V)
{
	if(T->flag){
		if(V > T->v)
			return check(T->Right, V);
		else if(V < T->v)
			return check(T->Left, V);
		else
			return 0;
	}
	else{
		if(V == T->v){
			T->flag = 1;
			return 1;
		}
		else 
			return 0;
	}
}

int Judge(Tree T, int N)
{
	int V;
	int flag = 0;
	scanf("%d", &V);
	if(V!=T->v)
		flag = 1;
	else 
		T->flag = 1;
	for(int i=1; i<N; i++){
		scanf("%d", &V);
		if((!flag) &&check(T, V)==0)
			flag = 1;
	}
	if(flag)
		return 0;
	else
		return 1;
}

void ResetTree(Tree T)
{
	if(T->Left)
		ResetTree(T->Left);
	if(T->Right)
		ResetTree(T->Right);
	T->flag = 0;
}

void FreeTree(Tree T)
{
	if(T->Left)
		FreeTree(T->Left);
	if(T->Right)
		FreeTree(T->Right);
	free(T);
}



























































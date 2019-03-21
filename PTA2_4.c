/*pop sequence*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000

typedef struct stack{
	int Data[MaxSize];
	int top;
	int Capacity;
}*Stack;

Stack CreateStack(int M);/*生成空堆栈*/
int Push(Stack S, int X);/*入栈*/
int IsFull(Stack S);/*判断堆栈满*/
void Pop(Stack S);/*出栈*/
void showStack(Stack S);/*打印栈内元素*/
int IsPossible(int data[], int M, int N);/*判断*/
int Top(Stack S);/*取出栈顶元素*/

int main()
{
	int M, N, K, i, j, data[1000];
	scanf("%d %d %d", &M, &N, &K);
	for(i=0; i<K; i++){
		for(j=0; j<N; j++){
			scanf("%d", &data[j]);
		}
		if(IsPossible(data, M, N))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
	
}

int IsPossible(int data[], int M, int N)
{
	int i;
	int head=0;
	Stack S;
	S = CreateStack(M);
	for(i=1; i<=N; i++){
		if(!Push(S, i)){
			return 0;
		}
		while(Top(S) == data[head])/*循环判断列中元素与栈顶元素是否相等，若相等在出栈*/
		{
			Pop(S);
			head++;
		}
	}
	if(head == N)
		return 1;
	else
		return 0;

}

Stack CreateStack(int M)
{
	Stack S = (Stack)malloc(sizeof(struct stack));
	if(S==NULL){
		printf("分配存储空间失败\n");
		return 0;
	}
	S->top = -1;
	S->Capacity = M;
	return S;
}

int IsFull(Stack S)
{
	if(S->top == S->Capacity-1){
		return 1;
	}
	return 0;
}

int Push(Stack S, int X)
{
	if(IsFull(S)){
		return 0;
	}
	S->Data[++(S->top)] = X;
	return 1;
}

void Pop(Stack S)
{
	S->top --;
}

int Top(Stack S)
{
	if(S->top >= 0){
		return S->Data[S->top];
	}
	else
		return -1;
}































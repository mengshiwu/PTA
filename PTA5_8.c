//File Transfer
#include <stdio.h>
#define MaxSize 10001

int S[MaxSize];//数组下标为结点元素，数组数据为父节点下标
void Initialization(int n);
int Find(int X);//找根节点
void Union(int Root1, int Root2);//合并集合
void InputConnection(int num1, int num2);//输入连接
void CheckConnection(int num1, int num2);//检查连接
void StopCheck(int n);

int main()
{
	int n;
	int num1, num2;
	char in;
	scanf("%d", &n);
	Initialization(n);
	while(1){
		scanf("%c", &in);
		if(in == 'S'){
			StopCheck(n);
			break;
		}
		else{
			scanf("%d %d", &num1, &num2);
			if(in == 'I'){
				InputConnection(num1, num2);

			}
			else if(in == 'C'){
				CheckConnection(num1, num2);
			}
		}
	}

	return 0;

}

void Initialization(int n)
{
	for(int i=0; i<n; i++){
		S[i] = -1;
	}

}

void StopCheck(int n)
{
	int count = 0; 
	for(int i=0; i<n; i++){
		if(S[i] < 0)
			count++;
	}
	if(count == 1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n", count);

}

void InputConnection(int num1, int num2)
{
	int Root1, Root2;
	Root1 = Find(num1-1);
	Root2 = Find(num2-1);
	if(Root1 != Root2){
		Union(Root1, Root2);
	}

}

int Find(int X)
{
	for(; S[X]>=0; X=S[X]);
	return X;
}

void Union(int Root1, int Root2)//把节点少的树挂在节点多的树下
{
	if(S[Root2] < S[Root1]){
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;		
	}
		
}

void CheckConnection(int num1, int num2)
{
	int Root1, Root2;
	Root1 = Find(num1-1);
	Root2 = Find(num2-1);
	if(Root1 == Root2){
		printf("yes\n");
	}
	else
		printf("no\n");
}






































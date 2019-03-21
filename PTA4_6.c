//Complete Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int A[1000];
int N;
int T[1000];

int Min(int a, int b);
int GetLeftLength(int N);
int compare(int *a, int *b);
void solve(int ALeft, int ARight, int TRoot);
int compared(const void*a, const void*b);

int main()
{
	int i;
	int output[1000];
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
	qsort(A, N, sizeof(int), compared);
	solve(0, N-1, 0);
	for(i=0; i<N-1; i++){
		printf("%d ", T[i]);
	}
	printf("%d\n", T[N-1]);


	
	return 0;
}

int compared(const void*a, const void*b)
{
	return *(int*)a-*(int*)b;
}

void solve(int ALeft, int ARight, int TRoot)
{
	int n, L;
	int LeftTRoot, RightTRoot;
	n = ARight - ALeft + 1;

	if(n==0)
		return;
	L = GetLeftLength(n);//计算N个节点的树的左子树有多少个节点
	T[TRoot] = A[ALeft + L];
	LeftTRoot = TRoot * 2 + 1;
	RightTRoot = LeftTRoot + 1;
	solve(ALeft, ALeft+L-1, LeftTRoot);
	solve(ALeft+L+1, ARight, RightTRoot); 
}



int GetLeftLength(int N)
{
	int h, x, L;
	h = log(N+1)/log(2);
	x = N - pow(2, h) + 1;
	x = Min(x, pow(2, h-1));
	L = pow(2, h-1) - 1 + x;
	return L;

}

int Min(int a, int b)
{
	return a<b?a:b;
}


































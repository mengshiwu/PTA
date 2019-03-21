//堆中的路径
#include <stdio.h>
#include <stdlib.h>
#define MinData -100000
#define ERROR -1
#define MaxSize 1000

typedef int ElementType;
typedef struct HeapNode{
	ElementType *Data;//存储元素的数组
	int Size;//堆中当前元素个数
}*Heap;

typedef Heap MinHeap;//定义最小堆


MinHeap CreateHeap();//建立堆
int IsFull(MinHeap H);//判断堆满
int Insert(MinHeap H, ElementType X);//将元素X插入最小堆中
int IsEmpty(MinHeap H);//判断堆空
void DispPath(MinHeap H, int node);

int main()
{
	int N, M, element[10000];
	int i, node;
	MinHeap H;
	H = CreateHeap();
	scanf("%d %d", &N, &M);
	for(i=0; i<N; i++){
		scanf("%d", &element[i]);
		Insert(H, element[i]);

	}

	for(i=0; i<M; i++){
		scanf("%d", &node);
		DispPath(H, node);
	}

	

}

void DispPath(MinHeap H, int node)
{
	int i;
	for(i=node; i>1; i=i/2){
		printf("%d ", H->Data[i]);
	}
	printf("%d\n", H->Data[1]);

}

MinHeap CreateHeap()
{
	MinHeap H = (MinHeap)malloc(sizeof(struct HeapNode));
	H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
	H->Size = 0;
	H->Data[0] = MinData;//此处定义哨兵

	return H;
}

int IsFull(MinHeap H)
{
	return (H->Size == MaxSize);
}

int Insert(MinHeap H, ElementType X)
{
	int i;
	if(IsFull(H)){
		printf("最小堆满\n");
		return 0;
	}
	i = ++(H->Size);
	for(; H->Data[i/2] > X; i=i/2){
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = X;
	return 1;

}

int IsEmpty(MinHeap H)
{
	return (H->Size == 0);
}




















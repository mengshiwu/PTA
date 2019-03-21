#include<stdio.h>

//二分查找
int BinarySearch(int List[], int X, int N);

int BinarySearch(int List[], int X, int N)
{//X为待查找的数，N为数组长度。返回值是下标
	int mid;
	int left = 0;
	int right = N-1;
	while(left <= right){
		mid = (left + right) / 2;
		if (X == List[mid]){
			return mid+1;
		}
		else if (X < List[mid]){
			right = mid -1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;//找不到，返回异常
}

int main()
{
	int N, X;
	int List[1000000];
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &List[i]);
	}
	scanf("%d", &X);
	printf("%d", BinarySearch(List, X, N));
	return 0;
}
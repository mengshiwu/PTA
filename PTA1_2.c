//maximum subsequence sum
#include<stdio.h>

int main()
{
	int N, i;
	int sequence[1000000];
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &sequence[i]);
	}
	int ThisSum, MaxSum;
	int nowstart = 0;
	int sumstart = 0;
	int sumend = 0;
	int flag = 0;
	ThisSum = 0;
	MaxSum = -1;
	for(i = 0; i < N; i++){
		ThisSum += sequence[i];//向右累加
		if(ThisSum > MaxSum){
			MaxSum = ThisSum;//若发现更大和则更新当前结果
			sumstart = nowstart;
			sumend = i;

		}
		

		else if(ThisSum < 0)//如果当前子列和为负
		{
			ThisSum = 0;//则不可能使后面的部分和增大，抛弃之
			nowstart = i + 1;
			
		}
		
	}
	for(i = 0; i < N; i++){
		if (sequence[i] >= 0){
			flag = 0;
			break;
		}
		else flag = 1;
	}
	if(flag){
		MaxSum = 0;
		sumstart = 0;
		sumend = N - 1;
	}
	printf("%d %d %d", MaxSum, sequence[sumstart], sequence[sumend]);
    return 0;
}


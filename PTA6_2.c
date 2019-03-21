#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
	double x, y;
}position[100];

int visited[100] = {0};
int N;
double D;//鳄鱼数量和跳跃距离
const double r = 15/2;//孤岛半径

int FirstJump(int v)
{
	return sqrt(position[v].x * position[v].x + position[v].y * position[v].y) <= r+D;
}

int Jump(int v, int i)
{
	return sqrt(fabs(position[i].x-position[v].x) * fabs(position[i].x-position[v].x) + fabs(position[i].y-position[v].y)*fabs(position[i].y-position[v].y)) <= D;
}

int IsSave(int v)
{
	return (fabs(position[v].x) >= 50-D || fabs(position[v].y) >= 50-D);
}

int DFS(int v)
{
	visited[v] = 1;
	if(IsSave(v)){
		return 1;
	}
	else{
		for(int i=0; i<N; i++){
			if(!visited[i] && Jump(v, i)){
				int isjump = DFS(i);
				if(isjump){
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int isjump;
	scanf("%d %lf", &N, &D);
	for(int i=0; i<N; i++){
		scanf("%lf %lf", &position[i].x, &position[i].y);

	}
	for(int i=0; i<N; i++){
		if(!visited[i] && FirstJump(i)){
			isjump = DFS(i);
			if(isjump)
				break;
		}
	}
	if(isjump)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;

}

































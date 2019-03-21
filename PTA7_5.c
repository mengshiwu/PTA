#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxVertexNum 101
#define Inf 9999999

int flag = 0;//表示能否到达岸边
int exist = 0;
int N;//鳄鱼数量（节点数量）
double D;//跳跃距离
int temp;
int dist[MaxVertexNum];
int path[MaxVertexNum];
int save[MaxVertexNum];
int visit[MaxVertexNum];
const double r = 15/2;//小岛半径

struct Node{
	double x, y;
}position[101];

double dis(int v){
	return sqrt(position[v].x*position[v].x+position[v].y*position[v].y);
}

int Jump(int v, int i)
{
	return sqrt(fabs(position[i].x-position[v].x) * fabs(position[i].x-position[v].x) + fabs(position[i].y-position[v].y)*fabs(position[i].y-position[v].y)) <= D;
}

int IsSave(int v)
{
	return (fabs(position[v].x) >= 50-D || fabs(position[v].y) >= 50-D);
}

void Initial()
{
	flag = 0;
	for(int i=0; i<N; i++){
		path[i] = -1;
		dist[i] = Inf;
		visit[i] = 0;
	}
}

void dijkstra(int s)
{
	visit[s] = 1;
	dist[s] = 1;//第一跳
	path[s] = -2;
	int i;
	temp = s;

	while(1){
		if(IsSave(temp)){//能跳到岸上，安全了
			dist[temp]++;//跳到岸上需要再加一步
			flag = 1;
			exist = 1;
			break;
		}
		for(i=0; i<N; i++){
			if(!visit[i] && Jump(i, temp) ){//i点未被访问，并且从temp可以跳到i上
				if(dist[temp] + 1 < dist[i]){
					dist[i] = dist[temp] + 1;
					path[i] = temp;
				}
			}
		}
		int min = Inf;
		for(i=0; i<N; i++){
			if(!visit[i] && dist[i]<Inf){
				if(min > dist[i]){
					min = dist[i];
					temp = i;
				}
			}
		}
		visit[temp] = 1;
		if(min == Inf)
			break;
	}

}

int FirstJump(int v)
{
	return sqrt(position[v].x * position[v].x + position[v].y * position[v].y) <= r+D;
}

int main()
{
	int i;
	scanf("%d %lf", &N, &D);
	for(i=0; i<N; i++){
		scanf("%lf %lf", &position[i].x, &position[i].y);
	}
	if(D+r >= 50){//一步就能跳上岸
		printf("1\n");
		return 0;
	}
	int firstnode[N];
	int firstnum=0;
	for(i=0; i<N; i++){
		if(FirstJump(i))
			firstnode[firstnum++] = i;//存下第一跳的下标
	}
	int min = Inf;
	int store[N], count=0;

	//对于每一个第一跳能到的点进行遍历
	for(i=0; i<firstnum; i++){
		Initial();
		dijkstra(firstnode[i]);
		if(flag){//找到路径了
			if(min > dist[temp]){
				min = dist[temp];
				count = 0;
				store[count++] = firstnode[i];
			}
			else if(dist[temp] == min){
				store[count++] = firstnode[i];
			}

		}

	}

	if(exist==0){//如果不能跳上岸
		printf("0\n");
		return 0;
	}

	min = Inf;
	int indexmin;//当有多条路时，选择离岛最近的一只鳄鱼
	for(i=0; i<count; i++){
		int index = store[i];
		if(min > dis(index)-r){
			min = dis(index)-r;
			indexmin = store[i];
		}
	}

	Initial();
	dijkstra(indexmin);
	printf("%d\n", dist[temp]);
	count = 0;
	while(1){
		store[count++] = temp;
		temp = path[temp];
		if(temp==-2)
			break;
	}
	for(i=count-1; i>=0; i--){
		printf("%.0f %.0f\n", position[store[i]].x, position[store[i]].y);
	}

	return 0;

}







































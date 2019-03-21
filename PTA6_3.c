#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxVertexNum 10001

int G[MaxVertexNum][MaxVertexNum] = {0};
int visited[MaxVertexNum];
int queue[MaxVertexNum];
int Nv, Ne;//顶点数，边数
double count;//
int p;

void BFS(int v)
{
	visited[v] = 1;
	int front = 0, rear = 0;
	int level = 0;//记录当前层数
	int last = v;//记录当前层最后一个元素
	int next = v;//记录下一层最后一个元素
	queue[rear++] = v;//入队
	while(front < rear){
		p = queue[front++];//当前元素（出队）
		for(int i=1; i<=Nv; i++){//题中要求的下标从1开始
			if(G[p][i] && !visited[i]){
				visited[i] = 1;
				count++;
				queue[rear++] = i;
				next = i;//记录这一层最后的元素，不断更新
			}
		}	
		if(last==p){//如果是当前层的最后一个元素
			level++;
			last = next;//更新为下一层的最后一个元素
		}
		if(level==6)
			break;	
	}
}

void ini_visited()
{
	for(int i=0; i<MaxVertexNum; i++){
		visited[i] = 0;
	}
}

int main()
{
	int gl, gc;
	scanf("%d %d", &Nv, &Ne);
	for(int i=0; i<Ne; i++){
		scanf("%d %d", &gl, &gc);
		G[gl][gc] = G[gc][gl] = 1;
	}
	for(int i=1; i<=Nv; i++){
		ini_visited();
		count = 1;
		BFS(i);
		printf("%d: %.2f%%\n", i, (count*100)/Nv);

	}
	return 0;

}





























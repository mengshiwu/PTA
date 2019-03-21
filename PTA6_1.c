#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10

int visited[MaxVertexNum] = {0};
//建立邻接矩阵
int G[MaxVertexNum][MaxVertexNum] = {0};
int Nv, Ne;//Nv是顶点数，Ne是边数

void BuildGraph()
{
	int v1, v2;
	int i, j;
	scanf("%d %d", &Nv, &Ne);
	for(i=0; i<Ne; i++){
		scanf("%d %d", &v1, &v2);
		//插入邻接矩阵
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}

}

//深度优先遍历
void DFS(int v)//对顶点v所在的连通分量进行遍历
{
	visited[v] = 1;
	printf("%d ", v);
	for(int i=0; i<Nv; i++){//遍历v的每个邻接点
		if(G[v][i] && !visited[i])//如果v和i直接有边&i未被访问过
			DFS(i);
	}
}

void ListComponentsDFS()
{
	int i;
	for(i=0; i<Nv; i++){
		if(!visited[i]){
			printf("{ ");
			DFS(i);
			printf("}\n");
		}
	}
}

void ini_visited()
{
	for(int i=0; i<MaxVertexNum; i++){
		visited[i] = 0;
	}
}

void BFS(int v)
{
	
	int queue[100];
	int first = -1; 
	int rear = -1;
	queue[++rear] = v;//入队
	visited[v] = 1;

	while(first < rear){//队列不为空
		int de = queue[++first];//出队
		for(int i=0; i<Nv; i++){
			if(G[de][i] && !visited[i]){
				visited[i] = 1;
				queue[++rear] = i;
			}
		}

	}
}

void ListComponentsBFS()
{
	int i;
	for(i=0; i<Nv; i++){
		if(!visited[i]){
			printf("{ ");
			BFS(i);
			printf("}\n");
		}
	}
}

int main()
{
	BuildGraph();
	ListComponentsDFS();
	ini_visited();
	ListComponentsBFS();
	return 0;

}















































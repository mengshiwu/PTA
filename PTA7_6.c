#include <stdio.h>
#include <stdlib.h>
#define MaxV 500
#define Inf 6666666

int S, D;

typedef struct ENode{
	int V1, V2;
	int Length;
	int Cost;
}*Edge;

typedef struct GNode{
	int Nv;
	int Ne;
	int Glen[MaxV][MaxV];
	int Gcost[MaxV][MaxV];
}*MGraph;

MGraph CreateGraph(int vertexnum)
{
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = vertexnum;
	Graph->Ne = 0;
	for(int i=0; i<Graph->Nv; i++){
		for(int j=0; j<Graph->Nv; j++){
			Graph->Glen[i][j] = Inf;
			Graph->Gcost[i][j] = Inf;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->Glen[E->V1][E->V2] = E->Length;
	Graph->Glen[E->V2][E->V1] = E->Length;
	Graph->Gcost[E->V1][E->V2] = E->Cost;
	Graph->Gcost[E->V2][E->V1] = E->Cost;

}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int N, M;
	scanf("%d %d %d %d", &N, &M, &S, &D);
	Graph = CreateGraph(N);
	Graph->Ne = M;

	if(Graph->Ne!=0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(int i=0; i<Graph->Ne; i++){
			scanf("%d %d %d %d", &E->V1, &E->V2, &E->Length, &E->Cost);
			InsertEdge(Graph, E);
		}
	}

	return Graph;
}

int FindMinDist(MGraph Graph, int dist[], int collected[], int fee[])
{
	int MinV, V;
	int MinDist = Inf;
	int MinFee = Inf;

	for(V=0; V<Graph->Nv; V++){
		if(!collected[V] && dist[V]<=MinDist){//若V未被收录，且dist[V]更小
			if(MinFee > fee[V])
				MinDist = dist[V];
				MinV = V;
		}
	}
	if(MinDist < Inf)//找到最小dist
		return MinV;//返回对应最小dist顶点下标
	return -1;
}

void Dirjsktra(MGraph Graph, int s, int d)
{
	int collected[MaxV];
	int dist[MaxV], fee[MaxV], path[MaxV];
	int v, w;
	for(v=0; v<Graph->Nv; v++){
		dist[v] = Graph->Glen[v][s];
		fee[v] = Graph->Gcost[v][s];
		if(dist[v] < Inf)
			path[v] = s;
		else
			path[v] = -1;
		collected[v] = 0;
	}
	dist[s] = 0;
	fee[s] = 0;
	collected[s] = 1;
	while(1){
		v = FindMinDist(Graph, dist, collected, fee);
		if(v==-1)//不存在
			break;
		collected[v] = 1;
		for(w=0; w<Graph->Nv; w++){
			//查看v的邻接点
			if(!collected[w] && Graph->Glen[v][w]<Inf){
				if(dist[v] + Graph->Glen[v][w] < dist[w]){
					dist[w] = dist[v] + Graph->Glen[v][w];
					fee[w] = fee[v] + Graph->Gcost[v][w];
					path[w] = v;
				}
				else if(dist[v] + Graph->Glen[v][w] == dist[w]){
					if(fee[v] + Graph->Gcost[v][w] < fee[w]){
						dist[w] = dist[v] + Graph->Glen[v][w];
						fee[w] = fee[v] + Graph->Gcost[v][w];
						path[w] = v;
					}

				}
			}
		}

	} 
	printf("%d %d\n", dist[d], fee[d]);

}

int main()
{
	MGraph Graph;
	Graph = BuildGraph();
	Dirjsktra(Graph, S, D);

}






































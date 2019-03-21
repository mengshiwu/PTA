#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 100
#define INFINITY 65535

//定义边
typedef struct ENode *PtrToENode;
struct ENode{
	int V1, V2;
	int Weight;
};
typedef PtrToENode Edge;

//定义图节点
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	int G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreateGraph(int VertexNum)
{
	int v, w;
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for(v=0; v<Graph->Nv; v++){
		for(w=0; w<Graph->Nv; w++){
			Graph->G[v][w] = INFINITY;
		}
	}
	return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	int Nv, Ne;

	scanf("%d %d", &Nv, &Ne);
	Graph = CreateGraph(Nv);
	Graph->Ne = Ne;

	if(Ne!=0){
		E = (Edge)malloc(sizeof(struct ENode));
		for(int i=0; i<Ne; i++){
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			E->V1--;
			E->V2--;
			InsertEdge(Graph, E);
		}
	}
	return Graph;
}

void Floyd(MGraph Graph, int D[MaxVertexNum][MaxVertexNum])
{
	int i, j, k;
	//先将D初始化为G
	for(i=0; i<Graph->Nv; i++){
		for(j=0; j<Graph->Nv; j++){
			D[i][j] = Graph->G[i][j];
		}
	}

	for(k=0; k<Graph->Nv; k++){
		for(i=0; i<Graph->Nv; i++){
			for(j=0; j<Graph->Nv; j++){
				if(D[i][k] + D[k][j] < D[i][j]){
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}

}

int FindMaxDist(int D[MaxVertexNum][MaxVertexNum], int i, int n)
{
	int MaxDist=0;
	int j;
	for(j=0; j<n; j++){
		if(i!=j && D[i][j] > MaxDist)
			MaxDist = D[i][j];
	}
	return MaxDist;
}

void FindAnimal(MGraph Graph)
{
	int D[MaxVertexNum][MaxVertexNum];
	int Animal;
	int MaxDist, MinDist;

	Floyd(Graph, D);

	MinDist = INFINITY;
	for(int i=0; i<Graph->Nv; i++){
		MaxDist = FindMaxDist(D, i, Graph->Nv);
		if(MaxDist==INFINITY){//说明有从i不能变出的动物
			printf("0\n");
			return;
		}
		if(MinDist > MaxDist){
			MinDist = MaxDist;
			Animal = i+1;//实际下标从1开始
		}
	}
	printf("%d %d\n", Animal, MinDist);
}

int main()
{
	MGraph Graph;
	Graph = BuildGraph();
	FindAnimal(Graph);
	return 0;
}




































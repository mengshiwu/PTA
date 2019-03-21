#include <stdio.h>
#include <stdlib.h>
#define MaxN 100
#define Inf -65535

typedef struct ENode{//此时为有向图，有向边<V1,V2>
	int V1, V2;
	int weight;
}*Edge;

typedef struct AdjNode *AdjList;
struct AdjNode{
	int index;//邻接点下标
	int weight;//边权重
	AdjList Next;
};

typedef struct HNode{
	AdjList FirstEdge;//邻接表节点第一条边
}List[MaxN];

typedef struct GNode{
	int Nv;
	List Head;//邻接表
}*LGraph;

void InsertEdge(LGraph Graph, Edge E)
{
	//有向边
	AdjList NewNode;
	//插入边<v1,v2>
	//为V2建立新的邻接点
	NewNode = (AdjList)malloc(sizeof(struct AdjNode));
	NewNode->index = E->V2;
	NewNode->weight = E->weight;
	//将V2插入V1表头
	NewNode->Next = Graph->Head[E->V1].FirstEdge;
	Graph->Head[E->V1].FirstEdge = NewNode;
}

LGraph BuildGraph(int n, int m)
{
	int v;
	LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
	Edge E = (Edge)malloc(sizeof(struct ENode));
	Graph->Nv = n;
	for(v=0; v<Graph->Nv; v++){
		Graph->Head[v].FirstEdge = NULL;
	}
	for(v=0; v<m; v++){
		scanf("%d %d %d", &E->V1, &E->V2, &E->weight);
		InsertEdge(Graph, E);
	}
	return Graph;
}

void TopSort(LGraph Graph)
{
	int Indegree[MaxN];//入度
	int Time[MaxN], cnt=0, temp=Inf;
	int queue[MaxN], front=0, rear=0;//队列中从下标为1开始存储节点
	int v;
	AdjList w;
	//初始化入度数
	for(v=0; v<Graph->Nv; v++){
		Indegree[v] = 0;
		Time[v] = 0;
	}
	//遍历图，得到indegree
	for(v=0; v<Graph->Nv; v++){
		for(w=Graph->Head[v].FirstEdge; w; w=w->Next){
			++Indegree[w->index];
		}
	}
	//将所有度为0的点入队列
	for(v=0; v<Graph->Nv; v++){
		if(!Indegree[v])
			queue[++rear] = v;
	}
	while(front!=rear){
		v = queue[++front];//弹出一个度为0的节点
		cnt++;
		//对v的每个邻接点w->index
		for(w=Graph->Head[v].FirstEdge; w; w=w->Next){
			if(Time[v] + w->weight > Time[w->index])//每个节点的时间选择最大的那个
				Time[w->index] = Time[v] + w->weight;
			if(--Indegree[w->index] == 0)//若删除v使得w->index的入度为0
				queue[++rear] = w->index;
		}
	}
	if(cnt != Graph->Nv)
		printf("Impossible\n");
	else{
		for(v=0; v<cnt; v++)
			if(temp<Time[v])
				temp = Time[v];
		printf("%d\n", temp);
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n,&m);
	LGraph Graph = BuildGraph(n, m);
	TopSort(Graph);
	return 0;

}





































#include <stdio.h>
#include <stdlib.h>
#define MaxVertex 1001
#define Inf 65535

int G[MaxVertex][MaxVertex], Nv, Ne;

void CreateGraph()
{
	int i, j;
	scanf("%d %d", &Nv, &Ne);

	for(i=1; i<=Nv; i++){
		for(j=1; j<=Nv; j++){
			G[i][j] = Inf;
		}
	}
	int v1, v2, cost;
	for(i=0; i<Ne; i++){
		scanf("%d %d %d", &v1, &v2, &cost);
		G[v1][v2] = cost;
		G[v2][v1] = cost;
	}
}

int Prim()
{
	int min;
	int i, j, k;
	int lowcost[MaxVertex];
	int cost=0;

	lowcost[1] = 0;//将1加入生成树
	for(i=2; i<=Nv; i++)
	{
		lowcost[i] = G[1][i];
	}
	for(i=2; i<=Nv; i++){
		min = Inf;
		j=1;
		k=0;
		while(j<=Nv){
			if(lowcost[j] != 0 && min>lowcost[j]){
				min = lowcost[j];
				k = j;//当前最小值下标存入k
			}
			j++;
		}

		if(k==0)
		{
			return -1;//不连通
		}
		cost += min;
		lowcost[k] = 0;//将当前节点设为0，表示此节点已经完成任务

		for(j=2; j<=Nv; j++){
			if(lowcost[j]!=0 && G[k][j]<lowcost[j]){
			//若下标为k节点各边权值小于此前这些节点未被加入生成树的权值
				lowcost[j] = G[k][j];

			}
		}
	}

	return cost;
}

int main()
{
	CreateGraph();
	int cost = Prim();
	printf("%d\n", cost);
}




































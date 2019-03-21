//List Leaves
//层序遍历：从根节点开始，依次将左右儿子入队，直到队列为空
#include <stdio.h>

typedef struct TreeNode
{
	int root;//根节点
	int left;
	int right;
}TNode;

int main()
{
	int N, i;
	char cl, cr;
	int Root;
	TNode nodes[10];
	scanf("%d", &N);
	getchar();
	for(i=0; i<N; i++){//创建基础节点
		nodes[i].left = -1;
		nodes[i].right = -1;
		nodes[i].root = -1;
	}
	for(i=0; i<N; i++){
		scanf("%c %c", &cl, &cr);
		getchar();
		if(cl != '-'){
			nodes[i].left = cl-'0';
			nodes[cl-'0'].root = 0;
		}
		if(cr != '-'){
			nodes[i].right = cr-'0';
			nodes[cr-'0'].root = 0;
		}
	}

	for(i=0; i<N; i++){
		if(nodes[i].root == -1){
			Root = i;
			break;
		}
	}

	//构造完树以后，层序遍历树，依次输出叶节点；
	int head=0, tail=0;
	int queue[10];
	int nownode;
	int temp[10];
	int count=0;
	queue[tail++] = Root;
	while((tail-head) != 0){
		nownode = queue[head++];
		if(nodes[nownode].left == -1 && nodes[nownode].right == -1){
			temp[count++] = nownode;
		}
		if(nodes[nownode].left != -1){
			queue[tail++] = nodes[nownode].left;
		}
		if(nodes[nownode].right != -1){
			queue[tail++] = nodes[nownode].right;
		}
	}
	for(i=0; i<count-1; i++){
		printf("%d ", temp[i]);
	}
	printf("%d\n", temp[count-1]);

	return 0;

}



































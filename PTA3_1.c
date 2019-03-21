//树的同构
#include <stdio.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define None -1

struct TreeNode
{
	ElementType Element;
	int left;
	int right;
}T1[MaxTree], T2[MaxTree];

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(int R1, int R2);

int main()
{
	int R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if(Isomorphic(R1, R2))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}

Tree BuildTree(struct TreeNode T[]){
	int N, i, check[10];
	int Root;
	char cl, cr;
	scanf("%d", &N);
	getchar();
	if(N){
		for(i=0; i<N; i++){
			check[i] = 0;
		}
		for(i=0; i<N; i++){
		}
		for(i=0; i<N; i++){
			scanf("%c %c %c", &T[i].Element, &cl, &cr);
			getchar();
			if(cl != '-'){
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else{
				T[i].left = None;
			}

			if(cr != '-'){
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else{
				T[i].right = None;
			}
		}

		for(i=0; i<N; i++){
			if(check[i] == 0)
				break;
		}
		Root = i;
		
	}
	return Root;
}

int Isomorphic(int R1, int R2){
	if((R1==None) && (R2==None))//两者都是空
		return 1;
	if(((R1==None) && (R2!=None))||((R1!=None) && (R2==None)))//有一个是空
		return 0; 
	if(T1[R1].Element != T2[R2].Element)//根不同
		return 0;
	if((T1[R1].left == None) && (T2[R2].left == None))
		return Isomorphic(T1[R1].right, T2[R2].right);//两者都没有左子树
	if(((T1[R1].left != None) && (T2[R2].left != None)) && ((T1[T1[R1].left].Element) == (T2[T2[R2].left].Element)))//左右子树不需要交换
		return (Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right));
	else
		return (Isomorphic(T1[R1].left, T2[R2].right) && Isomorphic(T1[R1].right, T2[R2].left));

}





























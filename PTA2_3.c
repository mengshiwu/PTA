//reversing linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int Address;
	int Data;
	int nextAddress;
	struct Node *next;
}Node, *LinkList;

int main()
{
	LinkList L1, p1, q1;
	L1 = (LinkList)malloc(sizeof(Node));
	L1->next = NULL;
	int firstAddress;
	int N, K;

	//排序前输入
	scanf("%d %d %d", &firstAddress, &N, &K);
	p1 = L1;
	for(int i=0; i<N; i++){
		q1 = (LinkList)malloc(sizeof(Node));
		scanf("%d %d %d", &q1->Address, &q1->Data, &q1->nextAddress);
		p1->next = q1;
		p1 = q1;
	}

	p1->next = NULL;

	// printf("测试：：\n");
	// p1 = L1->next;
	// while(p1!=NULL){
	// 	printf("%05d %d %05d\n", p1->Address, p1->Data, p1->nextAddress);
	// 	p1 = p1->next;

	// }

	//排序后输出
	LinkList L2, p2, q2;
	L2 = (LinkList)malloc(sizeof(Node));
	L2->next = NULL;
	int count = 0;
	int findAddress = firstAddress;
	p2 = L2;
	while(findAddress != -1){
		q2 = L1;
		while(q2->next != NULL){
			if(q2->next->Address == findAddress){
				p2->next = q2->next;
				q2->next = q2->next->next;
				p2 = p2->next;
				findAddress = p2->nextAddress;
				count ++;

			}
			else{
				q2 = q2->next;
			}
		}
	}
	p2->next = NULL;
	// printf("排序后：\n");
	// p2 = L2->next;
	// while(p2){
	// 	printf("%05d %d %05d\n", p2->Address, p2->Data, p2->nextAddress);
	//     p2 = p2->next;
	// }

	//逆转后
	LinkList L3, p3, q3, tail;
	L3 = (LinkList)malloc(sizeof(Node));
	L3->next = NULL;
	p3 = L3;
	p2 = L2;
	int n = count;
	int k = K;
	while(n>=k){//从头结点开始，不断改变链表指向方向
		n = n-k;
		for(int i=0; i<k; i++){
			p3->next = p2->next;
			p2->next = p2->next->next;
			if(i==0){
				tail = p3->next;
			}
			else{
				p3->next->next = q3;
			}
			q3 = p3->next;

		}
		p3 = tail;
	}

	p3->next = L2->next;
	p3 = L3->next;//此时L3不包含未逆转部分，所以下文需要一直p3=p3->next
	// printf("逆转后：\n");
	while(p3->next){
		printf("%05d %d %05d\n", p3->Address, p3->Data, p3->next->Address);
		p3 = p3->next;

	}
	printf("%05d %d -1\n",p3->Address, p3->Data);
	return 0;
}






























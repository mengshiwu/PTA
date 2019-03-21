//tree traversals Again
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int post[30];
int count=0; 

void to_post_tree(int *pre, int *in, int length)
{
	int key;
	if (length == 0)
		return;
	key = *pre;
	int i;
	for (i = 0; i < length; i++) {
		if (in[i] == *pre) {
			break;
		}
	}
	to_post_tree(pre+1, in, i);
	to_post_tree(pre + i + 1, in + i + 1, length - i - 1);
	post[count++] = key;
 
}
 
int main()
{
	int N, i;
	int num;
	char s[30];
	int pre[30], in[30], tmp[60];
	int cp=0, ci=0, ct=0;
	scanf("%d", &N);
	for(i=0; i<2*N; i++){
		scanf("%s", s);
		if(strcmp("Push", s) == 0){
			scanf("%d", &num);
			pre[cp++] = num;
			tmp[ct++] = num;
		}
		else{
			in[ci++] = tmp[--ct];
		}
	}
	to_post_tree(pre, in, N);
	for(i=0; i<N-1; i++){
		printf("%d ", post[i]);
	}
	printf("%d\n", post[count-1]);

	return 0;
}


































#include <stdio.h>

#define MAX_COUNT	100

struct bstree {
	int data;
	int lchild;
	int rchild;	
};
static struct bstree bst[MAX_COUNT];

int deal_one_line(void)
{
	int num_count = 0;
	int tmp = 0;
	int j = 0;
	int i = 0;
	struct bstree p = {0, -1, -1};

	for (i = 0; i < MAX_COUNT; i++)
		bst[i] = p;
	scanf("%d", &num_count);
	scanf("%d", &tmp);
	bst[0].data = tmp;
	printf("-1\n");
	for (i = 1; i < num_count; i++) {
		scanf("%d", &tmp);
		bst[i].data = tmp;
		j = 0;
		while ((tmp < bst[j].data && bst[j].lchild != -1) 
			|| (tmp > bst[j].data && bst[j].rchild != -1)) {
			if (tmp < bst[j].data) {
				j = bst[j].lchild;
			} else {
				j = bst[j].rchild;
			}
 		}
 		if (tmp < bst[j].data) {
 			bst[j].lchild = i;
 		} else {
 			bst[j].rchild = i;
 		}
 		printf("%d\n", bst[j].data);
	}
	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 1;
	int i = 0;

	fp = freopen("input.txt", "r", stdin);
	//scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

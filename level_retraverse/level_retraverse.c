#include <stdio.h>

#define MAX_COUNT	101

struct node{
	int parent;
	int lchild;
	int rchild;
};

static struct node btree[MAX_COUNT];
static int queue[MAX_COUNT] = {0};
int deal_one_line(int seq)
{
	int branch_count = 0;
	int node_count = 0;
	int i = 0;
	struct node np = {-1, -1, -1};
	int parent = 0;
	int child = 0;
	int head = 0;
	int tail = 0;
	int ip = 0;
	int right = 0;

	scanf("%d%d", &branch_count, &node_count);
	for (i = 1; i < node_count + 1; i++) {
		btree[i] = np;
	}
	for (i = 0; i < branch_count; i++) {
		scanf("%d%d", &child, &parent);
		btree[child].parent = parent;
		if (btree[parent].lchild == -1) {
			btree[parent].lchild = child;
		} else {
			btree[parent].rchild = child;
		}
	}
	queue[head++] = 1;
	right = 1;
	printf("Q%d:\n", seq);
	while (head != tail) {
		ip = queue[tail++];
		if (btree[ip].lchild != -1) {
			queue[head++] = btree[ip].lchild;
		}
		if (btree[ip].rchild != -1) {
			queue[head++] = btree[ip].rchild;
		}
		if (right == ip) {
			printf("%d\n", ip);	
			right = queue[head - 1];
		} else {
			printf("%d ", ip);
		}
	}

	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;

	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line(i + 1);
	}
	
	if (fp != stdin) fclose(fp);
}

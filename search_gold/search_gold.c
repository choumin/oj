#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>

#define MAX_COUNT	1000

struct list {
	int index;
	struct list *next;
};
struct node {
	int parent;
	int child_count;
	struct list *child_list;
};
struct node gold_tree[MAX_COUNT];

int deal_one_line(void)
{
	struct node bn = {-1, 0, NULL};
	int node_count = 0;
	int branch_count = 0;
	int gold_index = 0;
	int parent = 0;
	int child = 0;
	struct list *lp = NULL;
	struct list *p = NULL;
	struct list *q = NULL;
	int weight = 1;
	float chance = 0;
	int i = 0;

	for (i = 0; i < MAX_COUNT; i++) {
		gold_tree[i] = bn;
	} 
	scanf("%d%d%d", &node_count, &branch_count, &gold_index);
	for (i = 0; i < branch_count; i++) {
		scanf("%d%d", &parent, &child);
		gold_tree[child].parent = parent;
		lp = (struct list *)malloc(sizeof(struct list));
		lp->index = child;
		lp->next = NULL;
		gold_tree[parent].child_count++;
		if (!gold_tree[parent].child_list) {
			gold_tree[parent].child_list = lp;
			continue;
		}
		p = gold_tree[parent].child_list;
		while (p->next) {
			p = p->next;
		}
		p->next = lp;
	}
	while (gold_tree[gold_index].parent != -1) {
		weight *= gold_tree[gold_tree[gold_index].parent].child_count;
		gold_index = gold_tree[gold_index].parent;
	}
	printf("%.6f\n", 1.0 / weight);

	for (i = 0; i < MAX_COUNT; i++) {
		if (!gold_tree[i].child_count) {
			continue;
		}
		p = gold_tree[i].child_list;
		while (p) {
			q = p->next;
			free(p);
			p = q;
		}
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
//	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

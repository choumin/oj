#include <stdio.h>
#include <sys/malloc.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COUNT	1000

struct list
{
	int child;
	struct list *next;
};
struct node{
	int grade;
	int parent;
	struct list *child_list;
};

struct node directed_tree[MAX_COUNT] = {0};

void destrory_child_list(void)
{
	int i = 0;
	struct list *p = NULL;
	struct list *q = NULL;

	for (i = 0; i < MAX_COUNT; i++) {
		if (!directed_tree[i].grade)
			continue;
		p = directed_tree[i].child_list;
		while (p) {
			q = p->next;
			free(p);
			p = q;
		}
		directed_tree[i].child_list = NULL;
	}
}

int deal_one_line(void)
{
	int node_count = 0;
	int i = 0;
	int parent = 0;
	int child = 0;
	struct list *clp = NULL;
	struct list *p = NULL;
	int sum = 0;
	int max = 0;

	memset(directed_tree, 0, sizeof(struct node) * MAX_COUNT);
	scanf("%d", &node_count);
	
	for (i = 0; i < node_count - 1; i++) {
		scanf("%d", &parent);
		scanf("%d", &child);
		directed_tree[parent].grade++;
		directed_tree[child].grade++;
		directed_tree[child].parent = parent;
		
		clp = (struct list *)malloc(sizeof(struct list));
		clp->child = child;
		clp->next = NULL;
		if (directed_tree[parent].child_list == NULL) {
			directed_tree[parent].child_list = clp;
			continue;
		}
		p = directed_tree[parent].child_list;
		while (p->next) {
			p = p->next;
		}
		p->next = clp;
	}
	for (i = 0; i < MAX_COUNT; i++) {
		if (!directed_tree[i].grade)
			continue;
		max = directed_tree[directed_tree[i].parent].grade;
		if (max < directed_tree[i].grade) {
			max = directed_tree[i].grade;
		}
		p = directed_tree[i].child_list;
		while (p) {
			if (max < directed_tree[p->child].grade) {
				max = directed_tree[p->child].grade;
			}
			p = p->next;
		}
		if (max <= directed_tree[i].grade)
			sum++;
	}

	printf("%d\n", sum);

	destrory_child_list();

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
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

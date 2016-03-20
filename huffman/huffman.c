#include <stdio.h>

#define MAX_COUNT	1000
struct node {
	int parent;
	int lchild;
	int rchild;
	int weight;
};
struct node huffman_tree[2 * MAX_COUNT] = {0};

int select(int end, int *lcp, int *rcp)
{
	int i = 0;
	int flag = 0;
	int min  = 0;
	int sub_min = 0;
	int min_index = 0;
	int sub_min_index = 0;

	for (i = 0; i < end; i++) {
		if (huffman_tree[i].parent) 
			continue;
		if (flag == 0) {
			min = huffman_tree[i].weight;
			min_index = i;
			flag++;
		} else if (flag == 1) {
			if (huffman_tree[i].weight < min) {
				sub_min = min;
				sub_min_index = min_index;
				min = huffman_tree[i].weight;
				min_index = i;
			} else {
				sub_min = huffman_tree[i].weight;
				sub_min_index = i;
			}
			flag++;
		} else {
			if (huffman_tree[i].weight < min) {
				sub_min = min;
				sub_min_index = min_index;
				min = huffman_tree[i].weight;
				min_index = i;
			} else if (huffman_tree[i].weight < sub_min) {
				sub_min = huffman_tree[i].weight;
				sub_min_index = i;
			}
		}
	}
	*lcp = min_index;
	*rcp = sub_min_index;
	return 0;
}
int weight_sum(int root, int deep, int node_count)
{
	if (root >= node_count) {
		return weight_sum(huffman_tree[root].lchild, deep + 1, node_count) + 
				weight_sum(huffman_tree[root].rchild, deep + 1, node_count);
	}
	return deep * huffman_tree[root].weight;
}
int deal_one_line(void)
{
	int node_count = 0;
	int i = 0;
	int lchild = 0;
	int rchild = 0;
	int sum = 0;

	if (scanf("%d", &node_count) == EOF)
		return 0;
	for (i = 0; i < node_count * 2 - 1; i++) {
		huffman_tree[i].parent = 0;
		huffman_tree[i].lchild = 0;
		huffman_tree[i].rchild = 0;
	}
	for (i = 0; i < node_count; i++) {
		scanf("%d", &(huffman_tree[i].weight));
	}
	for (i = node_count; i < node_count * 2 - 1; i++) {
		select(i, &lchild, &rchild);
		huffman_tree[lchild].parent = i;
		huffman_tree[rchild].parent = i;
		huffman_tree[i].lchild = lchild;
		huffman_tree[i].rchild = rchild;
		huffman_tree[i].weight = huffman_tree[lchild].weight + huffman_tree[rchild].weight;
	}
	sum = weight_sum(i - 1, 0, node_count);

	printf("%d\n", sum);
	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;

	fp = freopen("input.txt", "r", stdin);
/*
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/
	while (flag) {
		flag = deal_one_line();
	}	
	if (fp != stdin) fclose(fp);
}

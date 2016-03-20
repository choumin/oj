#include <stdio.h>
#include <string.h>

#define MAX_COUNT	101

int parent_index[MAX_COUNT] = {0};
int deal_one_line(void)
{
	int i = 0;
	int parent = 0;
	int child = 0;
	int node_count =  0;
	int search_count = 0;
	int pu = 0;
	int pv = 0;
	int u = 0;
	int v = 0;

	memset(parent_index, 0, sizeof(int) * MAX_COUNT);
	scanf("%d", &node_count);
	for (i = 0; i < node_count - 1; i++) {
		scanf("%d%d", &parent, &child);
		parent_index[child] = parent;
	}
	scanf("%d", &search_count);
	for (i = 0; i < search_count; i++) {
		scanf("%d%d", &u, &v);
		pu = u;
		while (pu) {
			pv = v;
			while (pv && pv != pu) {
				pv = parent_index[pv];
			}
			if (pv) {
				break;
			}
			pu = parent_index[pu];
		}
		printf("%d\n", pv);
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
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

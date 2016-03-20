#include <stdio.h>
#include <string.h>

#define MAX_COUNT	100000
#define MAX_OP_LEN	8
#define MAX_PRO_COUNT	101

void kill_pro(char (*pro_tree)[MAX_PRO_COUNT], char pid) 
{
	int i = 0;

	for (i = 0; i < MAX_PRO_COUNT; i++) {
		if (pro_tree[pid][i]) {
			kill_pro(pro_tree, i);
		    pro_tree[pid][i] = 0;
		}
	}
}
int deal_one_line(void)
{
	int op_count = 0;
	char *yes = "Yes";
	char *no = "No";
	char op_str[MAX_OP_LEN] = {0};
	int i = 0;
	char pro_tree[MAX_PRO_COUNT][MAX_PRO_COUNT] = {0};
	int parent = 0;
	int child = 0;
	int j = 0;
	int pid = 0;
	pro_tree[0][0] = 1;
	scanf("%d", &op_count);

	for (i = 0; i < op_count; i++) {
		scanf("%s", op_str);
		if (strcmp(op_str, "FORK") == 0) {
			scanf("%d%d", &parent, &child);
			pro_tree[parent][child] = 1;
		} else if (strcmp(op_str, "QUERY") == 0) {
			scanf("%d", &pid);
			for (j = 0; j < MAX_PRO_COUNT; j++) {
				if (pro_tree[j][pid])
					break;
			}
			if (j < MAX_PRO_COUNT)
				printf("Yes\n");
			else 
				printf("No\n");
		} else {
			scanf("%d", &pid);
			for (j = 0; j < MAX_PRO_COUNT; j++) {
				if (pro_tree[j][pid])
					break;
			}
			if (j < MAX_PRO_COUNT) {
				pro_tree[j][pid] = 0;
				kill_pro(pro_tree, pid);
				//memset(pro_tree[j],);
			}
				
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

//	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	
//	if (fp != stdin) fclose(fp);
}

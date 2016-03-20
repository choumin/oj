#include <stdio.h>
#include <string.h>

#define MAX_COUNT	1001

int grad_array[MAX_COUNT];
int deal_one_line(void)
{
	int i = 0;
	int op_num = 0;
	char ch = 0;
	int j = 0;
	char op_code = 0;
	int id  = 0;
	int point = 0;

	memset(grad_array, 0, sizeof(int) * MAX_COUNT);
	scanf("%d", &op_num);
	for (i = 0; i < op_num; i++) {
		scanf("%c", &ch);
		scanf("%c", &ch);
		op_code = ch;
		scanf("%c", &ch);
		while (ch != ' ') {
			scanf("%c", &ch);
		}
		if (op_code == 'I') {
			scanf("%d%d", &id, &point);
			grad_array[id] = point;
		} else {
			scanf("%d", &id);
			if (grad_array[id]) {
				printf("name:%d score:%d\n", id, grad_array[id]);
			} else {
				printf("No result!\n");
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

	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int num_count;
	int i = 0;
	int last = 0;
	int flag = 0;
	int tmp = 0;

	scanf("%d", &num_count);
	for (i = 0; i < num_count; i++) {
		scanf("%d", &tmp);	
		if (last > tmp) {
			flag = 1;
		}
		last = tmp;
	}
	if (flag) {
		printf("No\n");
	} else {
		printf("Yes\n");
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

#include <stdio.h>

#define MAX_COUNT	10

int deal_one_line(void)
{
	int ret = 0;
	int num = 0;
	int max = 0;
	int i = 0;

	ret = scanf("%d", &max);
	if (ret == EOF) {
		return 1;
	}
	for (i = 1; i < MAX_COUNT; i++) {
		scanf("%d", &num);
		if (max < num) {
			max = num;
		}
	}
	printf("max=%d\n", max);

	return 0;
}
int main(void)
{
	int file_end = 0;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;

	fp = freopen("input.txt", "r", stdin);
/*	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/	
	while (!file_end) {
		file_end = deal_one_line();
	}
	if (fp != stdin) fclose(fp);
}

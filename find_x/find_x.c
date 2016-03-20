#include <stdio.h>

#define MAX_COUNT	200

int num_array[MAX_COUNT];

int deal_one_line(void)
{	
	int ret = 0;
	int num_count = 0;
	int i = 0;
	int num = 0;

	ret = scanf("%d", &num_count);
	if (ret == EOF) {
		return 1;
	}
	for (i = 0; i < num_count; i++) {
		scanf("%d", num_array + i);
	}

	scanf("%d", &num);
	for (i = 0; i < num_count; i++) {
		if (num_array[i] == num) {
			break;
		}
	}
	if (i < num_count && num_array[i] == num) {
		printf("%d\n", i);
	} else {
		printf("-1\n");
	}
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

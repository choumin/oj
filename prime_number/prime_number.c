#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int ret = 0;
	int num = 0;
	int count = 0;
	int i = 0;

	ret = scanf("%d", &num);
	if (ret == EOF) {
		return 1;
	}
	if (num < 2) {
		printf("no\n");
		return 0;
	}
	for (i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			count++;
			break;
		}
	}
	if (count) {
		printf("no\n");
	} else {
		printf("yes\n");
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

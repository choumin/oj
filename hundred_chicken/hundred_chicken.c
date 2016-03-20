#include <stdio.h>

#define MAX_COUNT	100

int deal_one_line(void)
{
	int ret = 0;
	int money = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	double total = 0;
	double sum = 0;

	ret = scanf("%d", &money);
	total = money;
	if (ret == EOF) {
		return 1;
	}
	for (i = 0; i <= MAX_COUNT; i++) {
		for (j = 0; j <= MAX_COUNT - i; j++) {
			k = 100 - i - j;
			sum = i * 5 + j * 3 + k / 3.0;
			if (sum <= total) {
				printf("x=%d,y=%d,z=%d\n", i, j, k);
			} else {
				break;
			}
		}
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

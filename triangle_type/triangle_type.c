#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int ret = 0;
	int max = 0;
	int min = 0;
	int mid = 0;
	int sum = 0;

	ret = scanf("%d%d%d", &a, &b, &c);
	if (ret == EOF) {
		return 1;
	}
	max = a > b ? a : b;
	max = max > c ? max : c;
	min = a > b ? b : a;
	min = min > c ? c : min;
	mid = a;
	mid = (a != max && a != min) ? a : mid;
	mid = (b != max && b != min) ? b : mid;
	mid = (c != max && c != min) ? c : mid;

	sum = min * min + mid * mid;
	if (sum > max * max) {
		printf("锐角三角形\n");
	} else if (sum == max * max) {
		printf("直角三角形\n");
	} else {
		printf("钝角三角形\n");
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

#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int ret = 0;
	int root = 0;
	int scale = 0;
	int count = 1;
	int most_left = 0;
	int right = 0;
	int most_right = 0;
	int tmp = 0;
	int times = 1;

	ret = scanf("%d%d", &root, &scale);
	if (ret == EOF || root == 0) {
		return 1;
	}
	tmp = 2 * root;
	while (tmp < scale) {
		most_left = tmp;
		tmp *= 2;
	}
	if (tmp == scale) {
		most_left = tmp;
	}
	tmp = 2 * root + 1;
	while (tmp < scale) {
		most_right = tmp;
		tmp = 2 * tmp + 1;
	}
	if (tmp == scale) {
		most_right = tmp;
	}

	right = 2 * root + 1;
	times *= 2;
	while (right <= scale) {
		count += times;
		times *= 2;
		right = right * 2 + 1;
	} 
	if (most_right < most_left && scale >= most_left) {
		count += (scale - most_left + 1);
	}

	printf("%d\n", count);

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

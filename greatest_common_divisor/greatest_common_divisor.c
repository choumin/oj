#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int ret = 0;
	int a = 0;
	int b = 0;
	int c = 0;

	ret = scanf("%d%d", &a, &b);
	if (ret == EOF) {
		return 1;
	}
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	while ((c = a % b)) {
		a = b;
		b = c;
	}
	
	printf("%d\n", b);
	
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
	return 0;
}

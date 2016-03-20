#include <stdio.h>

#define MAX_COUNT	20

int stamp[MAX_COUNT];
int deal_one_line(void)
{
	int ret = 0;
	int m = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int count = 0;

	ret = scanf("%d%d", &m, &n);
	if (ret == EOF) {
		return 1;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", stamp + i);
	}
	for (i = n - 1; i >= 0; i--) {
		sum += stamp[i];
		count++;
		if (sum == m) {
			break;
		} else if (sum > m) {
			sum -= stamp[i];
			count--;
		} 
	}
	if (sum == m) {
		printf("%d\n", count);
	} else {
		printf("0\n");
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

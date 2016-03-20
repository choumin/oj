#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int num_count = 0;
	int i = 0;
	int max = 0;
	int sub_max = 0;
	int tmp = 0;

	scanf("%d%d%d", &num_count, &max, &sub_max);
	if (sub_max > max) {
		tmp = sub_max;
		sub_max = max;
		max = tmp;
	}

	for (i = 2; i < num_count; i++) {
		scanf("%d", &tmp);
		if (tmp > max) {
			sub_max = max;
			max = tmp;
		} else if (tmp > sub_max){
			sub_max = tmp;
		}
	}
	printf("%d %d\n", max, sub_max);
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

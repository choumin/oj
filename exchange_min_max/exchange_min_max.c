#include <stdio.h>

#define MAX_COUNT	20

int num_array[MAX_COUNT];

int deal_one_line(void)
{
	int ret = 0;
	int num_count = 0;
	int max = 0;
	int min = 0;
	int max_index = 0;
	int min_index = 0;
	int i = 0;

	ret = scanf("%d", &num_count);
	if (ret == EOF) {
		return 1;
	}
	scanf("%d", num_array);
	max = num_array[0];
	max_index = 0;
	scanf("%d", num_array + 1);
	min = num_array[1];
	min_index = 1;
	if (max < min) {
		ret = max;
		max = min;
		min = ret;
		max_index = 1;
		min_index = 0;
	}

	for (i = 2; i < num_count; i++) {
		scanf("%d", num_array + i);
		if (num_array[i] > max) {
			max = num_array[i];
			max_index = i;
		} else if (num_array[i] < min) {
			min = num_array[i];
			min_index = i;
		}
	}
	ret = num_array[min_index];
	num_array[min_index] = num_array[max_index];
	num_array[max_index] = ret;

	for (i = 0; i < num_count - 1; i++) {
		printf("%d ", num_array[i]);
	}
	printf("%d\n", num_array[i]);

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

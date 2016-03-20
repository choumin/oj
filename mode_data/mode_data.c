#include <stdio.h>

#define MAX_COUNT	11

int data[MAX_COUNT] = {0};
int deal_one_line(void)
{
	int tmp = 0;
	int ret = 0;
	int i = 0;
	int max = 0;
	int max_index = 0;

	ret = scanf("%d", &tmp);
	if (ret == EOF) {
		return 1;
	}
	for (i = 1; i < 11; i++) {
		data[i] = 0;
	}
	data[tmp]++;
	for (i = 1; i < 20; i++) {
		scanf("%d", &tmp);
		data[tmp]++;
	}
	max = data[1];
	max_index = 1;
	for (i = 2; i < 11; i++) {
		if (max < data[i]) {
			max = data[i];
			max_index = i;
		}
	}
	printf("%d\n", max_index);
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

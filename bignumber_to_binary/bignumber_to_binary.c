#include <stdio.h>
#include <string.h>

#define MAX_COUNT		128
#define QUOTIENT_LEN	32

char binary_str[MAX_COUNT] = {0};
char quotient_str[QUOTIENT_LEN] = {0};
char ori_str[QUOTIENT_LEN] = {0};
int last = 0;

int get_remainder(int count)
{
	int i = 0;
	int num = 0;
	int l = 0;
	int k = 0;
	int j = 0;

	while (i < count && !ori_str[i]) {
		i++;
	}
	if (i >= count) {
		return 0;
	}
	for (; i < count; i++) {
		num = l * 10 + ori_str[i];
		l = num % 2;
		quotient_str[k++] = num / 2;
	}
	i = 0;
	while (i < k && !quotient_str[i]) {
		i++;
	}
	for (j = 0; i < k; j++, i++) {
		ori_str[j] = quotient_str[i];
	}
	binary_str[last--] = l;

	return j;
}
int deal_one_line(void)
{
	int ret = 0;
	char ch = 0;
	int i = 0;
	char r = 0;
	int file_end = 0;

	last = MAX_COUNT - 1;
	ret = scanf("%c", &ch);

	if (ret == EOF) {
		return 1;
	}
	memset(binary_str, 0, MAX_COUNT);
	memset(quotient_str, 0, QUOTIENT_LEN);
	memset(ori_str, 0, QUOTIENT_LEN);

	ori_str[i++] = ch - '0';
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		ori_str[i++] = ch - '0';
	}
	if (ch != '\n') {
		file_end = 1;
	}
	while (i > 0) {
		i = get_remainder(i);
	}

	if (last == MAX_COUNT - 1) {
		printf("0\n");
	} else {
		i = 0;
		while (!binary_str[i]) {
			i++;
		}
		for (; i < MAX_COUNT; i++) {
			printf("%d", binary_str[i]);		
		}
		printf("\n");	
	}
	
	return file_end;
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

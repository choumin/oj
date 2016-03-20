#include <stdio.h>

#define MAX_COUNT	128

int char_num[MAX_COUNT];
int deal_one_line(void)
{
	int ret = 0;
	char ch = 0;
	int i = 0;
	int j = 0;

	ret = scanf("%c", &ch);
	if (ret == EOF || ch == '\n') {
		return 1;
	}
	for (i = 0; i < MAX_COUNT; i++) {
		char_num[i] = 0;
	}
	char_num[ch]++;
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		char_num[ch]++;
	}
	for (i = 0; i < MAX_COUNT; i++) {
		if (!char_num[i])
			continue;
		j = 0;
		while (j < char_num[i]) {
			printf("%c", i);
			j++;
		}
	}
	printf("\n");

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

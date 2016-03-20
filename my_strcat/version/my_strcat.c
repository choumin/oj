#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	char ch = 0;
	int ret = 0;

	ret = scanf("%c", &ch);
	if (ret == EOF || ch == '\n') {
		return 1;
	}
	printf("%c", ch);
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		if (ch == ' ') {
			continue;
		}
		printf("%c", ch);
	}
	if (ch != '\n') {
		return 1;
	}
	printf("%c", ch);
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

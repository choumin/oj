#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	char c = 0;
	char ch = 0;
	int sum = 0;

	scanf("%c\n", &c);
	scanf("%c", &ch);
	while (ch != '\n') {
		if (ch == c) {
			sum++;
		}
		scanf("%c", &ch);
	}
	printf("%d\n", sum);
	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;
	char ch = 0;

	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	scanf("%c", &ch);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

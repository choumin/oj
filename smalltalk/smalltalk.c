#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int ret = 0;
	char ch = 0;
	int expr_ret = 0;

	ret = scanf("%c", &ch);
	if (ret == EOF) {
		return 1;
	}
	expr_ret = ch - '0';
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		switch (ch)
		{
		case '+':
			scanf("%c", &ch);
			expr_ret += ch - '0';
		break;
		case '-':
			scanf("%c", &ch);
			expr_ret -= ch - '0';
		break;
		case '*':
			scanf("%c", &ch);
			expr_ret *= (ch - '0');
		break;
		case '/':
			scanf("%c", &ch);
			expr_ret /= (ch - '0');
		break;
		}
	}
	printf("%d\n", expr_ret);
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

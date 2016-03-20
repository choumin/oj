#include <stdio.h>

#define MAX_COUNT	10000

int stack[MAX_COUNT];
int deal_one_line(void)
{
	int ret = 0;
	int op_num = 0;
	int sp = -1;
	char op_code = 0;
	char ch = 0;
	int num = 0;
	int i = 0;

	ret = scanf("%d", &op_num);
	if (ret == EOF || op_num == 0) {
		return 1;
	}
	for (i = 0; i < op_num; i++) {
		while (scanf("%c", &ch) != EOF && ch != '\n') {
			;
		}
		scanf("%c", &op_code);
		switch (op_code)
		{
		case 'A':
			if (sp < 0) {
				printf("E\n");
			} else {
				printf("%d\n", stack[sp]);
			}
		break;
		case 'P':
			scanf("%d", &num);
			stack[++sp] = num;
		break;
		case 'O':
			if (sp >= 0) {
				sp--;
			}
		break;
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

#include <stdio.h>

#define MAX_COUNT	1024

char str[MAX_COUNT] = {0};

int deal_one_line(void)
{
	char ch = 0;
	int ret = 0;
	int file_end = 0;
	int i = 0;
	int op_code = 0;
	int index = 0;
	int count = 0;
	int head = 0;
	int tail = 0;
	int op_num = 0;
	int str_len = 0;
	int j = 0;

	ret = scanf("%c", &ch); 
	if (ret == EOF) {
		return 1;
	}
	if (ch != '\n') {
		str[i++] = ch;	
	}
	
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		str[i++] = ch;
	}
	str_len = i;
	scanf("%d", &op_num);
	
	for (i = 0; i < op_num; i++) {
		scanf("%d%d%d", &op_code, &index, &count);	
		ret = scanf("%c", &ch);
		if (ret == EOF) {
			file_end = 1;
		}
		if (op_code == 0) {
			for (head = index, tail = index + count - 1, j = 0; j < count / 2; j++) {
				ch = str[head + j];
				str[head + j] = str[tail - j];
				str[tail - j] = ch;
			}

		} else {
			for (head = index, j = 0; j < count; j++) {
				scanf("%c", &ch);
				str[head + j] = ch;
			}

		}
		for (j = 0; j < str_len; j++) {
			printf("%c", str[j]);
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

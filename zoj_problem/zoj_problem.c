#include <stdio.h>

#define MAX_COUNT	1001

char str[MAX_COUNT] = {0};

int deal_one_line(void)
{
	int i = 0;
	int ret = 0;
	char ch = 0;
	int file_end = 0;
	int front = 0;
	int back = 0;
	int len = 0;
	int middle = 0;
	int flag = 0;
	int j = 0;

	str[MAX_COUNT - 1] = 0;
	ret = scanf("%c", &ch);
	if (ret == EOF) {
		return 1;
	}
	if (ch == '\n') {
		return 0;
	}
	str[i++] = ch;
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		str[i++] = ch;
	}
	if (ch != '\n') {
		file_end = 1;
	}
	len = i;
	j = 0;
	while (j < len && str[j] == 'o') {
		j++;
		front++;
	}
	if (str[j] != 'z') {
		flag = 1;
		goto RET;
	} 
	j++;
	while (j < len && str[j] == 'o') {
		j++;
		middle++;
	}

	if (!middle) {
		flag = 1;
		goto RET;
	}
	if (str[j] != 'j') {
		flag = 1;
		goto RET;
	}
	j++;
	while (j < len && str[j] == 'o') {
		j++;
		back++;
	}
	if (j != len) {
		flag = 1;
		goto RET;
	}
	if (middle == 1) {
		if (front != back) {
			flag = 1;
		}
	} else if (front * middle != back) {
			flag = 1;
	}
	
RET:
	if (flag) {
		printf("Wrong Answer\n");
	} else {
		printf("Accepted\n");
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

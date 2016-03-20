#include <stdio.h>
#include <string.h>

#define MAX_COUNT	1001

static char ori_sen[MAX_COUNT] = {0};
static char ret_sen[MAX_COUNT] = {0};

int deal_one_line(void)
{
	int flag = 1;
	char ch = 0;
	int file_end = 0;
	int i = 0;
	int last = MAX_COUNT;
	int k = 0;
	int j = 0;
	int ret = 0;

	if (scanf("%c", &ch) == EOF) {
		return 1;
	}

	memset(ori_sen, 0, MAX_COUNT);
	memset(ret_sen, 0, MAX_COUNT);
	ori_sen[i++] = ch;
	while (flag) {
		while ((ret = scanf("%c", &ch)) != EOF && ch != ' ' && ch != '\n') {
			ori_sen[i++] = ch;
		}
		if (ret == EOF) {
			file_end = 1;
		}
		if (ret == EOF || ch == '\n') {
			flag = 0;
		}
	
		for (j = last - i, k = 0; k < i; k++, j++) {
			ret_sen[j] = ori_sen[k];
		}
		if (last != MAX_COUNT) {
			ret_sen[j] = ' ';
		}
		last = last - i - 1;
		i = 0;
	}
	i = 0;
	while (!ret_sen[i])
		i++;
	printf("%s\n", ret_sen + i);

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
//	printf("%d\n", EOF);
	while (!file_end) {
		file_end = deal_one_line();
	} 	
	if (fp != stdin) fclose(fp);
}

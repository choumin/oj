#include <stdio.h>

#define MAX_COUNT	100001

char str[MAX_COUNT] = {0};

int deal_one_line(void)
{
	int char_count = 0;
	int  i = 0;
	int j = 0;
	char ch = 0;
	int op_num = 0;
	char op_code = 0;
	int index = 0;
	int left = 0;
	int right = 0;
	int min_len = 0;

	scanf("%c", &ch);
	scanf("%c", &ch);
	while (ch != '\n') {
		str[i++] = ch;
		scanf("%c", &ch);
	}
	char_count = i;
	scanf("%d", &op_num);
	for (i = 0; i < op_num; i++) {
		scanf("%c", &ch);
		scanf("%c", &op_code);
		scanf("%c", &ch);
		while (ch != ' ') {
			scanf("%c", &ch);
		}
		if (op_code == 'I') {
			scanf("%c", &ch);
			str[char_count++] = ch;
		} else if (op_code == 'Q') {
			scanf("%d", &index);
			//flag = 0;
			left = 0;
			right = 0;

			for (j = index - 1; j >= 0; j--) {
				if (str[j] == str[index]) {
					left = index - j;
					break;
				}
			}
			for (j = index + 1; j < char_count; j++) {
				if (str[j] == str[index]) {
					right = j - index;
					break;
				}
			}
			if (left == 0 && right == 0) {
				min_len = -1;	
			} else if (left == 0 && right != 0) {
				min_len = right;
			} else if (left != 0 && right == 0) {
				min_len = left;
			} else if (left != 0 && right != 0) {
				min_len = left < right ? left : right;
			}
			printf("%d\n", min_len);
		}
	}
	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;

	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

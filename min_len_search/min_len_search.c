#include <stdio.h>
#include <string.h>

#define MAX_COUNT	100001
#define MAX_OP_LEN	16

char str[MAX_COUNT] = {0};
int deal_one_line(void)
{
	int len = 0;
	int op_num = 0;
	int i = 0;
	int j = 0;
	char ch = 0;
	char op_str[MAX_OP_LEN] = {0};
	int index = 0;
	int left = 0;
	int right = 0;
	int min_len = 0;
	int flag = 0;

	scanf("%c", &ch);
	while (ch != '\n') {
		str[i++] = ch;
		scanf("%c", &ch);
	}
	len = i;
	scanf("%d", &op_num);
	scanf("%c", &ch);
	for (i = 0; i < op_num; i++) {
		j = 0;
		scanf("%c", &ch);
		while (ch != '\n') {
			op_str[j++] = ch;
			scanf("%c", &ch);
		}
		op_str[j] = ch;
		if (op_str[0] == 'Q') {
			j = 6;
			index = 0;
			
			while (op_str[j] != '\n') {
				index = index * 10 + op_str[j++] - '0';
			}
			j = 1;
			flag = 0;
			while (index - j >= 0 || index + j < len) {
				if (index - j >= 0 && str[index] == str[index - j]) {
					flag = 1;
					break;
				} 
				if (index + j < len && str[index] == str[index + j]) {
					flag = 1;
					break;
				}
				j++;
			}
			if (flag) {
				printf("%d\n", j);
			} else {
				printf("-1\n");
			}
		} else {
			str[len++] = op_str[7];
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
	char ch = 0;

	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	scanf("%c", &ch);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

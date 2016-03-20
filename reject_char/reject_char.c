#include <stdio.h>

#define MAX_COUNT	100000

char str[MAX_COUNT]; 
int deal_one_line(void)
{
	int i = 0;
	int ret = 0;
	int count = 0;
	char ch = 0;
	char target = 0;

	ret = scanf("%c", &ch);
	if (ret == EOF) {
		return 1;
	}
	while (ch != '\n') {
		str[i++] = ch;
		scanf("%c", &ch);
	}
	count = i;
	scanf("%c", &target);
	scanf("%c", &ch);
	for (i = 0; i < count; i++) {
		if (str[i] == target) {
			continue;
		}
		printf("%c", str[i]);
	}
	printf("\n");

	return 0;
}
int main(void)
{
	int file_end= 0;
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

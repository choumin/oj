#include <stdio.h>
#include <string.h>

#define MAX_COUNT	128

char str[MAX_COUNT];
int deal_one_line(void)
{
	int base = 0;
	int count = 0;
	int ret = 0;
	int i = 0;
	int j = 0;
	int c = 0;
	int bit_sum = 0;

	ret = scanf("%d%d", &base, &count);
	if (ret == EOF) {
		return 1;
	}
	memset(str, 0, MAX_COUNT);
	j = MAX_COUNT - 2;
	for (i = count; i > 0; i--) {
		bit_sum = i * base + c;
		str[j--] = bit_sum % 10 + '0';
		c = bit_sum / 10;
	}
	while (c) {
		str[j--] = c % 10 + '0';
		c /= 10;	
	}
	
	i = 0;
	while (!str[i]) {
		i++;
	}
	printf("%s\n", str + i);

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

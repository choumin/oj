#include <stdio.h>

#define MAX_COUNT	100000
#define INT_LEN		33

int deal_one_line(void)
{
	unsigned int num = 0;
	char str[INT_LEN] = {0};
	int i = 0;

	scanf("%ud", &num);
	for (i = 0; i < 32; i++) {
		str[32 - i - 1] = ((num >> i) & 0x01) + '0';
	}
	i = 0;
	while (str[i] == '0')
		i++;
	printf("%s\n", str + i);

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

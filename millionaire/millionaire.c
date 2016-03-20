#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	return 0;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int data = 1;
	int i = 0;
	for (i = 0; i < 30; i++) {
		data = (data << 1) + 1;
	}
/*
	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/
	printf("%d\n%d\n", data / 1000000, 30 * 10 * 1000000);	
//	if (fp != stdin) fclose(fp);
	return 0;
}

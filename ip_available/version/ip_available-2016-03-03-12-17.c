#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int ip[4] = {0};
	int flag = 0;
	int i = 0;
	char ch = 0;

	if (scanf("%d.%d.%d.%d", ip, ip + 1, ip + 2, ip + 3) != 4) {
		goto ERROR;
	}
	for (i = 0; i < 4; i++) {
		if (!(0 <= ip[i] && ip[i] <= 255)) {
			goto ERROR;
		} 
	}
	printf("Yes\n");
	return 1;
ERROR:
	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}
	printf("No\n");
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

#include <stdio.h>

#define MAX_COUNT	32

int deal_one_line(void)
{
	char ch = 0;
	int ip[4] = {-1, -1, -1, -1};
	int j = 0;
	int flag = 1;
	int i = 0;

	scanf("%c", &ch);
	while (ch != '\n') {
		if (flag && j < 4 && ch >= '0' && ch <= '9') {
			if (ip[j] == -1) {
				ip[j] = ch - '0';
			} else {
				ip[j] = ip[j] * 10 + ch - '0';
			}
		} else if (flag && ch == '.' && ip[j] >= 0 && ip[j] <= 255) {
			j++;
		} else {
			flag = 0;
		}
		scanf("%c", &ch);
	}
	for (i = 0; flag && i < 4; i++) {
		if (!(ip[i] >= 0 && ip[i] <= 255)) {
			flag = 0;
		}	
	}
	
//	printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
	if (flag) {
		printf("Yes\n");
	} else {
		printf("No\n");
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

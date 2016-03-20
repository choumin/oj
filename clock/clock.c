#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int hour = 0;
	int minute = 0;
	int ret = 0;
	float interval = 0;
	float hp = 0;
	float mp = 0;

	ret = scanf("%d:%d", &hour, &minute);
	if (ret == EOF) {
		return 1;
	}
	hp = hour > 11 ? hour - 12 : hour;
	hp = hp * 5 + minute / 60.0 * 5;
	interval = hp - minute;
	interval = interval < 0 ? interval * -1 : interval;
	interval = interval > 30 ? 60 - interval : interval;
	printf("%.2f\n", interval / 60 * 360);
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

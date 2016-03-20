#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int hour1 = 0;
	int hour2 = 0;
	int minute1 = 0;
	int minute2 = 0;
	int time1 = 0;
	int time2 = 0;
	int interval = 0;

	scanf("%d:%d%d:%d", &hour1, &minute1, &hour2, &minute2);
	time1 = hour1 * 60 + minute1;
	time2 = hour2 * 60 + minute2;
	interval = time2 - time1;
	if (interval < 0) {
		interval += 24 * 60;
	} 
	printf("%d\n", interval);

	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;

	freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}	
	if (fp != stdin) fclose(fp);
}

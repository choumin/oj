#include <stdio.h>

#define MAX_COUNT	100000

int leap_year_mark[13] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int common_year_mark[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

int deal_one_line(void)
{
	int year = 0;
	int month = 0;
	int day = 0;
	int leap_or_common = 0;

	scanf("%d:%d:%d", &year, &month, &day);
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			leap_or_common = 1;
		}
	} else if (year % 4 == 0) {
			leap_or_common = 1;
	} 
	if (leap_or_common) 
		printf("%d\n", leap_year_mark[month] + day);
	else 
		printf("%d\n", common_year_mark[month] + day);
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

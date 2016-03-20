#include <stdio.h>

#define MAX_COUNT	100000

struct date{
	int y;
	int m;
	int d;
};
int leap_common_year[][13] = {{0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334}, 
								{0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335}};
int leap_common_month[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
								{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int leap_or_common(int y) 
{
	int flag = 0;

	if (y % 100 == 0) {
		if (y % 400 == 0) {
			flag = 1;
		} 
	} else if (y % 4 == 0){
		flag = 1;
	}
	return flag;
}
int get_interval(struct date date1, struct date date2)
{
	int i = 0;
	int sum = 0;
	int lcy[2] = {365, 366};
	int loc = 0;

	for (i = date1.y + 1; i < date2.y; i++) {
		sum += lcy[leap_or_common(i)];	
	}
	if (date1.y == date2.y) {
		loc = leap_or_common(date1.y);
		sum = (leap_common_year[loc][date2.m] + date2.d) - (leap_common_year[loc][date1.m] + date1.d) + 1;
	} else {
		loc = leap_or_common(date1.y);
		sum += (lcy[loc] - leap_common_year[loc][date1.m] - date1.d + 1);
		loc = leap_or_common(date2.y);
		sum += (leap_common_year[loc][date2.m] + date2.d);
	}
	return sum;
}

int deal_one_line(void)
{
	struct date date1;
	struct date date2;
	int tmp1 = 0;
	int tmp2 = 0;
	int interval = 1;

	if (scanf("%d", &tmp1) == EOF) 
		return 0;
	date1.y = tmp1 / 10000;
	date1.m = (tmp1 % 10000) / 100;
	date1.d = tmp1 % 100;
	scanf("%d", &tmp2);
	date2.y = tmp2 / 10000;
	date2.m = (tmp2 % 10000) / 100;
	date2.d = tmp2 % 100;

	if (tmp1 > tmp2) {
		interval = get_interval(date2, date1);
	} else if (tmp1 < tmp2){
		interval = get_interval(date1, date2);
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

	fp = freopen("input.txt", "r", stdin);
/*
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/	
	while (flag) {
		flag = deal_one_line();
	}
	if (fp != stdin) fclose(fp);
}

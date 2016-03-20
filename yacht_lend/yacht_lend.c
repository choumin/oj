#include <stdio.h>

#define MAX_COUNT	101

struct yacht
{
	int begin;
	int end;
};
struct yacht ship[MAX_COUNT];

int deal_one_line(void)
{
	int ret = 0;
	int count = 0;
	float sum = 0;
	int hour = 0;
	int minute = 0;
	char type = 0;
	int ship_num = 0;
	int tmp= 0;
	int i = 0;
	int average = 0;

	ret = scanf("%d %c %d:%d", &ship_num, &type, &hour, &minute);
	if (ret == EOF || ship_num == -1) {
		return 1;
	}
	for (i = 0; i < MAX_COUNT; i++) {
		ship[i].begin = -1;
		ship[i].end = -1;
	}
	while (ret != EOF && ship_num != 0) {
		tmp = hour * 60 + minute;
		if (type == 'S') {
			ship[ship_num].begin = tmp;
		} else {
			ship[ship_num].end = tmp;
		}
		ret = scanf("%d %c %d:%d", &ship_num, &type, &hour, &minute);
	}
	for (i = 0; i < MAX_COUNT; i++) {
		if (ship[i].begin != -1 && ship[i].end != -1) {
			sum += ship[i].end - ship[i].begin;
			count++;
		}
	}

	if (count) {
		average = (int)(sum / count + 0.5);
		printf("%d %d\n", count, average);
	} else {
		printf("0 0\n");
	}

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

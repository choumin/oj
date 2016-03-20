#include <stdio.h>

#define MAX_COUNT	100

struct coor
{
	float x;
	float y;
};
struct coor data_array[MAX_COUNT] = {0.0};

int deal_one_line(void)
{
	int num_count = 0;
	int i = 0;
	float delt = 0;

	scanf("%d", &num_count);
	for (i = 0; i < num_count; i++) {
		scanf("%f", &(data_array[i].x));
		scanf("%f", &(data_array[i].y));
	}

	for (i = 2; i < num_count; i++) {
		delt = (data_array[1].y - data_array[0].y) * (data_array[i].x - data_array[0].x) 
			- (data_array[i].y - data_array[0].y) * (data_array[1].x - data_array[0].x);
		delt = delt < 0 ? delt * -1 : delt;
		if (delt > 0.000001) 
			break;
	}
	if (i >= num_count) {
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
	
	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	if (fp != stdin) fclose(fp);
}

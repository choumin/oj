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
	struct coor m, n, l;
	int flag = 1;
	int j = 0;
	int k = 0;

	scanf("%d", &num_count);
	for (i = 0; i < num_count; i++) {
		scanf("%f", &(data_array[i].x));
		scanf("%f", &(data_array[i].y));
	}

	for (i = 0; i < num_count && flag; i++) {
		m = data_array[i];
		for (j = i + 1; j < num_count && flag; j++) {
			n = data_array[j];
			for (k = j + 1; k < num_count && flag; k++) {
				l = data_array[k];
				delt = (n.y - m.y) * (l.x - m.x) - (l.y - m.y) * (n.x - m.x);
				delt = delt < 0 ? delt * -1 : delt;	
				if (delt <= 0.000001) 
					flag = 0;	
			}
		}
	}
		
	if (flag) {
		printf("No\n");
	} else {
		printf("Yes\n");
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

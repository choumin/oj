#include <stdio.h>

#define MAX_COUNT	101

int edge_length[MAX_COUNT];
int deal_one_line(int rest)
{
	int edge_count = 0;
	int i = 0;
	int tmp = 0;
	int sum = 0;

	scanf("%d", &edge_count);
	if (!edge_count) {
		return 0;	
	}
	for (i = 1;i < MAX_COUNT; i++) {
		edge_length[i] = 0;
	}

	for (i = 0; i < edge_count; i++) {
		scanf("%d", &tmp);
		edge_length[tmp]++;
	}
	for (i = 1; i < MAX_COUNT; i++) {
		if (edge_length[i] >= 3) {
			sum++;
		}
		//sum += edge_length[i] / 3;
	}
/*	if (rest == 1) {
		printf("%d", sum);
	} else {
		printf("%d\n", sum);		
	}
*/
	printf("%d\n", sum);
	return 0;
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
		flag = deal_one_line(item_count - i);
	}
	
	if (fp != stdin) fclose(fp);
}

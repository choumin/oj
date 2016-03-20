#include <stdio.h>

#define MAX_COUNT	100

int data[MAX_COUNT];

int deal_one_line(void)
{
	int num_count = 0;
	int i = 0;
	int sum = 0;

	scanf("%d", &num_count);
	for (i = 0; i < num_count; i++) {
		scanf("%d", data + i);
	}
	if (num_count % 2) {
		printf("%d\n", data[num_count / 2]);
	} else {
		sum = data[num_count / 2 - 1] + data[num_count / 2];
		if (sum % 2) {
			printf("%.1f\n", sum / 2.0);
		} else {
			printf("%d\n", sum / 2);	
		}
		
	}
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
		flag = deal_one_line();
	}
	
	if (fp != stdin) fclose(fp);
}

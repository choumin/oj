#include <stdio.h>

#define MAX_COUNT	10

int ori_matrix[MAX_COUNT][MAX_COUNT] = {0};
int ret_matrix[MAX_COUNT][MAX_COUNT] = {0};
int tmp_matrix[MAX_COUNT][MAX_COUNT] = {0};

int deal_one_line(void)
{
	int order_num = 0;
	int power_count = 0;
	int i = 0 ;
	int j = 0;
	int k = 0;
	int m = 0;

	scanf("%d%d", &order_num, &power_count);
	for (i = 0; i < order_num; i++) {
		for (j = 0; j < order_num; j++) {
			scanf("%d", ori_matrix[i] + j);
			if (power_count == 1) {
				ret_matrix[i][j] = ori_matrix[i][j];
			} else {
				tmp_matrix[i][j] = ori_matrix[i][j];
				ret_matrix[i][j] = 0;	
			}
		}
	}
	for (i = 0; i < power_count - 1; i++) {
		for (j = 0; j < order_num; j++) {
			for (k = 0; k < order_num; k++) {
				for (m = 0; m < order_num; m++) {
					ret_matrix[j][k] += tmp_matrix[j][m] * ori_matrix[m][k];
				}
			}
		}
		
		for (j = 0; i < power_count - 2 && j < order_num; j++) {
			for (k = 0; k < order_num; k++) {
				tmp_matrix[j][k] = ret_matrix[j][k];
				ret_matrix[j][k] = 0;
			}
		}
	}
	for (i = 0; i < order_num; i++) {
		for (j = 0; j < order_num - 1; j++) {
			printf("%d ", ret_matrix[i][j]);
		}
		printf("%d\n", ret_matrix[i][j]);
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

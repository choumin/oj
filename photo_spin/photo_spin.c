#include <stdio.h>

#define MAX_COUNT	50

char ori_photo[MAX_COUNT][MAX_COUNT] = {0};
char ret_photo[MAX_COUNT][MAX_COUNT] = {0};

int matrix_spin(int times, int *rowp, int *colp)
{
	int i = 0;
	int j = 0;
	int row = *rowp;
	int col = *colp;

	switch (times) 
	{
	case 0:
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				ret_photo[i][j] = ori_photo[i][j];
			}
		}
		break;
	case 1:
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				ret_photo[j][row - i - 1] = ori_photo[i][j];
			}
		}
		*rowp = col;
		*colp = row;
		break;
	case 2:
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				ret_photo[row - i - 1][col - j - 1] = ori_photo[i][j];
			}
		}
		break;
	case 3:
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				ret_photo[col - j - 1][i] = ori_photo[i][j];
			}
		}
		*rowp = col;
		*colp = row;
		break;
	}
	return 0;
}
int deal_one_line(void)
{
	int row = 0;
	int col = 0;
	int i = 0;
	int j = 0;
	int angle = 0;
	char ch = 0;

	scanf("%d%d", &row, &col);
	scanf("%c", &ch);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%c", ori_photo[i] + j);
		}
		scanf("%c", &ch);
	}
	scanf("%d", &angle);
	matrix_spin(angle / 90, &row, &col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%c", ret_photo[i][j]);
		}
		printf("\n");
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

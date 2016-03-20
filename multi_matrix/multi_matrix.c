#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	return 0;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int A[2][3] = {0};
	int B[3][2] = {0};
	int i = 0;
	int j = 0;
	int k = 0;
	int C[2][2] = {{0, 0}, {0, 0}};

	fp = freopen("input.txt", "r", stdin);
/*	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/
	for (i = 0; i < 2; i++) {
		scanf("%d%d%d", A[i], A[i] + 1, A[i] + 2);
	}
	for (i = 0; i < 3; i++) {
		scanf("%d%d", B[i], B[i] + 1);
	}
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			for (k = 0; k < 3; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	printf("%d %d \n%d %d \n", C[0][0], C[0][1], C[1][0], C[1][1]);
	if (fp != stdin) fclose(fp);
}

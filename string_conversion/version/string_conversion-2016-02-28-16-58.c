#include <stdio.h>

#define MAX_COUNT	1000
#define CHAR_NUM	26


int base_fee[CHAR_NUM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
int convert_fee[CHAR_NUM][CHAR_NUM] = {0};

int deal_one_line(void)
{
	int char_count[CHAR_NUM] = {0};
	int i = 0;
	int j = 0;
	char ch = 0;
	int total_fee = 0;
	int min_fee = 0;
	int flag = 0;

	while (scanf("%c", &ch) != EOF && ch != '\n') {
		char_count[ch - 'a']++;		
	}
	
	for (i = 0; i < CHAR_NUM; i++) {
		total_fee = 0;
		if (!char_count[i])
			continue;
		for (j = 0; j < CHAR_NUM; j++) {
			total_fee += (convert_fee[j][i] * char_count[j]);	
		}	
		if (flag == 0 || total_fee < min_fee) {
			min_fee = total_fee;
			flag = 1;
		}
	}
	
	printf("%d\n", min_fee);
	return 1;
}
void show_convert_fee(void) 
{
	int i = 0;
	int j = 0;

	for (i = 0; i < CHAR_NUM; i++) {
		for (j = 0; j < CHAR_NUM; j++)
			printf("%-2d ", convert_fee[i][j]);
		printf("\n");
	}
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;
	int j, k;
	char ch = 0;

	for (i = 0; i < CHAR_NUM; i++) {
		k = 0;
		for (j = CHAR_NUM - i; j < CHAR_NUM; j++) {
			convert_fee[i][k++] = base_fee[j];
		}
		for (j = 0; j < CHAR_NUM - i; j++) {
			convert_fee[i][k++] = base_fee[j];
		}
	}
//	show_convert_fee();
	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	scanf("%c", &ch);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
	if (fp != stdin) fclose(fp);

	return 0;
}

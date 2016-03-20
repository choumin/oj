#include <stdio.h>

#define MAX_COUNT	200

int perfect_num[MAX_COUNT];
int max = 0;
int count = 0;

int is_perfect(int num)
{
	int i = 0;
	int sum = 0;

	for (i = 1; i <= num / 2; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	if (sum == num) {
		return 1;
	} else {
		return 0;
	}
}
int deal_one_line(void)
{
	int i = 0;
	int num = 0;
	int ret = 0;
	int end = 0;

	ret = scanf("%d", &num);
	if (ret == EOF) {
		return 1;
	}	
	if (num > max) {
		for (i = max + 1; i <= num; i++) {
			if (is_perfect(i)) {
				perfect_num[count++] = i;
			} 
		}
		end = count;
		max = num;
	} else if (num >= perfect_num[0]){
		i = 0;
		while (i < count - 1) {
			if (num >= perfect_num[i] && num < perfect_num[i + 1]) {
				break;
			}
			i++;
		}
		end = i;
	}
	if (num >= perfect_num[0]) {
		for (i = 0; i < end - 1; i++) {
			printf("%d ", perfect_num[i]);
		}
		printf("%d\n", perfect_num[i]);	
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

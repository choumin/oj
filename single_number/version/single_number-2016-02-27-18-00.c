#include <stdio.h>
#include <string.h>

unsigned long long bit_sum_array[64] = {0};

int deal_one_line(void)
{
	int num_count = 0;
	
	int i = 0;
	int j = 0;
	unsigned long long tmp = 0;

	memset(bit_sum_array, 0, sizeof(unsigned long long) * 64);
	if (scanf("%d", &num_count) == EOF)
		return 0;
	for (i = 0; i < num_count; ++i) {
		scanf("%lld", &tmp);
		for (j = 0; j < 64; ++j) {
			bit_sum_array[j] += ((tmp >> j ) & 1);
		}
	}
	tmp = 0;
	for (j = 0; j < 64; ++j) {
		tmp |= ((bit_sum_array[j] % 3 ) << j);
	}
	printf("%lld\n", tmp);
	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;

	fp = freopen("input.txt", "r", stdin);
/*	scanf("%d", &item_count);
	for (i = 0; i < item_count; ++i) {
		flag = deal_one_line();
	}
*/
	while (flag) {
		flag = deal_one_line();
	}	
	if (fp != stdin) fclose(fp);
}

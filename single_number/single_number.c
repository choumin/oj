#include <stdio.h>

#define MAX_COUNT	100000

unsigned long long num_array[MAX_COUNT] = {0};

unsigned long long singleNumber(unsigned long long A[], int n) 
{
    unsigned long long count[64] = {0};
    unsigned long long result = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < 64; ++i) {
        for (j = 0; j < n; ++j) {
            if ((A[j] >> i) & 1) {
                ++count[i];
            }
        }
        result |= ((count[i] % 3) << i);
    }
    return result;
}
int deal_one_line(void)
{
	int num_count = 0;
	int i = 0;

	if (scanf("%d", &num_count) == EOF)
		return 0;
	for (i = 0; i < num_count; ++i) {
		scanf("%lld", num_array + i);
	}
	printf("%lld\n", singleNumber(num_array, num_count));
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
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/
	while (flag) {
		flag = deal_one_line();
	}	
	if (fp != stdin) fclose(fp);
}

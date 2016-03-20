#include <stdio.h>

#define MAX_COUNT	100000

int deal_one_line(void)
{
	int num_count = 0;
	int max_len = 1;
	int i = 0;
	int seq_len = 1;
	int step = 0;
	int pre = 0;
	int begin = 1;
	int val = 0;

	scanf("%d", &num_count);
	scanf("%d", &pre);
	for (i = 0; i < num_count - 1; i++) {
		scanf("%d", &val);
		if (begin) {
			step = val - pre;
			seq_len = 2;
			begin = 0;
		} else {
			if (val - pre == step) {
				seq_len++;
			} else {
				step = val - pre;
				seq_len = 2;
			}				
		}
		pre = val;
		max_len = max_len < seq_len ? seq_len : max_len;
	}
	printf("%d\n", max_len);

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

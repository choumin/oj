#include <stdio.h>

#define MAX_LEN		128
#define MAX_COUNT 	100

int num_array[MAX_COUNT][MAX_LEN];
char ret_str[MAX_LEN];

int deal_one_line(void)
{
	int ret = 0;
	char ch = 0;
	char tmp = 0;
	int i = 0;
	int j = 0;
	int max_index = 0;
	int c = 0;
	int count = 0;
	int sum = 0;
	int k = MAX_LEN - 2;

	ret = scanf("%c%c", &ch, &tmp);
	if (ret == EOF || (ch == '0' && tmp == '\n')) {
		return 1;
	}
	for (i = 0; i < MAX_LEN; i++) {
		ret_str[i] = 0;
	}
	i = 0;
	while (!(ret == EOF || (ch == '0' && tmp == '\n'))) {
		j = 0;
		num_array[i][++j] = ch;		
		while (tmp != '\n') {
			num_array[i][++j] = tmp;		
			scanf("%c", &tmp);
		}
		num_array[i++][0] = j;
		if (j > max_index) {
			max_index = j;
		}
		ret = scanf("%c%c", &ch, &tmp);
	}
	count = i;
	for (j = max_index; j > 0; j--) {
		sum = c;
		for (i = 0; i < count; i++) {
			if (num_array[i][0] > 0) {
				sum += num_array[i][num_array[i][0]] - '0';
				num_array[i][0]--;
			}
		}
		ret_str[k--] = sum % 10 + '0';
		c = sum / 10;
	}
	while (c) {
		ret_str[k--] = c % 10 + '0';	
		c /= 10;
	}
/*	i = 0;
	while (!ret_str[i]) {
		i++;
	}
*/
	printf("%s\n", ret_str + k + 1);

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

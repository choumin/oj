#include <stdio.h>

#define MAX_COUNT	100000
#define MAX_NUM_LEN	20

int deal_one_line(void)
{
	return 0;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int sum = 0;
	int i = 0;
	unsigned int k = 0;
	double num = 0;
	char str[MAX_NUM_LEN] = {0};
	unsigned int end = 1;
	char ch = 0;
	int j = 0;
	double left = 0;
	unsigned int begin = 0;
	unsigned int tmp = 0;


	fp = freopen("input.txt", "r", stdin);
/*	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/
	scanf("%c", &ch);
	while (ch != '\n') {
		str[i++] = ch;
		scanf("%c", &ch);	
	}
	if (i % 2) {
		end = 4;
	} else {
		end = 1;
	}
	for (j = 0; j < i / 2; j++) {
		end *= 10;
	}
	begin = end / 5;

	for (j = 0; j < i; j++) {
		num = num * 10 + str[j] - '0';
	}

	for (k = begin; k < end; k++) {
		tmp = k;
		sum =  0;
		while (tmp) {
			sum += tmp % 10;
			tmp /= 10;
		} 
		left = k;
		left = left * left + sum * left;
		//left = k * k + sum * k;
		if (left == num) {
			break;
		}
	}
	if (left == num) {
		printf("%u\n", k);
	} else {
		printf("-1\n");
	}
	if (fp != stdin) fclose(fp);
	return 0;
}

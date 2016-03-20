#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_COUNT	64

char str[MAX_COUNT];

int deal_one_line(void)
{
	int ret = 0;
	char ch = 0;
	int i = 0;
	int left_2 = 0;
	int left_1 = 0;
	int left_0 = 0;
	int right_2 = 0;
	int right_1 = 0;
	int right_0 = 0;
	int num = 1;
	int flag = 0;
	int prefix = 1;
	int a = 0;
	int b = 0;
	int c = 0;
	double delt = 0;
	double x1 = 0;
	double x2 = 0;

	ret = scanf("%c", &ch);
	if (ret == EOF) {
		return 1;
	} 

	memset(str, 0, MAX_COUNT);
	while (ch != '\n') {
		str[i++] = ch;
		scanf("%c", &ch);
	}
	i = 0;
	while (str[i]) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = str[i++] - '0';
			while (str[i] >= '0' && str[i] <= '9') {
				num = num * 10 + str[i++] - '0';
			}
			num *= prefix;
			if (str[i] != 'x') {
				if (flag == 0) {
					left_0 += num;
				} else {
					right_0 += num;
				}
			}
		} else if (str[i] == '-') {
			prefix = -1;
			if (str[i + 1] == 'x') {
				num = -1;
			}
			i++;
		} else if (str[i] == '+') {
			prefix = 1;
			if (str[i + 1] == 'x') {
				num = 1;
			}
			i++;
		} else if (str[i] == '=') {
			flag = 1;
			i++;
		} else if (str[i] == 'x') {
			switch (str[i + 1]) 
			{
			case '^':
				if (flag == 0) {
					left_2 += num;
				} else {
					right_2 += num;
				}
				i += 3;
			break;
			case 0:
				right_1 += num;
				i++;
			break;
			case '+':
			case '-':
				if (flag == 0) {
					left_1 += num;
				} else {
					right_1 += num;
				}
				i++;
			break;
			case '=':
				left_1 += num;
				i++;
			break;
			}
		}
	}
	a = left_2 - right_2;
	b = left_1 - right_1;
	c = left_0 - right_0;
	if (a == 0) {
		if (b == 0) {
			printf("No Solution\n");
		} else {
			printf("%.2lf\n", (-1.0) * c / b );		
		}
		return 0;
	}
	delt = b * b - 4 * a * c;
	if (delt < 0) {
		printf("No Solution\n");
		return 0;
	} 
	delt = sqrt(delt);
	x1 = (-1 * b + delt) / (2 * a);
	x2 = (-1 * b - delt) / (2 * a);

	if (x1 > x2) {
		delt = x1;
		x1 = x2;
		x2 = delt;
	}
	printf("%.2lf %.2lf\n", x1, x2);

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

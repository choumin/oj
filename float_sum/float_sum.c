#include <stdio.h>
#include <string.h>

#define MAX_COUNT	204

unsigned char f1[MAX_COUNT];
unsigned char f2[MAX_COUNT];
unsigned char sum_str[MAX_COUNT];

int add_str(char *str1, int end1, char *str2, int end2, int c, char *ret_str, int mode)
{
	int max = end1 > end2 ? end1 : end2;
	int i = 0;
	int sum = 0;
	int j = max;
	int delt = end1 - end2 > 0 ? end1 - end2 : end2 - end1;
	char *p = NULL;
	int k = 0;

	if (mode == 0) {
		if (end1 < end2) {
			p = str2;
			k = end2;
		} else if (end1 > end2) {
			p = str1;
			k = end1;
		}
		for (i = 0; i < delt; i++) {
			ret_str[j--] = p[k--];
		}

		max -= delt;
		for (i = max; i > 0; i--) {
			sum = c;
			sum += str1[i] - '0' + str2[i] - '0';	
			ret_str[j--] = sum % 10 + '0';
			c = sum /10;
		} 
	} else {
		if (end1 < end2) {
			for (i = end2; i > 0; i--) {
				sum = c;
				if (end1 > 0) {
					sum += str1[end1--] - '0' + str2[end2--] - '0';	
				} else {
					sum += str2[end2--] - '0';
				}
				
				ret_str[i] = sum % 10 + '0';
				c = sum / 10;
			}
		} else {
			for (i = end1; i > 0; i--) {
				sum = c;
				if (end2 > 0) {
					sum += str1[end1--] - '0' + str2[end2--] - '0';	
				} else {
					sum += str1[end1--] - '0';
				}
				
				ret_str[i] = sum % 10 + '0';
				c = sum / 10;
			}
		}
	}

	return c;
}
int deal_one_line(void)
{
	char ch = 0;
	int ret = 0;
	int i = 0;
	int j = 0;
	int c = 0;
	unsigned char *p = NULL;
	int max = 0;
	int pi1 = 0;
	int pi2 = 0;
	int sum = 0;
	int delt = 0;
	int begin = 0;
	int end = 0;
	int no_dec = 0;
	int no_int = 0;

	for (i = 0; i < MAX_COUNT; i++) {
		sum_str[i] = 0;
	}

	while (scanf("%c", &ch) != EOF && ch == '\n') {
		;
	}

	p = f1;
	for (i = 0; i < 2; i++) {
		j = 0;
		p[++j] = ch;
		while (scanf("%c", &ch) != EOF && ch != '\n') {
			if (ch == '.') {
				if (i == 0) {
					pi1 = j + 1;
				} else {
					pi2 = j + 1;
				}
			}
			p[++j] = ch;	
		}
		p[0] = j;
		if (i == 0) {
			p = f2;
			scanf("%c", &ch);			
		}
	}

	delt = pi1 - pi2;
	delt = delt > 0 ? delt : delt * -1;
	if (pi1 < pi2) {
		for (i = f1[0]; i > 0; i--) {
			f1[i + delt] = f1[i];
		}
		for (i = 1; i <= delt; i++) {
			f1[i] = '0';
		}
		f1[0] += delt;
	} else if (pi2 < pi1){
		for (i = f2[0]; i > 0; i--) {
			f2[i + delt] = f2[i];
		}
		for (i = 1; i <= delt; i++) {
			f2[i] = '0';
		}
		f2[0] += delt;
	}

	delt = f1[0] - f2[0];
	delt = delt > 0 ? delt : delt * -1;
	if (f1[0] < f2[0]) {
		for (i = 1; i <= delt; i++) {
			f1[f1[0] + i] = '0';
		}
	} else if (f2[0] < f1[0]){
		for (i = 1; i <= delt; i++) {
			f2[f2[0] + i] = '0';
		}
	}
	max = f1[0] > f2[0] ? f1[0] : f2[0];
	j = MAX_COUNT - 2;
	
	for (i = max; i > 0; i--) {
		if (f1[i] == '.') {
			sum_str[j--] = '.';
			continue;
		}
		sum = c;
		sum += f1[i] - '0' + f2[i] - '0';
		sum_str[j--] = sum % 10 + '0';
		c = sum / 10;
	}
	if (c) {
		sum_str[j] = c % 10 + '0';
	}
	j = MAX_COUNT - 2;
	while (j > 0 && sum_str[j] == '0'){
		j--;
	}
	end = j;
	if (sum_str[end] == '.') {
		end--;
		no_dec = 1;
	}
	j = 0;
	while (j < MAX_COUNT && (!sum_str[j] || sum_str[j] == '0')) {
		j++;
	}
	begin = j;
	if (sum_str[begin] == '.') {
		no_int = 1;
	} 
	if (no_int && no_dec) {
		printf("0\n");
	} else {
		for (i = begin; i <= end; i++) {
			printf("%c", sum_str[i]);
		}
		printf("\n");
	}
/*	j = 0;
	while (!sum_str[j]) {
		j++;
	}
	printf("%s\n", sum_str + j);
	
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		if (ch == '.') {
			p[0] = j;
			p = f1[1];
			j = 0; 
		} else {
			p[++j] = ch;	
		}
	}
	p[0] = j;

	j = 0;
	p = f2[0];
	scanf("%c", &ch);
	p[++j] = ch;
	while (scanf("%c", &ch) != EOF && ch != '\n') {
		if (ch == '.') {
			p[0] = j;
			p = f2[1];
			j = 0;
		} else {
			p[++j] = ch;
		}
	}
	p[0] = j;

	c1 = add_str(f1[1], f1[1][0], f2[1], f2[1][0], 0, ret_dec, 0);
	c2 = add_str(f1[0], f1[0][0], f2[0], f2[0][0], c1, ret_int, 1);
	ret_int[0] = c2 + '0';

	p = ret_int;
	if (!c2) {
		p++;
	} 
	max = f1[1][0] > f2[1][0] ? f1[1][0] : f2[1][0];
	while (ret_dec[max] == '0') {
		ret_dec[max--] = 0;
	}
	printf("%s", p);
	if (strlen(ret_dec + 1)) {
		printf(".%s\n", ret_dec + 1);	
	} else {
		printf("\n");
	}
*/
	
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

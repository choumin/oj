#include <stdio.h>
#include <string.h>

#define MAX_COUNT	104

char f1[2][MAX_COUNT];
char f2[2][MAX_COUNT];
char ret_int[MAX_COUNT];
char ret_dec[MAX_COUNT];

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
	int c1 = 0;
	int c2 = 0;
	char *p = NULL;
	int max = 0;

	for (i = 0; i < MAX_COUNT; i++) {
		ret_int[i] = 0;
		ret_dec[i] = 0;
	}

	while (scanf("%c", &ch) != EOF && ch == '\n') {
		;
	}
	j = 0;
	p = f1[0];
	p[++j] = ch;
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

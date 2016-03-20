#include <stdio.h>

#define MAX_COUNT	400

int deal_one_line(void)
{
	int a = 0;
	int b = 0;
	int c = 0;
	int numerator = 1;
	int denominator = 1;

	scanf("%d%d", &a, &b);
	if (a == b) {
		denominator = 1 << (a - 1); 		
	} else {
		c = a - b;
		c = c < 0 ? c * -1 : c;
		numerator += 1 << c;
		c = a < b ? b : a;
		denominator = 1 << c;
	}

	printf("%d/%d\n", numerator, denominator);
	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;
//	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
//	if (fp != stdin) fclose(fp);
}

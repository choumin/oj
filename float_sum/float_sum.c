#include <stdio.h>

#define MAX_COUNT	204

char f1[MAX_COUNT];
char f2[MAX_COUNT];
char ret[MAX_COUNT];

int deal_one_line(void)
{
	char ch = 0;
	int ret = 0;
	int i = 0;
	int j = 0;
	int ilen1 = 0;
	int dlen1 = 0;
	int ilen2 = 0;
	int dlen2 = 0;
	int c = 0;
	int max_len = 0;

	while (scanf("%c", &ch) != EOF && ch == '\n') {
		;
	}
	j = 0;
	f1[++j] = ch;
	while (scanf("%c", &ch) != EOF && ch != '\n')) {
		if (ch == '.') {
			idlen1 = j;
		}
		f1[++j] = ch;
	}
	f1[0] = j;
	dlen1 = j - ilen1 - 1;

	j = 0;
	scanf("%c", &ch);
	f2[++j] = ch;
	while (scanf("%c", &ch != EOF && ch != '\n')) {
		if (ch == '.') {
			idlen2 = j;
		}
		f2[++j] = ch;
	}
	f2[0] = j;
	dlen2 = j - ilen2 - 1;

	if (dlen1 > dlen1) {
		if ()
	}
	max_len = f2[0] > f1[0] ? f2[0] : f1[0]; 
	for () 
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

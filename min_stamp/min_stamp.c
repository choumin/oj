#include <stdio.h>

#define MAX_COUNT	32
#define MAX_VALUE	128	

int stamp[MAX_COUNT];
int dp[MAX_VALUE];
int deal_one_line(void)
{
	int ret = 0;
	int m = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int count = 0;
	int j = 0;
	int first = 1;

	ret = scanf("%d%d", &m, &n);
	if (ret == EOF) {
		return 1;
	}
	for (i = 0; i <= m; i++) {
		dp[i] = 123123123;
	}
	dp[0]=0;
	for (i = 0; i < n; i++) {
		scanf("%d", stamp + i);
	}
	/*
	for (i = 0; i <= m; i++) {
		first = 1;
		for (j = 0; j < n; j++) {
			if (first && i - stamp[j] == stamp[j]) {
				first = 0;
				continue;
			}
			if (i - stamp[j] < 0) {
				break;
			}
			if(i - stamp[j] >= 0 && dp[i] > dp[i - stamp[j]] + 1) {
				dp[i] = dp[i - stamp[j]] + 1;
			}
		}//重复使用
	}*/
	/*
	for (i = 0; i < n; i++) {
		for (j = stamp[i]; j <= m; j++) {
			if (dp[j] > dp[j - stamp[i]] + 1) {
				dp[j] = dp[j - stamp[i]] + 1;
			}
		}
	}//小弟已经吃掉了邮票，再询问老大吃不吃，可能会使老大受骗。
	*/
	for (i = 0; i < n; i++) {//每次有邮票了，如果吃了能瘦，那就吃，如果吃了不能瘦，那就等下一张，一开始非常胖。
		//一张邮票可以被多个人吃，吃了都能瘦，且还能自底向上（邮票的大小是升序）的传染。
		for (j = m; j >= stamp[i]; j--) {//按资排辈，最小的先吃，因为先来的面值小，老大看不上，老大得等。
			//大人吃大份，小孩吃小份，其实不是不吃，只是吃不了，吃了不能瘦。
			if (dp[j] > dp[j - stamp[i]] + 1) {//若此时邮票为3，则dp[0]和dp[1]已吃,dp[3]和dp[4]可以吃。
				dp[j] = dp[j - stamp[i]] + 1;
			}
		}
	}//老大谦让小弟，最后都让小弟先吃掉了。
	//虽然两者的目的都是让小弟先于老大吃掉邮票，但是后种方式更加安全。
	if (dp[m] != 123123123) {
		printf("%d\n", dp[m]);
	} else {
		printf("0\n");
	}

	return 0;
}
int main(void)
{
	int file_end = 0;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;

	fp = freopen("input.txt", "r", stdin);

	while (!file_end) {
		file_end = deal_one_line();
	}
	if (fp != stdin) fclose(fp);
}

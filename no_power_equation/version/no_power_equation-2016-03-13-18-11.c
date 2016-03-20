#include <stdio.h>

#define MAX_COUNT	100000
#define MAX_NUM_LEN	20

int deal_one_line(void)
{
	return 0;
}
int get_sum(long long int num)
{
	int sum = 0;

	while (num) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	long long int i = 0;
	long long int begin = 1;
	long long int end = 9;
	long long int times = 0;
	long long int num = 0;
	long long int left1 = 0;
	long long int left2 = 0;
	int cnt = 1;
	long long tmp = 0;
	int find = 0;


	fp = freopen("input.txt", "r", stdin);
/*	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/
	scanf("%lld", &num);
	cnt = get_sum(begin);
	left1 = begin * begin + begin * cnt;
	cnt = get_sum(end);
	left2 = end * end + end * cnt;
	while (!(left1 <= num && num <= left2)) {
		begin *= 10;
		end = end * 10 + 9;
		
		cnt = get_sum(begin);
		left1 = begin * begin + begin * cnt;
		cnt = get_sum(end);
		left2 = end * end + end * cnt;
	}
	if (left1 == num) {
		find = 1;
		i = begin;
		goto RET;
	}
	if (left2 == num) {
		i = end;
		find = 1;
		goto RET;
	}
	
	times = begin;
	while (times != 1) {
		end = begin + times - 1;

		cnt = get_sum(begin);
		left1 = begin * begin + begin * cnt;
		cnt = get_sum(end);
		left2 = end * end + end * cnt;
	
		while (!(left1 <= num && num <= left2)) {
			begin = end + 1;
			end = begin + times - 1;

			cnt = get_sum(begin);
			left1 = begin * begin + begin * cnt;
			cnt = get_sum(end);
			left2 = end * end + end * cnt;

		}
	/*	end = begin + times - 1;
		cnt = get_sum(end);
		left = end * end + end * cnt;
		while (left < num) {
			begin = end;
			end += times - 1;
			cnt = get_sum(end);
			left = end * end + end * cnt;
		}
		if (left == num) {
			i = end;
			goto RET;
		}
	*/
		if (left1 == num) {
			find = 1;
			i = begin;
			goto RET;
		}
		if (left2 == num) {
			find = 1;
			i = end;
			goto RET;
		}
		times /= 10;
	}
	for (i = begin; i <= end; i++) {
		cnt = get_sum(i);
		left1 = i * i + i * cnt;
		if (left1 == num) {
			find = 1;
			break;
		}
	}
RET:
	if (find) {
		printf("%lld\n", i);
	} else {
		printf("-1\n");
	}

	if (fp != stdin) fclose(fp);
}

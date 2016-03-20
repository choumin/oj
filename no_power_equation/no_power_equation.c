#include <stdio.h>

#define MAX_COUNT	100

int get_sum(unsigned long long int num)
{
	int sum = 0;

	while (num) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}
unsigned long long int get_root(int b, unsigned long long int c) 
{
	unsigned long long int delt = b * b + 4 * c;
	unsigned long long int t1 = 1;
	unsigned long long int t2 = 10;
	unsigned long long int p = 1;
	unsigned long long int times = 1;
	unsigned long long int i = 0;
	unsigned long long int ret = 0;
	unsigned long long int root = 0;

	p = t2 * t2;
	while (p < delt) {
		t2 *= 10;
		p = t2 * t2;
	}
	times = t1 = t2 / 10;
	if (p == delt) {
		i = t2;
		goto RET;
	}
	while (times != 1) {
		t2 = t1 + times;
		p = t2 * t2;
		while (p < delt) {
			t1 = t2;
			t2 = t1 + times;
			p = t2 * t2;
		}
		if (p == delt) {
			i = t2;
			goto RET;
		}
		times /= 10;
	}
	for (i = t1; i <= t2; i++) {
		p = i * i;
		if (p == delt) {
			break;
		}
	}
RET:
	if (p == delt) {
		if ((i - b) % 2 == 0) {
			root = (i - b) / 2;
			if (get_sum(root) == b) {
				ret = root;
			}
		}
	} 
	return ret;
}
int main(void)
{
	int find = 0;
	FILE *fp = NULL;
	int i = 0;
	unsigned long long int num = 0;
	unsigned long long int array[MAX_COUNT] = {0};
	unsigned long long int root = 0;
	unsigned long long int min_root = 0;

	fp = freopen("input.txt", "r", stdin);
	scanf("%lld", &num);
	for (i = 1; i < 90; i++) {
		root = get_root(i, num);
		if (root) {
			if (!find) {
				min_root = root;
				find = 1;
			} else if (root < min_root){
				min_root = root;
			}
		}
	}
	if (find) {
		printf("%lld\n", min_root);
	} else {
		printf("-1\n");
	}
	
	if (fp != stdin) fclose(fp);
}

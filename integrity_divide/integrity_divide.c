#include <stdio.h>
#include <string.h>

#define MAX_COUNT	1001

int prime_num[MAX_COUNT];
int prime_count = 0;
int init = 0;
int elem_num[MAX_COUNT];
int base_p[MAX_COUNT];

int is_prime(int num) 
{
	int i = 0;
	int j = 0;
	int prime = 0;

	if (!init) {
		for (i = 2; i <= 1000; i++) {
			prime = 1;
			for (j = 2; j <= i / 2; j++) {
				if (i % j == 0) {
					prime = 0;
					break;
				}
			}
			if (prime) {
				prime_num[prime_count++] = i;
			}
		}
		init = 1;
	} 

	for (i = 0; i < prime_count; i++) {
		if (prime_num[i] == num) {
			return 1;
		}
	}
	
	return 0;
}

int deal_one_line(void)
{
	int ret = 0;
	int num = 0;
	int base = 0;
	int tmp = 0;
	int j = 0; 
	int i = 0;
	int min = 0;
	int max = 0;

	ret = scanf("%d%d", &num, &base);
	if (ret == EOF) {
		return 1;
	}
	memset(elem_num, 0, MAX_COUNT * sizeof(int));
	memset(base_p, 0, MAX_COUNT * sizeof(int));
	for (i = 2; i <= num; i++) {
		tmp = i;
		while (!is_prime(tmp)) {
			for (j = 2; j <= tmp / 2; j++) {
				if (tmp % j == 0) {
					elem_num[j]++;
					tmp /= j;
					break;
				}
			}
		}
		elem_num[tmp]++;
	}
	tmp = base;
	while (!is_prime(tmp)) {
		for (j = 2; j <= tmp / 2; j++) {
			if (tmp % j == 0) {
				base_p[j]++;
				tmp /= j;
				break;
			}
		}
	}
	base_p[tmp]++;
	j = 2;
	while (!base_p[j]) {
		j++;
	}
	min = elem_num[j] / base_p[j];
	/*
	max = base_p[j];
	if (elem_num[j] < base_p[j]) {
		min = 0;
	} else {
		min = elem_num[j];
	}
	*/
	for (j++; min && j < MAX_COUNT; j++) {
		if (!base_p[j]) {
			continue;
		}
		if (min > (elem_num[j] / base_p[j])) {
			min = elem_num[j] / base_p[j];
		}
		/*
		if (elem_num[j] < base_p[j]) {
			min = 0;
		} else if (min > elem_num[j]) {
			min = elem_num[j];
		}
		if (max < base_p[j]) {
			max = base_p[j];
		}
		*/
	}

	printf("%d\n", min);

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

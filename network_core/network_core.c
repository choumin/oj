#include <stdio.h>

#define MAX_COUNT	51

int bit[MAX_COUNT] = {0};
char photo[MAX_COUNT][MAX_COUNT] = {0};
char queue[MAX_COUNT * MAX_COUNT] = {0};
char distance[MAX_COUNT] = {0};
char visit[MAX_COUNT] = {0};

int get_sum_len(int index, char *distance) 
{
	int head = 0;
	int tail = 0;
	int last = 0;
	int level = 0;
	int m = 0;
	int sum = 0;
	int i = 0;

	for (i = 1; i < MAX_COUNT; i++) {
		visit[i] = 0;
	}
	queue[head++] = index;
	visit[index] = 1;
	while (head != tail) {
		m = queue[tail];
		if (level < distance[m]) {
			distance[m] = level;
		}
		for (i = 1; i < MAX_COUNT; i++) {
			if (!visit[i] && photo[m][i] == 1) {
				queue[head++] = i;
				visit[i] = 1;
			}
		}
		if (tail == last) {
			level++;
			last = head - 1;
		} 
		tail++;
	}
	for (i = 1; i < MAX_COUNT; i++) {
		sum += distance[i];
	}

	return sum;
}
int deal_one_line(void)
{
	int node_count = 0;
	int edge_count = 0;
	int i = 0;
	int j = 0;
	int in = 0;
	int out = 0;
	int min_index = 0;
	int min = 0;
	int len = 0;

	scanf("%d%d", &node_count, &edge_count);
	for (i = 1; i < MAX_COUNT; i++) {
		bit[i] = 0;
		for (j = 1; j < MAX_COUNT; j++) {
			if (i == j) {
				photo[i][j] = 0;
				continue;
			}
			photo[i][j] = node_count;
		}
	}
	for (i = 0; i < edge_count; i++) {
		scanf("%d%d", &in, &out);
		photo[in][out] = 1;
		photo[out][in] = 1;
		bit[in] = 1;
		bit[out] = 1;
	}
	for (j = 1; j < MAX_COUNT; j++) {
		distance[j] = photo[1][j];
	}
	min = get_sum_len(1, distance);
	min_index = 1;
	for (i = 2; i < MAX_COUNT; i++) {
		if (!bit[i]) {
			continue;
		}
		for (j = 1; j < MAX_COUNT; j++) {
			distance[j] = photo[i][j];
		}
		len = get_sum_len(i, distance);
		if (len < min) {
			min = len;
			min_index = i;
		}
	}
	
	printf("%d\n", min_index);

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

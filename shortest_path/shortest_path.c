#include <stdio.h>
#include <string.h>

#define MAX_COUNT		1001

#define MAX_CHAR_NUM	127
const char max_char_num = MAX_CHAR_NUM;
const int max_num = (max_char_num << 24) + (max_char_num << 16) + (max_char_num << 8) + max_char_num;
int matrix[MAX_COUNT][MAX_COUNT] = {0};
int target_vec[MAX_COUNT] = {0};

int tmp_vec[MAX_COUNT] = {0};
int delivery(int begin, int *sum) 
{
	int i = 0;
	int next = begin;
	int min_index = 0;
	int min_path = max_num;

	memcpy(tmp_vec, matrix[begin], MAX_COUNT * sizeof(int));
//	printf("%d->", begin);
	while (1) {	
		min_index = 0;
		min_path = max_num;
		for (i = 1; i < MAX_COUNT; i++) {
			if (tmp_vec[i] < min_path) {
				min_index = i;
				min_path = tmp_vec[i];
			}
		}
		
		if (target_vec[min_index]) {
			target_vec[min_index] = 0;
			break;
		}
		tmp_vec[min_index] = max_num;
		for (i = 1; i < MAX_COUNT; i++) {
			if (i == begin || i == min_index)
				continue;
			if (matrix[min_index][i] != max_num && tmp_vec[i] > (matrix[min_index][i] + min_path)) {
				tmp_vec[i] = matrix[min_index][i] + min_path;
			}
		}
	}
	*sum = *sum + min_path;
	printf("\n%d:%d", min_index, min_path);
	//printf("\n%d:%d", min_path);
	return min_index;
}
int deal_one_line(void)
{
	int node_count = 0;
	int edge_count = 0;
	int target_count = 0;
	int first_vex = 0;
	int second_vex = 0;
	int fee = 0;
	int i = 0;
	int tmp = 0;
	int position = 1;
	int sum = 0;

	memset(*matrix, max_char_num, MAX_COUNT * MAX_COUNT * sizeof(int));
	memset(target_vec, 0, MAX_COUNT * sizeof(int));
	scanf("%d%d%d", &node_count, &edge_count, &target_count);
	for (i = 0; i < edge_count; i++) {
		scanf("%d%d%d", &first_vex, &second_vex, &fee);
		matrix[first_vex][second_vex] = fee;
		matrix[second_vex][first_vex] = fee;
	}
	for (i = 0; i < target_count; i++) {
		scanf("%d", &tmp);
		target_vec[tmp] = 1;
	}
	printf("%d->", 1);
	for (i = 0; i < target_count; i++) {
		position = delivery(position, &sum);
	}
	printf("\n%d\n", sum);
	return 1;
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

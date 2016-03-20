#include <stdio.h>
#include <string.h>
#include <sys/malloc.h>
#include <stdlib.h>

#define LIST_NAME_LEN	16
#define MAX_LIST		100
#define MAX_ELEM		100

struct list{
	char name[LIST_NAME_LEN];
	int *head;
	int elem_count;
	int used;
};
struct list list_array[MAX_LIST];
int pop_sort(int *array, int count) 
{
	int i = 0; 
	int j = 0;
	int tmp = 0;

	for (i = count; i > 0; i--) {
		for (j = 0; j < i - 1; j++) {
			if (array[j] > array[j + 1]) {
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
	return 0;
}
int deal_one_line(void)
{
	int op_count = 0;
	char ch = 0;
	int list_count = 0;
	char list_name[LIST_NAME_LEN] = {0};
	int i = 0;
	int j = 0;
	int find = 0;
	int id = 0;
	char key = 0;
	int num = 0;

	for (i = 0; i < MAX_LIST; i++) {
		list_array[i].used = 0;
		list_array[i].head = NULL;
		list_array[i].elem_count = 0;
	}
	scanf("%d", &op_count);
	scanf("%c", &ch);
	for (i = 0; i < op_count; i++) {
		j = 0;
		scanf("%c", &ch);
		while (ch != '=' && ch != '.' && ch != '[') {
			list_name[j++] = ch;
			scanf("%c", &ch);
		}
		list_name[j] = 0;
		find = 0;
		for (j = 0; j < list_count; j++) {
			if (!strcmp(list_name, list_array[j].name)) {
				find = 1;
				break;
			}
		}
		switch (ch) 
		{
		case '=':
			if (find) {
				list_array[j].elem_count = 0;
			} else {
				strcpy(list_array[list_count].name, list_name);
				list_array[list_count].head = (int *)malloc(sizeof(int) * MAX_ELEM);
				list_array[list_count].used = 1;
				list_count++;
			}
			scanf("%c", &ch);
			scanf("%c", &ch);
			scanf("%c", &ch);
		break;

		case '[':
			scanf("%d", &id);
			if (id < list_array[j].elem_count) {
				printf("%d\n", list_array[j].head[id]);
			} else {
				printf("ERROR\n");
			}
			scanf("%c", &ch);
			scanf("%c", &ch);
		break;
		case '.':
			scanf("%c", &key);
			scanf("%c", &ch);
			while (ch != '(') {
				scanf("%c", &ch);
			}
			if (key == 'a') {
				scanf("%d", &num);
				list_array[j].head[list_array[j].elem_count++] = num;
			} else {
				pop_sort(list_array[j].head, list_array[j].elem_count);
			}
			scanf("%c", &ch);
			scanf("%c", &ch);
		break;
		}	
	}
	for (i = 0; i < list_count; i++) {
		free(list_array[i].head);
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

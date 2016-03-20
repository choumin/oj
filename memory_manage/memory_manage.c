#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>

#define MAX_COUNT	100
int memory_list[MAX_COUNT] = {0};

int deal_one_line(void)
{
	int memory_block = 0;
	int i = 0;
	int tmp = 0;
	int memory_request = 0;	
	int suit_size = 0;
	int suit_index = 0;
	int j = 0;

	scanf("%d", &memory_block);
	for (i = 0; i < memory_block; i++) {
		scanf("%d", &tmp);
		memory_list[i] = tmp;
	}
	scanf("%d", &memory_request);
	for (i = 0; i < memory_request; i++) {
		scanf("%d", &tmp);
		suit_index = 0;
		suit_size = 0;
		for (j = 0; j < memory_block; j++) {
			if (memory_list[j] == 0)
				continue;
			if (memory_list[j] >= tmp) {
				if (suit_size == 0 || memory_list[j] < suit_size) {
					suit_size = memory_list[j];
					suit_index = j;
				} 
			}
		}
		if (suit_size) {
			memory_list[suit_index] = 0;
			printf("%d", suit_size);
		} else {
			printf("NULL");
		}
		if (i == memory_request - 1) {
			printf("\n");
		} else {
			printf(" ");
		}
	}
	
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

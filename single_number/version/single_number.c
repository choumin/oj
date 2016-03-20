#include <stdio.h>
#include <string.h>
#include <sys/malloc.h>
#include <stdlib.h>

#define MAX_COUNT	1024

struct node{
	long long data;
	struct node *next;
};

struct node hash_array[MAX_COUNT] = {0};
int deal_one_line(void)
{
	int num_count = 0;
	int i = 0;
	int j = 0;
	int count = 0;
	long long key = 0;
	long long tmp = 0;
	struct node *p = NULL;
	struct node *q = NULL;
	struct node *r = NULL;
	
	memset(hash_array, 0, sizeof(struct node) * MAX_COUNT);
	if (scanf("%d", &num_count) == EOF)
		return 0;

	for (i = 0; i < num_count; i++) {
		scanf("%lld", &tmp);
		key = tmp;
		key = (~key) + (key << 21);
		key = key ^ (key >> 24);
		key = key + (key << 19);
		key = key >> 54; 
		p = hash_array + key;
		count = 0;
		if (p->next == NULL) {
			q = (struct node *)malloc(sizeof(struct node));
			q->data = tmp;
			q->next = p->next;
			p->next = q;
			continue;
		}

		while (p->next) {
			if (tmp <= p->next->data) {
				r = p->next;
				while (r && tmp == r->data) {
					count++;
					r = r->next;
				}
				if (count == 2) {
					r = p->next;
					while (count > 0) {
						q = r->next;
						free(r);
						count--;
						r = q;
					}
					p->next = q;
				} else {
					q = (struct node *)malloc(sizeof(struct node));
					q->data = tmp;
					q->next = p->next;
					p->next = q;	
				}
				break;
			}
			p = p->next;
		}	
	}
	for (i = 0; i < MAX_COUNT; i++) {
		if (hash_array[i].next) {
			printf("%lld\n", hash_array[i].next->data);
			free(hash_array[i].next);
			break;
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
/*	scanf("%d", &item_count);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line();
	}
*/
	while (flag) {
		flag = deal_one_line();
	}	
	if (fp != stdin) fclose(fp);
}

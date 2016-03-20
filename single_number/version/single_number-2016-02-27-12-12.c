#include <stdio.h>
#include <string.h>
#include <sys/malloc.h>
#include <stdlib.h>

#define MAX_COUNT	1024

struct node{
	long long data;
	struct node *next;
};

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
	struct node *l = NULL;
	struct node *r = NULL;
	struct node head = {0, NULL};
	long long last = 0;

	if (scanf("%d", &num_count) == EOF)
		return 0;
	l = &head;
	for (i = 0; i < num_count; i++) {
		scanf("%lld", &tmp);
		if (tmp >= last) {
			p = l;
		} else {
			p = &head;
		}
		
		count = 0;
		while (p->next && tmp > p->next->data) {
			p = p->next;
		}
		if (p->next && tmp <= p->next->data) {
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
				last = tmp;
				l = p;
				continue;
			}
		}
		q = (struct node *)malloc(sizeof(struct node));
		q->data = tmp;
		q->next = p->next;
		p->next = q;	
		last = tmp;
		l = p;
	}
	printf("%lld\n", head.next->data);
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

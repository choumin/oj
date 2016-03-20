#include <stdio.h>
#include <sys/malloc.h>
#include <stdlib.h>

#define MAX_COUNT	100000

struct list{
	int val;
	int a;
	int b;
	struct list *next;
};

int deal_one_line(void)
{
	int op_num = 0;
	int count = 0;
	int i = 0;
	char ch = 0;
	char op_code = 0;
	int a = 0;
	int b = 0;
	struct list head = {0,0,0, NULL};
	struct list *np = NULL;
	struct list *p = NULL;
	struct list *q = NULL;

	scanf("%d", &op_num);
	for (i = 0; i < op_num; i++) {
		scanf("%c", &ch);
		scanf("%c", &op_code);
		ch = op_code;
		
		if (op_code == 'I') {
			while (ch != ' ') {
				scanf("%c", &ch);
			}
			scanf("%d+i%d", &a, &b);
			np = (struct list*)malloc(sizeof(struct list));
			np->next = NULL;
			np->val = a * a + b * b;
			np->a = a;
			np->b = b;
			count++;
			printf("Size: %d\n", count);
			
			p = &head;
			while (p->next && p->next->val > np->val ) {
				p = p->next;
			}
			np->next = p->next;
			p->next = np;

		} else {
			scanf("%c", &ch);
			scanf("%c", &ch);
			if (count == 0) {
				printf("Empty!\n");
			} else {
				p = head.next;
				printf("%d+i%d\n", p->a, p->b);
				head.next = p->next;
				free(p);
				count--;
				if (!count) {
					printf("Empty!\n");
				} else {
					printf("Size: %d\n", count);
				}
			}
		}
	}
	p = head.next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
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

#include <stdio.h>
#include <string.h>

#define MAX_COUNT	500
#define NAME_LEN	32
struct stu_info {
	char name[NAME_LEN];
	int sex;
	int y;
	int m;
	int d;
};
struct query_info {
	char name[NAME_LEN];
	int name_used;
	int sex;
	int sex_used;
	int y;
	int m;
	int d;
	int bir_used;
};
struct stu_info stu_array[MAX_COUNT];

int deal_one_line(void)
{
	int stu_count = 0;
	int query_count = 0;
	int i = 0;
	int j = 0;
	char ch = 0;
	struct query_info q = {"", 0, 0, 0, -1, -1, -1, 0};
	int k = 0;
	char key = 0;
	int find = 0;

	memset(stu_array, 0, sizeof(struct stu_info) * MAX_COUNT);
	scanf("%d%d", &stu_count, &query_count);
	for (i = 0; i < stu_count; i++) {
		scanf("%c", &ch);
		scanf("%c", &ch);
		j = 0;
		
		while (ch != ' ') {
			stu_array[i].name[j++] = ch;
			scanf("%c", &ch);
		}
		scanf("%c", &ch);
		if (ch == 'M') {
			stu_array[i].sex = 1;
		}
		while (ch != ' ') {
			scanf("%c", &ch);
		}
		scanf("%d/%d/%d", &(stu_array[i].y), &(stu_array[i].m), &(stu_array[i].d));
	}
	scanf("%c", &ch);
	for (i = 0; i < query_count; i++) {
		q.name_used = 0;
		q.sex = 0;
		q.sex_used = 0;
		q.y = -1;
		q.m = -1;
		q.d = -1;
		q.bir_used = 0;
		for (k = 0; k < 3; k++) {
			scanf("%c", &key);
			scanf("%c", &ch);
			while (ch != '\'') {
				scanf("%c", &ch);
			}
			if (key == 'N') {
				j = 0;
				scanf("%c", &ch);
				while (ch != '\'') {
					q.name[j++] = ch;
					scanf("%c", &ch);
				}
				q.name[j] = 0;
				q.name_used = 1;
			} else if (key == 'S') {
				scanf("%c", &ch);
				if (ch == 'M') {
					q.sex = 1;
				} 
				q.sex_used = 1;
				while (ch != '\'') {
					scanf("%c", &ch);
				}
			} else {
				scanf("%c", &ch);
				if (ch != '*') {
					q.y = 0;
					while (ch != '/') {
						q.y = q.y * 10 + ch - '0';
						scanf("%c", &ch);
					}	
				} else {
					scanf("%c", &ch);	
				}
				scanf("%c", &ch);
				if (ch != '*') {
					q.m = 0;
					while (ch != '/') {
						q.m = q.m * 10 + ch - '0';
						scanf("%c", &ch);
					}	
				} else {
					scanf("%c", &ch);
				}
				scanf("%c", &ch);
				if (ch != '*') {
					q.d = 0;
					while (ch != '\'') {
						q.d = q.d * 10 + ch - '0';
						scanf("%c", &ch);
					}	
				} else {
					scanf("%c", &ch);
				}
				q.bir_used = 1;
			}
			scanf("%c", &ch);
			if (ch == '\n') {
				break;
			}
		}
		find = 0;
		for (j = 0; j < stu_count; j++) {
			if (q.name_used) {
				if (strcmp(stu_array[j].name, q.name)) {
					continue;
				}
			}
			if (q.sex_used) {
				if (q.sex != stu_array[j].sex) {
					continue;
				}
			}
			if (q.bir_used) {
				if (q.y != -1 && q.y != stu_array[j].y) {
					continue;
				}
				if (q.m != -1 && q.m != stu_array[j].m) {
					continue;
				}
				if (q.d != -1 && q.d != stu_array[j].d) {
					continue;
				}
			}
			find =  1;
			printf("%s\n", stu_array[j].name);
		}
		if (!find) {
			printf("NULL\n");
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

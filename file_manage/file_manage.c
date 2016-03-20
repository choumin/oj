#include <stdio.h>
#include <string.h>
#include <sys/malloc.h>
#include <stdlib.h>

#define MAX_COUNT		100000
#define FILE_MAX_LEN	21
#define	MAX_LEN 		64
#define OP_LEN			16

struct file {
	char name[FILE_MAX_LEN];
};
struct dir_list {
	struct dir *dirp;
	struct dir_list *next;
};
struct file_list {
	struct file *filep;
	struct file_list *next;
};
struct dir {
	char name[FILE_MAX_LEN];
	struct dir_list *sub_dir_list;
	struct file_list *sub_file_list;
};

struct dir *find_dir(char *dir_name, struct dir *root) 
{
	struct dir *p = NULL;
	struct dir_list *q = NULL;
	if (strcmp(dir_name, root->name)) {
		q = root->sub_dir_list;
		while (p == NULL && q) {
			p = find_dir(dir_name, q->dirp);
			q = q->next;
		} 
	} else {
		p = root;
	}

	return p;
}

void destroy_file_system(struct dir *root) 
{
	struct dir_list *dlp = NULL;
	struct file_list *flp = NULL;
	struct file_list *flq = NULL;

	dlp = root->sub_dir_list;
	while (dlp) {
		destroy_file_system(dlp->dirp);
		dlp = dlp->next;
	}

	flp = root->sub_file_list;
	while (flp) {
		flq = flp->next;
		free(flp);
		flp = flq;	
	}
	free(root);
}
int deal_one_line(void)
{
	int op_num = 0;
	struct dir *root = NULL;
	char op_code[OP_LEN] = {0};
	int i = 0;
	int j = 0;
	char fch = 0;
	char lch = 0;
	char ch = 0;
	char parent[FILE_MAX_LEN] = {0};
	char child[FILE_MAX_LEN] = {0};
	struct dir *dp = NULL;
	struct dir_list *dlp = NULL;
	struct dir_list *p = NULL;
	struct file_list *flp = NULL;
	struct file_list *q = NULL;
	struct file *filep = NULL;
	struct dir *dirp = NULL;

	root = (struct dir *)malloc(sizeof(struct dir *));
	strcpy(root->name, "root");
	root->sub_dir_list = NULL;
	root->sub_file_list = NULL;
	scanf("%d", &op_num);
	for (i = 0; i < op_num; i++) {
		if (i == 0)
			scanf("%c", &ch);
		scanf("%c", &fch);
		while (scanf("%c", &ch) != EOF && ch != ' ') 
			lch = ch;
		if (fch == 'C') {
			j = 0;
			while (scanf("%c", &ch) != EOF && ch != ' ')
				child[j++] = ch;
			child[j] = 0;
			j = 0;
			while (scanf("%c", &ch) != EOF && ch != '\n')
				parent[j++] = ch;
			parent[j] = 0;
			dp = find_dir(parent, root);
			if (lch == 'R') {
				dirp = (struct dir *)malloc(sizeof(struct dir));
				dirp->sub_dir_list = NULL;
				dirp->sub_file_list = NULL;
				strcpy(dirp->name, child);

				dlp = (struct dir_list *)malloc(sizeof(struct dir_list));
				dlp->next = NULL;
				dlp->dirp = dirp;

				if (dp->sub_dir_list == NULL) {
				 	dp->sub_dir_list = dlp;	
				 	continue;
				}
				p = dp->sub_dir_list;
				while (p->next) {
				 	p = p->next;
				}
				p->next = dlp;
			} else if (lch == 'E') {
				filep = (struct file *)malloc(sizeof(struct file));
				strcpy(filep->name, child);
				
				flp = (struct file_list *)malloc(sizeof(struct file_list));
				flp->next = NULL;
				flp->filep = filep;

				if (dp->sub_file_list == NULL) {
					dp->sub_file_list = flp;
					continue;
				} 
				q = dp->sub_file_list;
				while (q->next) {
					q = q->next;
				}
				q->next = flp;
			}	
		} else if (fch == 'L') {
			j = 0;
			while (scanf("%c", &ch) != EOF && ch != '\n')
				parent[j++] = ch;
			parent[j] = 0;
			dp = find_dir(parent, root);
			if (lch == 'R') {
				p = dp->sub_dir_list;
				while (p) {
					printf("%s\n", p->dirp->name);
					p = p->next;
				}
			} else if (lch == 'E') {
				q = dp->sub_file_list;
				while (q) {
					printf("%s\n", q->filep->name);
					q = q->next;
				}
			}
		}
	}

	destroy_file_system(root);
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

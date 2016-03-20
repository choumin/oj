#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
	
#define MAX_COUNT	100

short photo[MAX_COUNT][MAX_COUNT];
char visited[MAX_COUNT][MAX_COUNT];
struct point
{
	int x;
	int y;
};

int right(struct point p, int row, int col, int pix, int delt)
{
	if ((p.x >= 0 && p.x < row) && (p.y >= 0 && p.y < col) 
		&& !visited[p.x][p.y] && abs(photo[p.x][p.y] - pix) <= delt)
		return 1;
	else 
		return 0;
}
int deal_one_line(void)
{
	int row = 0;
	int col = 0;
	int delt = 0;
	int i = 0;
	int j = 0;
	int find = 0;
	int tail = 0;
	int head = 0;
	struct point inp = {0, 0};
	struct point outp = {0, 0};
	int region_count = 0;
	struct point *queue = NULL;

	scanf("%d%d%d", &row, &col, &delt);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			visited[i][j] = 0;
			scanf("%d", photo[i] + j);
		}
	}
	queue = (struct point *)malloc(sizeof(struct point) * row * col);
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (visited[i][j]) 
				continue;
			find = 0;
			head = tail = 0;
			inp.x = i;
			inp.y = j;
			queue[head++] = inp;
			visited[inp.x][inp.y] = 1;
			while (head != tail) {
				outp = queue[tail++];
				
				inp.x = outp.x - 1; 
				inp.y = outp.y - 1;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
				
				inp.x = outp.x - 1;
				inp.y = outp.y;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
				
				inp.x = outp.x - 1;
				inp.y = outp.y + 1;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
				
				inp.x = outp.x;
				inp.y = outp.y - 1;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
				
				inp.x = outp.x;
				inp.y = outp.y + 1;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
				
				inp.x = outp.x + 1;
				inp.y = outp.y - 1;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
				
				inp.x = outp.x + 1, 
				inp.y = outp.y;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
				
				inp.x = outp.x + 1;
				inp.y = outp.y + 1;
				if (right(inp, row, col, photo[outp.x][outp.y], delt)) {
					queue[head++] = inp;
					visited[inp.x][inp.y] = 1;
				}
			}
			region_count++;
		}
	}
	printf("%d\n", region_count);
	free(queue);

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

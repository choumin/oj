#include <stdio.h>

#define MAX_COUNT	100000
#define REG_COUNT	4
#define	REG_LEN		2
#define MAX_BIN_LEN	20

int reg[REG_COUNT][REG_LEN] = {0};

int get_src(char *str, int len) 
{
	int src = 0;
	int i = 0;

	switch (str[len - 1]) 
	{
	case 'H':
		if (len == 2) {
			src = reg[str[0] - 'A'][0];
		} else {
			for (i = 0; i < len - 1; i++) {
				if (str[i] >= '0' && str[i] <= '9') {
					src = src * 16 + str[i] - '0';
				} else {
					if (str[i] >= 'A' && str[i] <= 'F') {
						src = src * 16 + str[i] - 'A' + 10;
					} else {
						src = src * 16 + str[i] - 'a' + 10;		
					}
				}
			}	
		}
	break;
	case 'B':
		for (i = 0; i < len - 1; i++) {
			src = src * 2 + str[i] - '0';
		}
	break;
	case 'X':
		src = reg[str[0] - 'A'][0] * 256 + reg[str[0] - 'A'][1];
	break;
	case 'L':
		src = reg[str[0] - 'A'][1];
	break;
	default:
		for (i = 0; i < len; i++) {
			src = src * 10 + str[i] - '0';
		}
	}
	return src;
}
int deal_one_line(void)
{
	int op_count = 0;
	char ch = 0;
	int i = 0;
	int j = 0;
	char key = 0;
	int dst = 0;
	int src = 0;
	int dst_index = 0;
	char xhl = 0;
	char str[MAX_BIN_LEN] = {0};

	for (i = 0; i < REG_COUNT; i++) {
		for (j = 0; j < REG_LEN; j++) {
			reg[i][j] = 0;
		}
	}
	scanf("%d", &op_count);
	scanf("%c", &ch);
	for (i = 0; i < op_count; i++) {
		scanf("%c", &key);
		scanf("%c", &ch);
		while (ch != ' ') {
			scanf("%c", &ch);
		}

		scanf("%c", &ch);
		dst_index = ch - 'A';
		scanf("%c,", &xhl);
		j = 0;
		scanf("%c", &ch);
		while (ch != '\n') {
			str[j++] = ch;
			scanf("%c", &ch);
		}
		src = get_src(str, j);

		if (key == 'M') {
			switch (xhl) 
			{
			case 'X':
				reg[dst_index][0] = src / 256;
				reg[dst_index][1] = src % 256;
			break;
			case 'H':
				reg[dst_index][0] = src;
			break;
			case 'L':
				reg[dst_index][1] = src;
			break;
			}
		} else {
			switch (xhl) 
			{
			case 'X':
				dst = reg[dst_index][0] * 256 + reg[dst_index][1];
				dst += src;
				reg[dst_index][0] = dst / 256;
				reg[dst_index][1] = dst % 256;
			break;
			case 'H':
				reg[dst_index][0] += src;
			break;
			case 'L':
				reg[dst_index][1] += src;
			break;	
			}
		}	
	}
	
	printf("%d %d %d %d\n", reg[0][0] * 256 + reg[0][1], reg[1][0] * 256 + reg[1][1],
		reg[2][0] * 256 + reg[2][1], reg[3][0] * 256 + reg[3][1]);
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

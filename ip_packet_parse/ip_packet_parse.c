#include <stdio.h>

#define MAX_COUNT	100000
#define IP_LEN      4

int deal_one_line(int seq)
{
	int ip_packet_len = 0;
	int ip_head_len = 0;
	int tmp = 0;
	char ch = 0;
	int i = 0;
	int src_ip[IP_LEN] = {0};
	int dst_ip[IP_LEN] = {0};
	int src_port = 0;
	int dst_port = 0;

	for (i = 0; i < 2; i++) {
		scanf("%c", &ch);
	}
	ip_head_len = 4 * (ch - '0');
	scanf("%x", &tmp);
	scanf("%x", &ip_packet_len);
	scanf("%x", &tmp);
	ip_packet_len = ip_packet_len * 256 + tmp;
	for (i = 0; i < 8; i++) {
		scanf("%x", &tmp);
	}
	for (i = 0; i < 4; i++) {
		scanf("%x", &tmp);
		src_ip[i] = tmp;
	}
	for (i = 0; i < 4; i++) {
		scanf("%x", &tmp);
		dst_ip[i] = tmp;	
	}
	for (i = 20; i < ip_head_len; i++) {
		scanf("%x", &tmp);
	}
	scanf("%x", &src_port);
	scanf("%x", &tmp);
	src_port = src_port * 256 + tmp;
	scanf("%x", &dst_port);
	scanf("%x", &tmp);
	dst_port = dst_port * 256 + tmp;

	scanf("%c", &ch);
	while (ch != '\n') {
		scanf("%c", &ch);
	}

	printf("Case #%d\n", seq);
	printf("Total length = %d bytes\n", ip_packet_len);
	printf("Source = %d.%d.%d.%d\n", src_ip[0], src_ip[1], src_ip[2], src_ip[3]);
	printf("Destination = %d.%d.%d.%d\n", dst_ip[0], dst_ip[1], dst_ip[2], dst_ip[3]);
	printf("Source Port = %d\n", src_port);
	printf("Destination Port = %d\n\n", dst_port);

	return 1;
}
int main(void)
{
	int flag = 1;
	FILE *fp = NULL;
	int item_count = 0;
	int i = 0;
	char ch = 0;

	fp = freopen("input.txt", "r", stdin);
	scanf("%d", &item_count);
	scanf("%c", &ch);
	for (i = 0; i < item_count; i++) {
		flag = deal_one_line(i + 1);
	}
	
	if (fp != stdin) fclose(fp);
}

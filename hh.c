/*
 * C源程序名: hh.c
 * 作者: mike2718
 * 作用: 国内业余无线电台呼号分区信息查询C程序
 * 用法（在Arch Linux下使用pcc编译）：
 *   $ pcc -g -std=c99 -O0 hh.c -o hh && ./hh
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void func(char *temp) {
	char *name;
	name = strtok(temp, ":");

	// Convert to upper case
	char *s = name;
	while (*s) {
		*s = toupper((unsigned char) *s);
		s++;
	}

}

int main(void) {
	printf("\n查询中国大陆业余无线电台呼号相关信息的程序\n\n");
	printf("  目前功能有限，不能查询港澳台的呼号\n");
	printf("  可能不准，不代表官方观点\n");
	printf("  输入格式（例子）：BG7XTQ\n");
	printf("------------------------------------------\n\n");

	char h[11]; /* 最长10 */
	int check;
	do {
		printf("输入要查询的呼号：");
		check = scanf("%10s", h);
		while (getchar()!='\n');
		/*printf("%s\n", h);*/
	} while (check != 1);
	func(h);  /* 转换为大写 */

	/* 结尾非字母 */

	/* 第二位电台种类 非字母 */
	if (h[0] != 'B' || h[1] < 'A' || h[1] > 'Z' || h[2] < '0' || h[2] > '9' || strlen(h) > 10 || strlen(h) < 4) {
		printf("\n  输入错误！呼号格式不符合法律规定\n\n");
		return 0;
	}
	printf("\n该呼号信息：\n\n");
	if ((h[1] > 'K' && h[1] < 'R') || (h[1] > 'T' && h[1] < 'Y')) {   /* LMNOPQ || UVWX */
		printf("  国家无线电管理机构留作备用\n");
	} else {
		if (h[1] == 'J') printf("  业余信标台或空间业余无线电台\n");
		if (h[1] == 'R') printf("  业余中继台\n");
	}
	switch (h[2]) {
	case '1':
		printf("  第1区：北京\n");
		break;
	case '2':
		printf("  第2区：黑龙江、吉林、辽宁\n");
		break;
	case '3':
		printf("  第3区：天津、内蒙古、河北、山西\n");
		break;
	case '4':
		printf("  第4区：上海、山东、江苏\n");
		break;
	case '5':
		printf("  第5区：浙江、江西、福建\n");
		break;
	case '6':
		printf("  第6区：安徽、河南、湖北\n");
		break;
	case '7':
		if ((strlen(h) == 4) && (h[1] == 'S') && (h[3] == 'H')) {   /* BS7H */
			printf("  黄岩岛业余无线电台\n");
			break;
		}
		printf("  第7区：湖南、广东、广西、海南\n");
		break;
	case '8':
		printf("  第8区：四川、重庆、贵州、云南\n");
		break;
	case '9':
		printf("  第9区：陕西、甘肃、宁夏、青海\n");
		break;
	case '0':
		printf("  第0区：新疆、西藏\n");
		break;
	}
	printf("\n");
	return 0;
}


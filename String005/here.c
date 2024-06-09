#include <stdio.h>
#include <string.h>
//7.strncpy(s1,s2,n)函数把s2中的n个字符拷贝至s1中，截断s2，或者有必要的话再末尾添加空字符。如果s2的长度是n或者多于n，目标字符串不能
//以空字符结尾。该函数返回s1。自己编写这样的函数，名为mystrncpy（）。在一个完整的程序中测试该函数，使用一个循环给函数提供输入值
#define max 30
char* mystrncpy(char* s1,  char* s2, int n);
int getnum(int x);
char* s_gets(char* st, int n);
int main()
{
	int n;
	int x = 1;
	printf("请输入你想添加的字符数：\n");
	n = getnum(&n);
	char arr1[5][max];
	char arr2[max];
	char* s3[5];
	int panbie = 0;
	int w = 0;
	//printf("请输入目标字符串:\n");
	//s_gets(arr1, max);
//	printf("请输入想要添加的字符串：\n");
	//s_gets(arr2, max);
	//printf("接下来你想添加的字符串的目标字符数下降复制在目标字符串中：\n");
	while (x <= 5)
	{
		printf("请输入想要添加的字符串：\n");
		s_gets(arr2, max);
		printf("接下来你想添加的字符串的目标字符数下降复制在目标字符串中：\n");
		s3[w] = mystrncpy(arr1[w], arr2, n);
		printf("还想输入吗？：继续输入1否则输入0；\n");
			panbie = getnum(&panbie);
			if (panbie == 0)
				break;
			w++;
			x++;
			//s3++;
	}
	printf("结果为：\n");
	for (n = 0;n < x;n++)
	{
		printf("%s ", s3[n]);
		//s3++;
	}
	return 0;
}
char* mystrncpy(char* s1, char* s2, int n)
{
	if (strlen(s2)<= n)
		s2[(sizeof(s2))] = '\0';
	else
	{
		printf("输入超出，只读%d个\n", n);
		s2[n] = '\0';
	}
	strncpy(s1, s2, n+1);
	return s1;
}
int getnum(int x)
{
	scanf("%d", &x);
	while (getchar() != '\n')
		continue;
	return x;
}
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n'&&st[i]!='\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
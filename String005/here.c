#include <stdio.h>
#include <string.h>
//7.strncpy(s1,s2,n)������s2�е�n���ַ�������s1�У��ض�s2�������б�Ҫ�Ļ���ĩβ��ӿ��ַ������s2�ĳ�����n���߶���n��Ŀ���ַ�������
//�Կ��ַ���β���ú�������s1���Լ���д�����ĺ�������Ϊmystrncpy��������һ�������ĳ����в��Ըú�����ʹ��һ��ѭ���������ṩ����ֵ
#define max 30
char* mystrncpy(char* s1,  char* s2, int n);
int getnum(int x);
char* s_gets(char* st, int n);
int main()
{
	int n;
	int x = 1;
	printf("������������ӵ��ַ�����\n");
	n = getnum(&n);
	char arr1[5][max];
	char arr2[max];
	char* s3[5];
	int panbie = 0;
	int w = 0;
	//printf("������Ŀ���ַ���:\n");
	//s_gets(arr1, max);
//	printf("��������Ҫ��ӵ��ַ�����\n");
	//s_gets(arr2, max);
	//printf("������������ӵ��ַ�����Ŀ���ַ����½�������Ŀ���ַ����У�\n");
	while (x <= 5)
	{
		printf("��������Ҫ��ӵ��ַ�����\n");
		s_gets(arr2, max);
		printf("������������ӵ��ַ�����Ŀ���ַ����½�������Ŀ���ַ����У�\n");
		s3[w] = mystrncpy(arr1[w], arr2, n);
		printf("���������𣿣���������1��������0��\n");
			panbie = getnum(&panbie);
			if (panbie == 0)
				break;
			w++;
			x++;
			//s3++;
	}
	printf("���Ϊ��\n");
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
		printf("���볬����ֻ��%d��\n", n);
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
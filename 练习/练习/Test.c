#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define max 10
typedef float Elementtype;

Elementtype Sum(Elementtype s[], int n)
{
	int i = 0;
	Elementtype sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += s[i];
		s[i] = i;
	}
	//printf("����Ԫ�ص�ƽ��ֵΪ:%f\n", sum / n);
	return sum / n;
}

int main()
{
	int n, i;
	Elementtype s[max] = {0};
	printf("����������Ԫ�ظ���:\n");
	scanf("%d", &n);

	if (n <= 10)
	{
		printf("����������ĸ���Ԫ��:");
		for (i = 0; i < n; i++)
		{
			scanf("%f", &s[i]);
			//s[i] = i;
		}
		//	Sum(s, n);
		printf("�����:%f", Sum(s, n));
	}
	else
		printf("�����������Ԫ�ظ������Ϲ淶!\n");
}



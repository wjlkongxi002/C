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
	//printf("数组元素的平均值为:%f\n", sum / n);
	return sum / n;
}

int main()
{
	int n, i;
	Elementtype s[max] = {0};
	printf("请输入数组元素个数:\n");
	scanf("%d", &n);

	if (n <= 10)
	{
		printf("请输入数组的各个元素:");
		for (i = 0; i < n; i++)
		{
			scanf("%f", &s[i]);
			//s[i] = i;
		}
		//	Sum(s, n);
		printf("结果是:%f", Sum(s, n));
	}
	else
		printf("所输入的数组元素个数不合规范!\n");
}



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define max 10
typedef float Elementtype;


int main() 
{
	int n, i;
	Elementtype s[max];
	printf("请输入数组元素个数:\n");
	scanf("%d", &n);
	if (n <= 10)
	{
		printf("请输入数组的各个元素:");

		for (i = 0; i < n; i++)
		{
			scanf("%f", &s[i]);
		}
		int Sum(Elementtype s[], int n);
	}
	//int  Sum(Elementtype s[], int n);
	else
	{
		printf("所输入的数组元素个数不合规范!\n");
	}
	return 0;

}

 Sum(Elementtype s[], int n)
{
	int i;
	float sum = 0;
	for (i = 0; i<n; i++) 
	{
		sum = sum + s[i];
	}
	printf("数组元素的平均值为:%f\n", sum / n);
	return 0;
}
/*
#include <stdio.h>
//int main()
//{
	//	int i = 0, a = 0;
	//	while (i<20)
	//	{
	//		for (;;)
	//		{
	//			if ((i % 10) == 0) break;
	//			else i--;
	//		} 
	//			i+= 11; a += i;
	//	}
	//	printf("%d\n", a);
	//	return 0;
	//} 
	/*
	#define N 2
	#define M N+1
	#define NUM (M+1)*M/2
	int main()
	{
	printf("%d\n", NUM);
	}
	*/
	/*int a = 1;
	int func(int a);
	{
		int b;
		switch (a)
		{
		case 1: b = 30;
		case 2: b = 20;
		case 3: b = 16;
		default: b = 0;
		}
		return b;
	}*/
	/*int m = 'ab';
	int n = '\101';
	int o = "A";
	int p = PI;

	printf("delete file (are you really sure??): ");*/
/*
			char *p = "abcdefgh", *r;
			long *q;
			q = (long*)p;
			q++;
			r = (char*)q;
			printf("%s\n", r);
		*/

	
			/*char str[] = "ABCD", *p = str;
			printf("%d\n", *(p + 4));
			return 0;*/
	/*int f(int n);
	int n=4;
	{
		if (n)
			return f(n - 1) + n;
		else
			return n;
	}*/
	//printf("\a\a\a\a\a");
//}
	//int Add(int a, int b)
	//{
	//	int c = 0;
	//	c = a + b;
	//	return c;
	//}
	//int main()
	//{
	//	//Add(10,20);
	//	printf("%d", Add(10, 20));
	//}

	//
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int main()
{
	int a[5] = { 1, 3, 5, 7, 9 };
	int  *p = (int *)(&a + 1);
	printf("%d, %d", *(a + 1), *(p - 1));
	return 0;
}

#if 0
void GetMemory(char *p)
{
	p = (char *)malloc(100);
}
void Test(void)
{
	char *str = NULL;
	GetMemory(str);
	strcpy(str, "hello world");//ÄÚ´æÐ¹Â©
	printf(str);
}

int main()
{
	Test();
	return 0;
}

#endif
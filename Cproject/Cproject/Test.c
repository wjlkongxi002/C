#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N_VALUES 5

int main()
{
	char a = 0, ch;
	while ((ch = getchar()) != '\n')
	{
		if (a % 2 != 0 && (ch >= 'a'&&ch <= 'z'))
			ch = ch - 'a' + 'A';
		a++;
		putchar(ch);
	}
	printf("\n");
}
/*
//��������
int main()
{
	int N = 0;
	int a[] = {0};
	int *p = a;
	int j = a[1];
	int sum = 0;
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}
	while (*(p+1) = (j++))
	{
		sum += *p;
	}
	printf("%d", sum);
	return 0;
}
/*
int main()
{
	char p1[15] = "abcd", *p2 = "ABCD", str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
	printf("%s", str);
	
	/*
	int a; float b, c;
	scanf("%2d%3f%4f", &a, &b, &c);
	printf("\na=%d,b=%d,c=%f\n", a, b, c);
	int x = 1;
	do
	{
		printf("%2d\n", x++);

	} while (x--);
	return 0;

}

/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr; //ָ����������Ԫ�صĵ�ַ
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i<sz; i++)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}


/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int *p = arr; //ָ����������Ԫ�صĵ�ַ
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i<sz; i++)
	{
		printf("&arr[%d] = %p <====> p+%d = %p\n", i, &arr[i], i, p + i);
	}
	return 0;
}

/*
int my_strlen(char *s)
{
	char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}
int main()
{
	float values[N_VALUES];
	float *vp;
	//ָ��+-������ָ��Ĺ�ϵ����
	for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0;
	}
	my_strlen("abcdefg");;
	printf("%p\n", values[0]);
	printf("%p\n", values[N_VALUES]);
	printf("%p\n", vp);
}
/*
int main()
{
	printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));
	printf("%d\n", sizeof(long double));
	return 0;
}

/*int main()
{
	int n = 10;
	char *pc = (char*)&n;
	int *pi = &n;
	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc + 1);
	printf("%p\n", pi);
	printf("%p\n", pi + 1);
	return 0;
}
*/
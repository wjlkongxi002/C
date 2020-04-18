#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdbool.h>
#define N_VALUES 5


void main()
{
	int a, b；
	scanf("%d,%d", &a, &b)；
	if (a>b) a = b;
	        b = a;
	else a++；b++；
		printf("%d,%d", a, b);
}
/*
int main()
{
	int a[] = { 2, 4, 6, 8 }, *p = a, i;
	for (i = 0; i<4; i++)
		a[i] = *p++;
	printf("%d\n", a[2]);
	return 0;
}
/*
void main()
{
	int a = 1; int b = 2;
	for (; a<8; a++)
	{
		b += a; a += 2;
	}
	printf("%d，%d\n", a, b);
}

/*
int main()
{
	int i = 0;
	int sum = 0;
	int *p;
	scanf("%d", &i);
	p = &i;
	sum = *p + 15;
	printf("%d  %d\n", i, sum);
	return 0;
}




/*
bool fun(int n)
{
	int sum = 0;
	for (int i = 1; n < sum; i = i + 2)
		sum = sum + i;
	return (n = sum);
}

void main()
{
	fun(484);

}


/*
int main()
{
	char a[] = "wangjia";
	printf("%d", sizeof(a));
	printf("%d", strlen(a));
}

/*
int main()
{
	int i, a[10];
	for (i = 9; i >= 0; i--)
	{
		a[i] = 10 - i;
	}
	printf("%d%d%d", a[2], a[5], a[8]);
	return 0;
}


/*
int main() {
	int i, j;
	int a[5][5] = {0};
	int m, n;

	printf("请输入二维数组的行(m)和列(n):");
	scanf("%d %d", &m, &n);

	printf("下面请输入%d行%d列二维数组的各个元素:", m, n);
	for (i = 0; i < m; i++) 
	{
		for (j = 0; j <m*n; j++) 
		{
			scanf("%d", &a[m*n]);
		}
	}

	printf("下面输出二维数组:\n");
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++) 
		{
			printf("%4d", a[m][n]);
			if ((j + 1) % n == 0) 
			{
				printf("\n");
			}
		}
	}

	return 0;
}

/*
int main()
{
	int i = 10;
	int j = 1;
	const int *p1;
	int const *p2 = &i;
	p2 = &j;
	int *const p3 = &i;
	*p3 = 20;
	//*p2 = 30;
	//p3 = &j;
	return 0;
}

/*
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
//连续最大和
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
	int *p = arr; //指针存放数组首元素的地址
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
	int *p = arr; //指针存放数组首元素的地址
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
	//指针+-整数；指针的关系运算
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
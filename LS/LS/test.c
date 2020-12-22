#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

void Dijkstra(int n, int v, int distance[], int previous[], int **G)
//distance Ϊ��㵽��������̾���
// previousΪÿ���ڵ������ڵ�
{
	int * sign = (int *)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)//��ʼ��
	{
		distance[i] = G[v][i];//��i����̾��������ʼ�� ���ﲻ�˵Ľڵ�ΪINT_MAX
		if (i == v)
		{
			sign[i] = 1;

		}
		else
		{
			sign[i] = 0;
		}

		if (G[v][i] == INT_MAX)
		{
			previous[i] = -1;
		}
		else
		{
			previous[i] = v;//��ʼ�ڵ������ڵ���������
		}

	}

	for (int i = 0; i < n - 1; i++)//n���ڵ㣬n-1��
	{
		int temp = INT_MAX;
		int min_v = INT_MAX;
		for (int j = 0; j < n; j++)
		{
			if ((!sign[j]) && distance[j] < temp)
				//ѡ��һ��δ������Ҿ����ʼ�ڵ���̵Ľڵ�
			{
				min_v = j;
				temp = distance[j];
			}
		}
		sign[min_v] = 1;
		for (int j = 0; j < n; j++)
		{
			if ((!sign[j]) && G[min_v][j] < INT_MAX)
				//����δ�����Ҷ���ɴ�
			{
				int newdist = distance[min_v] + G[min_v][j];
				//��̽ڵ� + ����ڵ��·�� ������·�����п�������̵�·��

				if (newdist < distance[j])
				{
					//����Դ��ͨ��j��ľ���
					distance[j] = newdist;
					previous[j] = min_v;//������̽ڵ� min_v
				}
			}

		}
	}


}
void showPath(int start, int end, int n, int previous[])

{
	int *way = (int*)malloc(sizeof(int)*n);//·������
	int previous_v = end;
	int count = 0;
	while (1)
	{
		way[count] = previous_v;
		count++;
		previous_v = previous[previous_v];
		if (previous_v == start)
		{
			way[count] = previous_v;
			count++;
			break;
		}

	}
	printf("The start : %d The end %d\n", start, end);
	for (int i = count - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			printf("%d", way[i]);

		}
		else {
			printf("%d->", way[i]);
		}
	}
	printf("\n");
}
int ** generateGraph(int n)
{
	int ** Graph = (int**)malloc(sizeof(int *)*n);
	for (int i = 0; i < n; i++)
	{
		Graph[i] = (int*)malloc(sizeof(int)*n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				Graph[i][j] = 0;
			}
			else
			{
				Graph[i][j] = INT_MAX;
			}
		}
	}
	Graph[1][0] = 2;
	Graph[2][0] = 1;
	Graph[3][0] = 4;
	Graph[4][0] = 0;
	Graph[5][0] = 1;

	Graph[2][1] = 7;
	Graph[3][1] = 0;
	Graph[4][1] = 5;
	Graph[5][1] = 0;
	Graph[3][2] = 3;
	Graph[4][2] = 0;
	Graph[5][2] = 0;

	Graph[4][3] = 2;
	Graph[5][3] = 0;
	Graph[5][4] = 3;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			Graph[i][j] = Graph[j][i];
		}
	}

	return Graph;
}


int main()
{
	int ** Graph = generateGraph(6);
	int * distance = (int*)malloc(sizeof(int)* 6);
	int * previous = (int*)malloc(sizeof(int)* 6);
	Dijkstra(6, 2, distance, previous, Graph);
	for (int i = 0; i < 6; i++)
	{
		showPath(2, i, 6, previous);
	}
	system("pause");
	return 0;
}


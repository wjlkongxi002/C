#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#define ROUTER_OF_NUMBER 100    //网络中路由的最大数目
#define MaxExp 10000 //假设为此路由费用为无穷大

int RouterNum;                  //网络中路由的个数

//定义一个路由的信息
struct Router
{
	int exp;               //每条链路的费用
	int neighbor;           //相邻节点的信息,若两节点相邻设置为1，否则为0
	int nexthop;           //接收节点的上一跳的地址
};


Router routertable[ROUTER_OF_NUMBER][ROUTER_OF_NUMBER];  //路由表信息

void InitialNodeState(); //初始化节点分布的情况
void PrintNetwork(); //网络生成图
void ExchangeInformation();             //相邻节点间交换链路信息
void DV(int send, int recv);               //DV算法
void DisplayRouter(int src, int dst);        //显示源节点到目的节点路径

int main()
{
	int src, dst;
	InitialNodeState();

	printf("网络的费用情况\n");
	PrintNetwork();

	// 因为该网络会不停的更新网络的信息，所以这里的循环次数可以根据网络的拓扑而定，一般设有几个节点就循环多少次
	for (int i = 0; i < RouterNum; i++)
	{
		ExchangeInformation();
	}

	printf("交换完信息网络的最短路由费用情况\n");
	PrintNetwork();             //显示寻找完最短路由的网络图

	printf("源节点：");
	scanf("%d", &src);
	printf("目的节点：");
	scanf("%d", &dst);

	printf("\n");
	printf("源节点到目的节点的总费用：%d\n", routertable[src][dst].exp);
	printf("\n");
	DisplayRouter(src, dst);
}

void InitialNodeState()
{

	printf("网络中路由的数目：");
	scanf("%d", &RouterNum);

	printf("网络中路由的连接情况\n");

	for (int i = 0; i < RouterNum - 1; i++)
	{
		for (int j = i + 1; j< RouterNum; j++)
		{
			printf("从第%d个节点到第%d个节点的费用:", i, j);
			scanf("%d", &routertable[i][j].exp);
			routertable[j][i].exp = routertable[i][j].exp;
			//假设来回的路由的费用相同
		}
	}

	//通过路由的费用来确认他们之间的相邻关系

	for (int m = 0; m < RouterNum; m++)
	{
		for (int n = 0; n < RouterNum; n++)
		{
			if (m == n)
			{
				routertable[m][n].exp = -1;
				routertable[m][n].neighbor = 0;
				routertable[m][n].nexthop = -1;
			}
			else
			{
				if (routertable[m][n].exp != -1)             //若费用为-1说明两节点无连接，不为相邻的节点
				{
					routertable[m][n].neighbor = 1;       //说明两个节点是相邻的
					routertable[m][n].nexthop = -1;

					//初始化时，无上一跳节点
				}
				else
				{
					routertable[m][n].neighbor = 0;
					routertable[m][n].nexthop = -1;
				}

			}

		}
	}
}

void PrintNetwork()    //用网格的形式打印出网络中各节点的连接关系
{

	printf("\n");
	printf("\n");

	for (int i = 0; i <= RouterNum; i++)
	{
		for (int j = 0; j <= RouterNum; j++)
		{
			if (i == 0)
			{
				if (j == 0)
				{
					printf("     ");
				}
				else
				{
					printf("  %d  ", j - 1);
				}
			}
			else
			{
				if (j == 0)
				{
					printf("  %d  ", i - 1);
				}
				else
				{
					if (routertable[i - 1][j - 1].exp != -1)
					{
						printf("  %d  ", routertable[i - 1][j - 1].exp);
					}
					else
					{
						printf("  *  ");
					}
				}
			}
		}
		printf("\n");
		printf("\n");
	}
}

void ExchangeInformation()
{
	for (int m = 0; m < RouterNum; m++)
	{
		for (int n = 0; n < RouterNum; n++)
		{
			if (routertable[m][n].neighbor == 1)  //相邻节点之间交换链路信息
			{
				DV(m, n); //通过相邻节点的信息更新发送节点的距离向量
			}
		}
	}
}

void DV(int send, int recv)  //接收节点通过接收到的信息来调整自己的距离向量
{
	for (int i = 0; i < RouterNum; i++)
	{
		if (routertable[send][i].exp >  0)   //发送节点到第i节点存在路径
		{
			if (routertable[recv][i].exp >  0)  //接收的节点到第i节点存在路径
			{
				//重新计算距离向量
				if (routertable[recv][i].exp > routertable[recv][send].exp + routertable[send][i].exp)
				{
					//如果接收节点到其它节点更近，更新其信息列表，把到i节点的最短路径的下一条设置为发送节点
					routertable[recv][i].exp = routertable[recv][send].exp + routertable[send][i].exp;
					routertable[recv][i].nexthop = send;
				}
				//否则不做任何的改动
			}
			else
			{
				if (recv != i)  //相同节点不做任何处理
				{
					//接收的节点到第i节点的路径不存在，把接收节点到i路径添加到接收节点到i节点最短路径
					routertable[recv][i].exp = routertable[recv][send].exp + routertable[send][i].exp;
					routertable[recv][i].nexthop = send;
				}
			}
		}
		//若发送节点到第i节点路径不存在，仍不做任何的改动
	}
}

void DisplayRouter(int src, int dst)
{
	if (src < 0 || src >= RouterNum || dst < 0 || dst >= RouterNum)
	{
		printf("网络中没有您要找的路由\n");
	}

	int count_router[ROUTER_OF_NUMBER];      //经过路由统计数
	count_router[0] = src;
	int flag = count_router[0];       //循环控制标志


	printf("源节点到目的节点所经过的路径:");
	printf("%d->", count_router[0]);

	int k = 1;
	while (flag != -1)
	{
		count_router[k] = routertable[src][dst].nexthop;
		flag = count_router[k];
		src = flag;
		if (flag != -1)
		{
			printf("%d->", count_router[k]);
		}
		k++;
	}

	printf("%d\n", dst);
}
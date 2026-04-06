#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	int i;
	int a;								//普通输入
	int ab;								//大小函数中间值
	int f;								//判断过渡
	int fin;							//结束判断
	int fine;							//结束过渡
	int pw[4];							//四位密码
	int pwa[4];							//密码输入
	int p[100];							//预备数组
ICE:									//重开游戏标记*
	srand((unsigned)time(NULL));		//定义rand函数种子
	for (i = 0; i < 100; i++)			//配置预备数组（0-99）
	{
		p[i] = i;
	}
	for (i = 99; i > 0; i--)			//洗牌乱序
	{
		int l1 = rand() % (i + 1);
		int l2 = p[i];
		p[i] = p[l1];
		p[l1] = l2;
	}
	printf("游戏开发：凌柃|代码语言：C语言|版本：1.4\n");
	printf("游戏代码：101——直接输出密码|102——密码输入重置\n");
	printf("游戏代码：103——直接重开游戏|104——直接结束游戏\n");
	printf("游戏代码：105——清除记录并重开|106——启用辅助判断器\n");
	printf("请注意：密码有四个数字，游戏代码在准备完毕后才生效！\n");
	printf("请注意游戏过程中不要输入包括小数点在内的除数字之外的任何字符！\n");
	printf("请输入您挑战的最大有效值（范围3——99）：");
	scanf_s("%d", &a);
	while (a < 3) 
	{
		printf("错误，请注意最小有效值为3！\n");
		scanf_s("%d", &a);
	}
	i = 0;								//修正i值
	f = 0;
	ab = 0;
	do
	{
		if (p[i] <= a)
		{
			pw[f] = p[i];
			f++;
		}
		i++;
	} while (f < 4);
	printf("游戏准备完毕\n");
RE:										//重新输入标记*
	fin = 0;
	do									//*****主 运 算 区*****
	{
		for (i = 0; i < 4; i++)
		{
			fine = 0;
			printf("请输入第%d位密码（输入102可重置您的输入）：\n", i + 1);
			scanf_s("%d", &pwa[i]);
			switch (pwa[i])					//游戏代码,不包含代码105
			{
			case 101:
				printf("密码为：%d-%d-%d-%d\n", pw[0], pw[1], pw[2], pw[3]);
				goto RE;
			case 102:
				printf("执行输入重置！\n");
				goto RE;
			case 103:
				printf("执行直接重开游戏！\n");
				goto ICE;
			case 104:
				printf("执行直接结束游戏！\n");
				goto END;
			case 106:
				printf("启用辅助判断器！\n");
				ab = 1;
				goto RE;
			default:
				break;
			}
		}
		printf("您的输入结果：\n%d-%d-%d-%d\n", pwa[0], pwa[1], pwa[2], pwa[3]);
		for (i = 0; i < 4; i++)				//密码判断
		{
			if (pwa[i] == pw[0])
			{
				if (i == 0)
				{
					printf("V");
					fine++;
					//printf("%d", fine);
				}
				else
				{
					printf("Y");
				}
			}
			if (pwa[i] == pw[1])
			{
				if (i == 1)
				{
					printf("V");
					fine++;
					//printf("%d", fine);
				}
				else
				{
					printf("Y");
				}
			}
			if (pwa[i] == pw[2])
			{
				if (i == 2)
				{
					printf("V");
					fine++;
					//printf("%d", fine);
				}
				else
				{
					printf("Y");
				}
			}
			if (pwa[i] == pw[3])
			{
				if (i == 3)
				{
					printf("V");
					fine++;
					//printf("%d", fine);
				}
				else
				{
					printf("Y");
				}
			}
			if (pwa[i] != pw[0] && pwa[i] != pw[1] && pwa[i] != pw[2] && pwa[i] != pw[3])
			{
				printf("X");
			}
		}
		//printf("%d", fine);
		if (fine == 4)
		{
			fine = 0;
			fin++;
		}
		else
		{
			printf("\n解释：V表示该位置数字完全正确；X表示密码中不包含该数字；\n");
			printf("Y表示密码中包含该数字但位置不正确\n");
			if (ab == 1)						//辅助判断器
			{
				for (int i = 0; i < 4; i++)
				{
					if (pwa[i] == pw[0] || pwa[i] == pw[1] || pwa[i] == pw[2] || pwa[i] == pw[3])
					{
						printf("=");
					}
					else
					{
						if (pwa[i] > pw[i])
						{
							printf(">");
						}
						else
						{
							printf("<");
						}
					}
				}
				printf("（辅助判断结果）\n辅助判断说明：=表示该位置与密码中的某一个数值相等\n");
				printf(">表示对应位置的值偏大，<表示对应位置的值偏小\n");
			}
		}
	} while (fin == 0);
END:										//游戏结束标记*
	printf("\n游戏结束，输入103重开游戏，输入105清除记录并重开\n");
	scanf_s("%d", &a);
	if (a == 103)
	{
		printf("执行直接重开游戏！\n");
		goto ICE;
	}
	if (a == 105)							//清除控制台
	{
		system("cls");
		printf("\n已重开游戏\n");
		goto ICE;
	}
	return 0;
}

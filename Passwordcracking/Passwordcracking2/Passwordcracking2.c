#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	int a;					//范围最大值
	int ab;					//辅助判断器中间值
	int f;					//判断过渡
	int e;					//模式存储
	int e0;					//模式存储继承中间值
	int a0;					//范围存储继承中间值
	int ha1, ha2;			//困难模式判断过渡
	int c;					//次数记录
	int k = 0;				//确认输入过渡
	int eafk = 0;			//确认继承过渡
	int fin;				//结束判断
	int fine;				//结束过渡
	int eaf = 0;			//继承设置过渡
	int pw[4];				//四位密码
	int pwa[4];				//密码输入
	int p[100];				//预备数组
ICE:									//重开游戏标记*
	srand((unsigned)time(NULL));		//定义rand函数种子
	for (i = 0; i < 100; i++)			//配置预备数组（0-99）
	{
		p[i] = i;
	}
	for (i = 99; i > 0; i--)			//洗牌乱序
	{
		int l1 = rand() % (i + 1);		//任意生成一个随机位置l1
		int l2 = p[i];					//提取位置i的值
		p[i] = p[l1];					//将随机位置l1的值赋值给位置i
		p[l1] = l2;						//将位置i的值赋值给随机位置l1
	}
	printf("游戏开发：凌柃|代码语言：C语言|版本：2.8\n");
	printf("游戏代码：（除105外在游戏设置完毕后有效）\n");
	printf("101——直接输出密码|102——密码输入重置\n");
	printf("103——直接重开游戏|104——直接结束游戏\n");
	printf("105——清除记录并重开|106——启用辅助判断器\n");
	printf("107——停用辅助判断器|108——输出当前难度及范围\n");
	printf("109——直接重开游戏且继承上一局游戏设置\n");
	printf("请注意：密码有四个数字，游戏代码在准备完毕后才生效！\n");
	printf("另外，游戏过程中禁止输入包括小数点在内的除数字之外的任何字符！\n");
	if (eaf == 0)			//如果继承设置过渡为0则进入设置，否则进入继承
	{
		printf("请输入您选择的难度（1简单，2困难）：");
		scanf_s("%d", &e);
		printf("请输入您挑战的最大有效值（范围3——99）：");
		scanf_s("%d", &a);
	}
	else
	{
		e = e0;			//e,a值继承
		a = a0;
		printf("\n您选择了继承上一次的设置->\n");		//输出继承的设置
		printf("游戏难度：");
		if (e == 1)
		{
			printf("简单\n");
		}
		else
		{
			printf("困难\n");
		}
		printf("有效值范围：0——%d\n", a);
		printf("输入1确认继承，输入2重新设置：");		//继承确认
		eafk = 0;			//清除中间值
		scanf_s("%d", &eafk);
		switch (eafk)		//中间值为1确认继承，为2则不继承，进行重新设置
		{
		case 1:
			eaf = 0;
			eafk = 0;
			break;
		case 2:
			eaf = 0;
			eafk = 0;
			printf("请输入您选择的难度（1简单，2困难）：");
			scanf_s("%d", &e);
			printf("请输入您挑战的最大有效值（范围3——99）：");
			scanf_s("%d", &a);
		default:
			break;
		}
	}
	e0 = e;				//存储设置
	a0 = a;
	while (a < 3)		//范围最小判断
	{
		printf("错误，请注意最小有效值为3！\n");
		scanf_s("%d", &a);
	}
	i = 0;				//修正重要值
	f = 0;
	ab = 0;
	c = 0;
	k = 0;
	do			//提取密码
	{
		if (p[i] <= a)		//依次从准备好的数组中提取密码，如果符合条件则进入密码数组，否则丢弃
		{
			pw[f] = p[i];
			f++;
		}
		i++;
	} while (f < 4);
	printf("游戏准备完毕\n");
RE:						//重新输入标记*
	fin = 0;
	do					//*****<主 运 算 区>*****
	{
		for (i = 0; i < 4; i++)				//依次存入四个数字
		{
			fine = 0;
			printf("请输入第%d位密码（输入102可重置您的输入）：\n", i + 1);
			scanf_s("%d", &pwa[i]);
			switch (pwa[i])					//游戏代码,不包含代码105
			{
			case 101:			//代码101，可以直接输出正确密码
				printf("密码为：%d-%d-%d-%d\n", pw[0], pw[1], pw[2], pw[3]);
				goto RE;
			case 102:			//代码102，可以重新输入密码
				printf("执行输入重置！\n");
				goto RE;
			case 103:			//代码103，可以直接重开游戏
				printf("即将执行直接重开游戏···\n");
				printf("请问是否要继承该局游戏的设置？\n（输入1确认继承，输入0放弃继承）\n");
				int yu = 5;		//中间值清除
				scanf_s("%d", &yu);
				if (yu == 1)	//继承判断
				{
					eaf = 1;
					yu = 5;
					printf("执行重开游戏且继承设置！\n");
					goto ICE;
				}
				else
				{
					eaf = 0;
					yu = 5;
					printf("执行直接重开游戏！\n");
					goto ICE;
				}
			case 104:			//代码104，可以直接结束游戏
				printf("执行直接结束游戏！\n");
				goto END;
			case 106:			//代码106，可以启用辅助判断器
				printf("启用辅助判断器！\n");
				if (e == 2)		//提示信息，告知玩家启用辅助判断器可能带来的后果
				{
					printf("请注意：困难难度启用辅助判断器将会破坏困难难度规则！\n");
					printf("输入107代码可关闭辅助判断器\n");
				}
				ab = 1;
				goto RE;
			case 107:			//代码107，可以取消启用辅助判断器
				if (e == 2) 
				{
					printf("执行停用辅助判断器！\n");
					ab = 0;
				}
				goto RE;
			case 108:			//代码108，可以输出当前游戏设置
				printf("当前游戏难度：");
				if (e == 1) 
				{
					printf("简单\n");
				}
				else
				{
					printf("困难\n");
				}
				printf("当前有效值范围：0——%d\n", a);
				goto RE;
			case 109:			//代码109，可以直接重开游戏而且直接选择继承
				printf("执行直接重开游戏且继承上一局游戏设置\n");
				eaf = 1;
				goto ICE;
			default:
				break;
			}
		}
		printf("请确认您的输入（输入1确认结果，输入2重新输入）\n%d-%d-%d-%d\n", pwa[0], pwa[1], pwa[2], pwa[3]);
		k = 0;
		scanf_s("%d", &k);
		switch (k)		//输出结果确认，避免因失误输错数字浪费次数
		{
		case 1:
			k = 0;
			break;
		case 2:
			k = 0;
			goto RE;
		default:
			break;
		}
		c++;			//当确认输入的结果后增加一次次数，然后进行密码判断
		printf("您的输入结果：\n%d-%d-%d-%d\n", pwa[0], pwa[1], pwa[2], pwa[3]);
		if (e == 1)						//简单难度
		{
			for (i = 0; i < 4; i++)		//密码判断
			{
				if (pwa[i] == pw[0])	//如果值与一号位相同，判断位置是否也相同
				{
					if (i == 0)			//位置也相同则输出“V”
					{
						printf("V");
						fine++;
					}
					else				//位置不同则输出“Y”
					{
						printf("Y");
					}
				}
				if (pwa[i] == pw[1])	//同上
				{
					if (i == 1)
					{
						printf("V");
						fine++;
					}
					else
					{
						printf("Y");
					}
				}
				if (pwa[i] == pw[2])	//同上
				{
					if (i == 2)
					{
						printf("V");
						fine++;
					}
					else
					{
						printf("Y");
					}
				}
				if (pwa[i] == pw[3])	//同上
				{
					if (i == 3)
					{
						printf("V");
						fine++;
					}
					else
					{
						printf("Y");
					}
				}
				if (pwa[i] != pw[0] && pwa[i] != pw[1] && pwa[i] != pw[2] && pwa[i] != pw[3])
				{
					printf("X");		//如果值与正确密码中的任何一个都对不上，输出“X”
				}
			}
		}
		else		//困难难度
		{
			ha1 = 0;
			ha2 = 0;
			for (i = 0; i < 4; i++)
			{
				if (pwa[i] == pw[i])	//首先判断是否存在完全正确的情况，有则ha2的值+1
				{
					ha2++;
				}
				else					//其次判断是否存在值相等的情况，有则ha1的值+1
				{
					if (pwa[i] == pw[0] || pwa[i] == pw[1] || pwa[i] == pw[2] || pwa[i] == pw[3])
					{
						ha1++;
					}
				}
			}
			if (ha2 > 0)				//如果存在完全正确的情况，先输出对应数量的“V”
			{
				for (i = 0; i < ha2; i++)
				{
					printf("V");
				}
				for (i = 0; i < ha1; i++)		//如果同时存在值相等的情况，再输出对应数量的“Y”
				{
					printf("Y");
				}
				for (i = 0; i < (4 - ha1 - ha2); i++)		//最后用“X”补全
				{
					printf("X");
				}
				if (ha2 == 4)			//当完全正确的值的数量为4时结束游戏
				{
					fine = 4;
				}
			}
			else				//如果没有完全正确的值，根据存在值相等的情况的数量直接输出对应结果
			{
				switch (ha1)
				{
				case 0:
					printf("XXXX");
					break;
				case 1:
					printf("YXXX");
					break;
				case 2:
					printf("YYXX");
					break;
				case 3:
					printf("YYYX");
					break;
				default:
					printf("YYYY");
					break;
				}
			}
		}
		if (fine == 4)			//判断游戏是否符合结束条件，如不符合再进行后续输出
		{
			fine = 0;
			fin++;
		}
		else
		{
			printf("\n解释：V表示该位置数字完全正确；X表示密码中不包含该数字；\n");
			printf("Y表示密码中包含该数字但位置不正确\n");
			if (ab == 1)		//辅助判断器
			{
				for (int i = 0; i < 4; i++)
				{
					if (pwa[i] == pw[0] || pwa[i] == pw[1] || pwa[i] == pw[2] || pwa[i] == pw[3])
					{
						printf("=");			//首先判断是否存在值相等的情况
					}
					else
					{
						if (pwa[i] > pw[i])		//其次判断偏大偏小
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
END:						//游戏结束标记*
	if (fin == 0)			//如果游戏是直接结束的（fin值仍然为0），不反馈次数
	{
		printf("游戏结束\n");
		printf("正确密码为：%d-%d-%d-%d\n", pw[0], pw[1], pw[2], pw[3]);
	}
	else
	{
		printf("\n游戏结束!正确密码为：%d-%d-%d-%d\n", pw[0], pw[1], pw[2], pw[3]);
		printf("本次破解密码您一共花了%d次\n", c);
	}
	printf("输入103重开游戏，输入105清除记录并重开\n");
	int x = 0;
	int xl = 5;
	scanf_s("%d", &x);
	if (x == 103)
	{
		printf("请问是否要继承该局游戏的设置？\n（输入1确认继承，输入0放弃继承）\n");
		scanf_s("%d", &xl);
		if (xl == 1) 
		{
			eaf = 1;
			xl = 5;
			printf("执行重开游戏且继承设置！\n");
			goto ICE;
		}
		else
		{
			eaf = 0;
			xl = 5;
			printf("执行直接重开游戏！\n");
			goto ICE;
		}
	}
	if (x == 105)								//清除控制台
	{
		system("cls");
		printf("\n执行清除记录并重开游戏！\n");
		goto ICE;
	}
	return 0;
}

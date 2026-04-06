#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a;							//令随机数为a
	int b;							//设置可变数字b
	int max = 100;					//定义最大值且初始值为100
	int min = 1;					//定义最小值且初始值为1
	int k;							//用于结束游戏
	srand((unsigned)time(NULL));	//定义rand函数种子
	a = rand() % 100 + 1;			//随机数最大值为100，最小值为1
	printf("请输入数字：");
	scanf_s("%d", &b);
	do
	{
		if (b > a)
		{
			printf("这个数字比较大·+\n");
			if (max>b)				//记录当前最大值
			{
				max = b;
			}
		}
		else
		{
			printf("这个数字比较小·-\n");
			if (min<b)				//记录当前最小值
			{
				min = b;
			}
		}
		printf("—·—当前最小值为*%d*,最大值为*%d*—·—\n", min, max);	//输出当前有效范围
		b = 0;						//将可变数字归零
		printf("请再次输入：");
		scanf_s("%d", &b);
	} while (b!=a);					//游戏结束判定：当b=a时结束循环，游戏结束
	printf("——BOOM!——\n-游戏结束-\n炸弹是：");
	printf("%d\n", a);
	printf("输入任意字符并回车结束\n");	
	scanf_s("%d", &k);				//保持窗口显示
	return 0;
}

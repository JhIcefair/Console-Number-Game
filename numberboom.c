#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
	int a;					//令随机数为a
	int b;					//设置可变数字b
	int k;					//用于结束游戏
	srand((unsigned)time(NULL));
	a = rand() % 101;		//随机数最大值为100
	printf("请输入数字：");
	scanf_s("%d", &b);
	while (b != a) 
	{
		if (b > a)
		{
			printf("这个数字比较大·+\n请再次输入：");
			b = 0;			//将可变数字归零
			scanf_s("%d", &b);
		}
		else
		{
			printf("这个数字比较小·-\n请再次输入：");
			b = 0;			//将可变数字归零
			scanf_s("%d", &b);
		}
	}
	printf("——BOOM!——\n-游戏结束-\n炸弹是：");
	printf("%d\n", a);
	printf("输入任意字符并回车结束\n");
	scanf_s("%d", &k);
	return 0;
}

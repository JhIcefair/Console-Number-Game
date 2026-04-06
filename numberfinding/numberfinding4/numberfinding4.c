#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int tpf1(int gold, int tp0);				//生成tp1
int tpf2(int gold, int tp0);				//生成tp2
int pathf1(int gold, int path0);			//生成path1
int pathf2(int gold, int path0);			//生成path2
int bmf(int i, int u);						//生成bm[i]
int bmw(int wx, int gold, int tp1, int tp2, int path1, int path2);		//bm[i]值冲突修正
int paf1(int sr1, int min, int max, int gold);							//生成pa1
int paf2(int sr2, int min, int max, int gold);							//生成pa2
int minf(int fd, int gold, int min);		//min判断与储存
int maxf(int fd, int gold, int max);		//max判断与储存

int main()
{
	int gold;				//宝藏，触发后为fin赋值1
	int gl;					//宝藏位置记录
	int fd;					//输入值存储
	int min = 1;			//剩余区域最小值
	int max = 100;			//剩余区域最大值
	int fin = 0;			//结束判定，条件：fin > 0
	int fe;					//结束保持显示
	int path0;				//秘密通道开关范围
	int path1;				//秘密通道开关1
	int path2;				//秘密通道开关2
	int pt = 0;				//秘密通道触发判定
	int pa1 = 0;			//秘密通道1，触发后为fin赋值2
	int pa2 = 0;			//秘密通道2，触发后为fin赋值2
	int tp0;				//位移机关范围
	int tp1;				//位移机关1
	int tp2;				//位移机关2
	int tpe = 0;			//位移机关触发判定
	int bm[20];				//炸弹开关
	int i = 0;				//数组赋值过渡
	int u = 1;				//数组赋值过渡
	int v = 10;				//数组赋值过渡
	int w0 = 0;				//数组值修正过渡
	int w1 = 0;				//数组值修正过渡
	int w2 = 0;				//数组值修正过渡
	int wr = 0;				//数组检测过渡
	int wrl = 0;			//炸弹开关操作过渡
	int rl = 1;				//炸弹开关触发，初始值1，打开1，关闭0
ICE:						//标记位置，用于重开游戏
	printf("创作参考：数字炸弹|游戏名称：数轴探宝\n");
	printf("开发：凌柃|代码语言：C语言|版本：4.0\n");
	printf("指令代码：101——输出位移机关触发点范围值\n");
	printf("指令代码：102——强制结束游戏|103——直接重开游戏\n");
	printf("指令代码：104——清除过往记录并重开|105——输出当前有效值\n");
	u = 1;					//重开后复位主要默认值
	v = 10;
	w0 = 0;
	w1 = 0;
	w2 = 0;
	fin = 0;
	pt = 0;
	pa1 = 0;
	pa2 = 0;
	tpe = 0;
	rl = 1;
	min = 1;
	max = 100;
	srand((unsigned)time(NULL));		//定义rand函数种子
	gold = rand() % 100 + 1;			//在1——100范围内生成宝藏
	tp0 = rand() % 30 + 1;				//生成位移机关范围
	path0 = rand() % 16 + 5;			//生成秘密通道开关范围
	if (path0 == tp0)
	{
		path0 = tp0 + rand() % 5 + 2;
	}
	tp1 = tpf1(gold, tp0);				//生成位移机关
	tp2 = tpf2(gold, tp0);
	path1 = pathf1(gold, path0);		//生成秘密通道开关
	path2 = pathf2(gold, path0);
	for (i = 0; i < 20; i=i+2)			//生成炸弹开关
	{
		bm[i] = bmf(i, u);
		w1 = bm[i];
		w0 = bmw(w1, gold, tp1, tp2, path1, path2);
		if (w0==1)
		{
			bm[i]--;
			w0 = 0;
		}
		w0 = 0;
		bm[i + 1] = bm[i] + rand() % 5 + 1;
		if (bm[i + 1] > v)				//值大小修正
		{
			bm[i + 1] = bm[i + 1] - 10;
		}
		w2 = bm[i + 1];
		w0 = bmw(w2, gold, tp1, tp2, path1, path2);
		if (w0==1)
		{
			bm[i + 1]--;
			w0 = 0;
		}
		w0 = 0;
		u = u + 10;
		v = v + 10;
	}
	printf("说明：\n在数轴1到100的范围内藏着一处与炸弹相连的宝藏\n");
	printf("有两处被关闭的秘密通道直接通往宝藏所在之处\n");
	printf("通道之内安放着同样的炸弹，一旦落入即触发\n");
	printf("想要获得宝藏，需要找到可以关闭炸弹链接的开关\n");
	printf("位于宝藏附近·%d·单位的位移机关能改变宝藏位置\n", tp0);
	do			//*****主 运 算 区*****
	{
		printf("请输入数字(注意避免小数点)：");
		scanf_s("%d", &fd);
		gl = gold;			//记录旧的宝藏位置
		switch (fd)			//游戏代码（除104）
		{
		case 101:			//代码101
			printf("位移机关位于宝藏附近·%d·单位处\n", tp0);
			fd = 0;
			goto FIJH;
		case 102:			//代码102
			printf("游戏已执行强制结束代码\n");
			goto END;
		case 103:			//代码103
			printf("\n已重开游戏\n");
			goto ICE;
		case 105:			//代码105
			printf("--当前有效值如下--\n");
			printf("炸弹开关：（当前状态：%d）\n", rl);
			printf("%d,%d,%d,%d,%d\n", bm[0], bm[1], bm[2], bm[3], bm[4]);
			printf("%d,%d,%d,%d,%d\n", bm[5], bm[6], bm[7], bm[8], bm[9]);
			printf("%d,%d,%d,%d,%d\n", bm[10], bm[11], bm[12], bm[13], bm[14]);
			printf("%d,%d,%d,%d,%d\n", bm[15], bm[16], bm[17], bm[18], bm[19]);
			printf("位移机关：%d，%d\n", tp1, tp2);
			printf("秘密通道开关：%d，%d\n", path1, path2);
			if (pt == 1)
			{
				printf("秘密通道：%d，%d\n", pa1, pa2);
			}
			else
			{
				printf("秘密通道：未开启\n");
			}
			printf("宝藏：%d\n", gold);
			goto FIJH;
		}
		if (fd == gold)				//结束判定1
		{
			fin = 1;
			goto FIJH;
		}
		if (fd==pa1||fd==pa2)		//结束判定2
		{
			fin = 2;
			goto FIJH;
		}
		if (fd == tp1)										//位移机关的判定
		{
			printf("触发位移机关，宝藏位置发生改变\n");
			printf("新的宝藏位于区域1——%d\n", gold);
			gold = rand() % gl + 1;							//新的宝藏会生成在小于等于旧位置的区域内
			tpe = 1;										//触发位移机关，更改tpe值
		}
		if (fd == tp2)
		{
			printf("触发位移机关，宝藏位置发生改变\n");
			printf("新的宝藏位于区域%d——100\n", gold);
			gold = rand() % (100 - gl + 1) + gl;			//新的宝藏会生成在大于等于旧位置的区域内
			tpe = 2;										//触发位移机关，更改tpe值
		}
		if (tpe>0)								//位移机关的处理
		{
			tp1 = tpf1(gold, tp0);				//生成位移机关
			tp2 = tpf2(gold, tp0);
			path1 = pathf1(gold, path0);		//生成秘密通道开关
			path2 = pathf2(gold, path0);
			u = 1;								//重置u值
			v = 10;								//重置v值
			w0 = 0;								//重置w0值
			w1 = 0;								//重置w1值
			w2 = 0;								//重置w2值
			for (i = 0; i < 20; i = i + 2)		//生成炸弹开关
			{
				bm[i] = bmf(i, u);
				w1 = bm[i];
				w0 = bmw(w1, gold, tp1, tp2, path1, path2);
				if (w0 == 1)
				{
					bm[i]--;
					w0 = 0;
				}
				w0 = 0;
				bm[i + 1] = bm[i] + rand() % 5 + 1;
				if (bm[i + 1] > v)					//值大小修正
				{
					bm[i + 1] = bm[i + 1] - 10;
				}
				w2 = bm[i + 1];
				w0 = bmw(w2, gold, tp1, tp2, path1, path2);
				if (w0 == 1)
				{
					bm[i + 1]--;
					w0 = 0;
				}
				w0 = 0;
				u = u + 10;
				v = v + 10;
			}
			if (tpe == 1)
			{
				max = gl;							//更新最大值为新范围最大值
				min = 1;							//更新最小值为新范围最小值
			}
			if (tpe == 2)
			{
				max = 100;							//更新最大值为新范围最大值
				min = gl;							//更新最小值为新范围最小值
			}
			int sr1 = rand() % 100;					//自定义种子
			int sr2 = sr1 + rand() % 10;			//自定义种子
			if (pt == 1)
			{
				pa1 = paf1(sr1, min, max, gold);
				pa2 = paf2(sr2, min, max, gold);
			}
			tpe = 0;
			gl = 0;
			if (min==max)							//处理极端情况：当只剩1或者100时在1——100的范围内生成新宝藏
			{
				gold = rand() % 100 + 1;			//在1——100范围内生成新的宝藏
				tp1 = tpf1(gold, tp0);				//生成位移机关
				tp2 = tpf2(gold, tp0);
				path1 = pathf1(gold, path0);		//生成秘密通道开关
				path2 = pathf2(gold, path0);
				u = 1;								//重置u值
				v = 10;								//重置v值
				w0 = 0;								//重置w0值
				w1 = 0;								//重置w1值
				w2 = 0;								//重置w2值
				for (i = 0; i < 20; i = i + 2)		//生成炸弹开关
				{
					bm[i] = bmf(i, u);
					w1 = bm[i];
					w0 = bmw(w1, gold, tp1, tp2, path1, path2);
					if (w0 == 1)
					{
						bm[i]--;
						w0 = 0;
					}
					w0 = 0;
					bm[i + 1] = bm[i] + rand() % 5 + 1;
					if (bm[i + 1] > v)				//值大小修正
					{
						bm[i + 1] = bm[i + 1] - 10;
					}
					w2 = bm[i + 1];
					w0 = bmw(w2, gold, tp1, tp2, path1, path2);
					if (w0 == 1)
					{
						bm[i + 1]--;
						w0 = 0;
					}
					w0 = 0;
					u = u + 10;
					v = v + 10;
				}
				int sr1 = rand() % 100;				//自定义种子
				int sr2 = sr1 + rand() % 10;		//自定义种子
				if (pt == 1)
				{
					pa1 = paf1(sr1, min, max, gold);
					pa2 = paf2(sr2, min, max, gold);
				}
				min = 1;
				max = 100;
				printf("由于只剩下一个数字，故在区域1——100重新生成宝藏\n");
			}
			continue;
		}
		if (fd==path1||fd==path2)			//生成秘密通道
		{
			min = minf(fd, gold, min);		//记录当前最小值
			max = maxf(fd, gold, max);		//记录当前最大值
			int sr1 = rand() % 100;			//自定义种子
			int sr2 = sr1 + rand() % 10;	//自定义种子
			if (pt==1)
			{
				pa1 = paf1(sr1, min, max, gold);
				pa2 = paf2(sr2, min, max, gold);
				printf("秘密通道位置发生变化，当前剩余区域：%d--%d\n", min, max);
			}
			else
			{
				pt = 1;
				pa1 = paf1(sr1, min, max, gold);
				pa2 = paf2(sr2, min, max, gold);
				printf("秘密通道已打开，当前剩余区域：%d--%d\n", min, max);
			}
			goto FIJH;
		}
		for (i = 0; i < 20; i++)			//炸弹开关触发判定
		{
			if (fd==bm[i])
			{
				wr = 1;
			}
		}
		if (wr==1)							//炸弹开关处理
		{
			switch (rl)
			{
			case 1:
				printf("发现一个开关，当前处于打开状态，请问是否要关闭？\n");
				printf("（输入1执行操作，输入0放弃操作继续）\n");
				scanf_s("%d", &wrl);
				if (wrl == 1)
				{
					rl = 0;
					wrl = 0;
					printf("已断开炸弹链接！\n");
					min = minf(fd, gold, min);			//记录当前最小值
					max = maxf(fd, gold, max);			//记录当前最大值
					printf("————剩余区域：%d--%d\n", min, max);
				}
				else
				{
					min = minf(fd, gold, min);			//记录当前最小值
					max = maxf(fd, gold, max);			//记录当前最大值
					printf("————剩余区域：%d--%d\n", min, max);
				}
				wr = 0;
				goto FIJH;
			case 0:
				printf("发现一个开关，当前处于关闭状态，请问是否要打开？\n");
				printf("（输入1执行操作，输入0放弃操作继续）\n");
				scanf_s("%d", &wrl);
				if (wrl == 1)
				{
					rl = 1;
					wrl = 0;
					printf("已恢复炸弹链接！\n");
					min = minf(fd, gold, min);			//记录当前最小值
					max = maxf(fd, gold, max);			//记录当前最大值
					printf("————剩余区域：%d--%d\n", min, max);
				}
				else
				{
					min = minf(fd, gold, min);			//记录当前最小值
					max = maxf(fd, gold, max);			//记录当前最大值
					printf("————剩余区域：%d--%d\n", min, max);
				}
				wr = 0;
				goto FIJH;
			}
		}
		min = minf(fd, gold, min);			//记录当前最小值
		max = maxf(fd, gold, max);			//记录当前最大值
		printf("这个位置没有东西\n");
		printf("————剩余区域：%d--%d\n", min, max);		//输出当前有效范围
	FIJH:					//优先级处理标记
		fd = 0;
	} while (fin == 0);
END:						//标记位置，用于强制结束游戏
	if (rl==1)				//游戏结束后公布结果
	{
		if (fin==1)
		{
			printf("\n发现宝藏！\n");
			printf("但是很遗憾，炸弹爆炸，触发者失败。\n");
		}
		if (fin==2)
		{
			printf("\n掉入秘密通道，触发所有炸弹，游戏结束。\n");
			printf("很遗憾，触发者失败。\n");
		}
	}
	if (rl==0)
	{
		if (fin == 1)
		{
			printf("\n发现宝藏！\n");
			printf("炸弹未发生爆炸，恭喜触发者获得胜利！！！\n");
		}
		if (fin == 2)
		{
			printf("\n掉入秘密通道，发现宝藏！\n");
			printf("所有炸弹均未爆炸，恭喜触发者获得胜利！！！\n");
		}
	}
	printf("\n输入除103、104之外的任意字符并回车结束\n");
	printf("输入代码103并回车可直接开启下一局\n");
	printf("输入代码104并回车可清除记录\n");
	scanf_s("%d", &fe);						//保持窗口显示
	if (fe == 103)							//直接重开游戏
	{
		printf("\n已重开游戏\n");
		goto ICE;
	}
	if (fe == 104)							//清除控制台
	{
		system("cls");
		printf("\n已重开游戏\n");
		goto ICE;
	}
	return 0;
}

int tpf1(int gold, int tp0)
{
	int tpx1;						//原参数插入x（下同）
	tpx1 = gold + tp0;
	if (tpx1 > 100)
	{
		tpx1 = tpx1 - 100;
	}
	return tpx1;
}

int tpf2(int gold, int tp0)
{
	int tpx2;
	tpx2 = gold - tp0;
	if (tpx2 < 1)
	{
		tpx2 = tpx2 + 100;
	}
	return tpx2;
}

int pathf1(int gold, int path0) 
{
	int pathx1;
	pathx1 = gold + path0;
	if (pathx1 > 100)
	{
		pathx1 = pathx1 - 100;
	}
	return pathx1;
}

int pathf2(int gold, int path0)
{
	int pathx2;
	pathx2 = gold - path0;
	if (pathx2 < 1)
	{
		pathx2 = pathx2 + 100;
	}
	return pathx2;
}

int bmf(int i, int u) 
{
	int bmx[20];
	bmx[i] = rand() % 11 + u;
	return bmx[i];
}

int bmw(int wx, int gold, int tp1, int tp2, int path1, int path2) 
{
	int w = 0;
	if (wx==gold)
	{
		w = 1;
	}
	if (wx==tp1)
	{
		w = 1;
	}
	if (wx==tp2)
	{
		w = 1;
	}
	if (wx==path1)
	{
		w = 1;
	}
	if (wx==path2)
	{
		w = 1;
	}
	return w;
}

int paf1(int sr1,int min, int max,int gold) 
{
	int pax1;
	int pao1;
	srand(sr1);									//定义rand函数种子
	pao1 = rand() % 2 + 1;						//生成1或2用于决定后续是加是减
	pax1 = rand() % (max - min + 1) + min;		//在剩余范围内生成通道
	if (pax1==gold)
	{
		if (pao1==1)
		{
			pax1++;
		}
		else
		{
			pax1--;
		}
	}
	return pax1;
}

int paf2(int sr2,int min, int max, int gold)
{
	int pax2;
	int pao2;
	srand(sr2);									//定义rand函数种子
	pao2 = rand() % 2 + 1;						//生成1或2用于决定后续是加是减
	pax2 = rand() % (max - min + 1) + min;		//在剩余范围内生成通道
	if (pax2 == gold)
	{
		if (pao2 == 1)
		{
			pax2++;
		}
		else
		{
			pax2--;
		}
	}
	return pax2;
}

int minf(int fd,int gold,int min) 
{
	int minx;
	if (fd<gold)
	{
		if (fd>min)
		{
			minx = fd;
		}
		else
		{
			minx = min;
		}
	}
	else
	{
		minx = min;
	}
	return minx;
}

int maxf(int fd, int gold, int max) 
{
	int maxx;
	if (fd>gold)
	{
		if (fd<max)
		{
			maxx = fd;
		}
		else
		{
			maxx = max;
		}
	}
	else
	{
		maxx = max;
	}
	return maxx;
}

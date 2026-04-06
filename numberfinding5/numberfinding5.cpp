#include <iostream>
#include <random>			// 现代随机数库
#include <cstdlib>			// 使用系统命令清除控制台

using namespace std;

// 定义函数fx12，用于生成位移机关

void fx12(int a, int x0, int* x1, int* x2) {
	*x1 = a - x0;		//一号值为宝藏位置减去范围
	if (*x1 < 1) {
		*x1 = *x1 + 100;		//如果一号值小于1，那么将该值加100
	}
	*x2 = a + x0;		//二号值为宝藏位置加上范围
	if (*x2 > 100) {
		*x2 = *x2 - 100;		//如果二号值大于100，那么将该值减100
	}
}

//定义函数bmf，用于生成部分炸弹开关

int bmf(int i, int u, mt19937& eng) {
	int bmx[20];
	uniform_int_distribution<int> disu(u, u + 9);		// 均匀整数分布,范围u——u+9（e.g.:21——30）
	bmx[i] = disu(eng);			//每10个值内（u——u+9）取一个值作为炸弹开关
	return bmx[i];
}

// 定义函数bmw，用于判断是否存在值冲突

int bmw(int wx, int g, int t1, int t2, int p1, int p2) {
	int w = 0;		// 定义一个过渡值，0为不存在冲突，1为存在冲突
	if (wx == g) {
		w = 1;
	}
	if (wx == t1) {
		w = 1;
	}
	if (wx == t2) {
		w = 1;
	}
	if (wx == p1) {
		w = 1;
	}
	if (wx == p2) {
		w = 1;
	}
	return w;
}

// 定义函数paf，用于生成秘密通道

int paf(int min, int max, int g, mt19937& eng) {
	int pax = 0;
	int pao = 0;
	uniform_int_distribution<int> dispaf(min, max);		// 均匀整数分布,范围min——max
	pax = dispaf(eng);			// 在剩余范围内生成秘密通道

	// 如果生成的值与宝藏位置冲突，将该值加1或者减1

	uniform_int_distribution<int> dis16(1, 6);		// 均匀整数分布,范围1——6
	pao = dis16(eng);			// 取一个随机数用于决定是加还是减
	if (pax == g) {
		if (pao < 4) {
			pax--;			// 如果随机数为1、2、3则自加
		}
		else {
			pax++;			// 如果随机数为4、5、6则自减
		}
	}
	return pax;
}

//定义函数mf，用于更新最大值和最小值

void mf(int x, int g, int* mi, int* ma) {
	if (x < g) {
		if (x > *mi) {
			*mi = x;		// 如果输入的值比宝藏位置小且比当前最小值大则更新最小值
		}
	}
	else {
		if (x < *ma) {
			*ma = x;		// 如果输入的值比宝藏位置大且比当前最大值小则更新最大值
		}
	}
}

// 主函数

int main(){

	//核心变量

	int find = 0;			// 定义变量，用于存储输入的值
	int fe = -1;			// 定义单独的输入值存储变量，用于游戏结束时保持控制台开启
	int fin = 0;			// 定义变量，用于结束判定——结束条件：fin > 0
	int gold = 0;			// 定义宝藏变量，触发后为fin赋值“1”
	int gl = 0;				// 定义变量，用于记录旧的宝藏位置
	int min = 1, max = 100;	// 定义变量，用于提示剩余区域范围
	int path0 = 0;			// 定义变量，用于存储秘密通道开关的生成范围
	int path1 = 0, path2 = 0;	// 定义两个秘密通道开关变量
	int pt = -1;			// 定义变量，用于秘密通道触发判定
	int pa1 = 0, pa2 = 0;	// 定义两个秘密通道变量，触发后为fin赋值“2”
	int tp0 = 0;			// 定义变量，用于记录位移机关范围
	int tp1 = 0, tp2 = 0;	// 定义两个位移机关变量
	int tpe = -1;			// 定义变量，用于位移机关触发判定
	int bm[20];				// 定义数组，用于存储20个炸弹开关的位置
	int wr = -1;			// 定义变量，用于判断炸弹开关是否被发现
	int rl = 1;				// 定义变量，用于记录炸弹开关状态，默认开启（1），关闭值（0）
	int wrl = 0;			// 定义变量，用于操作炸弹开关
	int u = 1, v = 10;		// 定义变量，用于数组赋值
	int w0 = 0, w1 = 0, w2 = 0;		// 定义变量，用于修正数组值
	int x = 1;			// 定义计算器，用于记录一行输出了几个值

ICE:			// 重开游戏标记

	// 初始化游戏
	// 初始化随机数生成引擎
	
	random_device rd;		// 硬件熵源（真随机数）
	mt19937 gen(rd());		// 梅森旋转算法引擎（伪随机数）

	// 复位变量

	u = 1;
	v = 10;
	w0 = w1 = w2 = 0;
	fin = 0;
	pt = 0;
	pa1 = pa2 = 0;
	tpe = 0;
	rl = 1;
	min = 1;
	max = 100;

	// 生成各有效值

	uniform_int_distribution<int> disgold(1, 100);		// 均匀整数分布,范围1——100
	gold = disgold(gen);			//使用disgold分布生成宝藏位置gold

	uniform_int_distribution<int> distp(1, 30);		// 均匀整数分布,范围1——30
	tp0 = distp(gen);			//使用distp分布生成位移机关范围tp0

	uniform_int_distribution<int> dispath(5, 16);		// 均匀整数分布,范围5——16
	path0 = dispath(gen);			//使用dispath分布生成秘密通道开关范围path0

	// 如果生成的位移机关范围和秘密通道开关范围相同
	// 改变秘密通道开关范围为“位移机关范围”+“2——5随机值”

	if (path0 == tp0) {
		uniform_int_distribution<int> distpf(2, 5);		// 均匀整数分布,范围2——5
		path0 = tp0 + distpf(gen);
	}

	fx12(gold, tp0, &tp1, &tp2);			// 调用fx12函数生成位移机关
	fx12(gold, path0, &path1, &path2);			// 调用fx12函数生成秘密通道开关

	//通过for循环为bm数组赋值，生成炸弹开关

	for (int i = 0; i < 20; i = i + 2) {
		bm[i] = bmf(i, u, gen);			// 调用bmf函数生成第一个开关
		w1 = bm[i];			// 临时存储第一个开关值
		w0 = bmw(w1, gold, tp1, tp2, path1, path2);			// 调用bmw函数进行值冲突判断
		if (w0 == 1) {
			bm[i]--;			// 如果存在冲突，将值自减
			w0 = 0;			// 复位中间值
		}
		w0 = 0;
		uniform_int_distribution<int> disbmi(1, 5);		// 均匀整数分布,范围1——5
		bm[i + 1] = bm[i] + disbmi(gen);			// 第一个开关值加上1——5范围的随机值生成另一个开关
		if (bm[i + 1] > v) {
			bm[i + 1] = bm[i + 1] - 10;			// 如果另一个值偏大，那么该值减10
		}
		w2 = bm[i + 1];			// 临时存储另一个开关值
		w0 = bmw(w2, gold, tp1, tp2, path1, path2);			// 调用bmw函数进行值冲突判断
		if (w0 == 1) {
			bm[i + 1]--;			// 如果存在冲突，将值自减
			w0 = 0;			// 复位中间值
		}
		w0 = 0;
		u = u + 10;			// 进入下一次循环，调整中间值到下一个范围（e.g.:1——>11）
		v = v + 10;			// 进入下一次循环，调整中间值到下一个范围（e.g.:10——>20）
	}

	// 初始化完成，输出游戏说明

	cout << "创作参考：数字炸弹|游戏名称：数轴探宝" << endl;
	cout << "开发：凌柃|代码语言：C++|版本：5.1" << endl;
	cout << "指令代码：101——输出位移机关触发点范围值" << endl;
	cout << "指令代码：102——强制结束游戏|103——直接重开游戏" << endl;
	cout << "指令代码：104——清除过往记录并重开|105——输出当前有效值" << endl;
	cout << "说明：" << endl << "在数轴1到100的范围内藏着一处与炸弹相连的宝藏" << endl;
	cout << "有两处被关闭的秘密通道直接通往宝藏所在之处" << endl;
	cout << "通道之内安放着同样的炸弹，一旦落入即触发" << endl;
	cout << "想要获得宝藏，需要找到可以关闭炸弹链接的开关" << endl;
	cout << "位于宝藏附近·" << tp0 << "·单位的位移机关能改变宝藏位置" << endl;
	
	// *****主 运 算 部 分*****
	// 建立do while循环，当fin大于0结束循环

	do	{

		// 首先读取一个数字

		cout << "请输入一个整数：";
		cin >> find;

		gl = gold;			// 记录旧的宝藏位置备用

		// 对输入的数字进行第一优先级的代码判断

		switch (find)
		{
		case 101:			// 代码101，输出位移机关触发点范围值
			cout << "位移机关位于宝藏附近·" << tp0 << "·单位处" << endl;
			find = 0;
			goto FIJH;			// 位于do while循环末尾
		case 102:			// 代码102，强制结束游戏
			cout << "游戏执行强制结束代码" << endl;
			goto END;			// 位于do while循环结束之后
		case 103:			// 代码103，直接重开游戏
			cout << "\n已重开游戏" << endl;
			goto ICE;			// 位于变量定义后，游戏初始化前
		case 105:			// 代码105，输出当前有效值
			cout << "--当前有效值如下--" << endl;

			// 炸弹开关

			cout << "炸弹开关：（当前状态：" << rl << "）" << endl;
			for (int i = 0; i < 20; i++) {
				cout << bm[i] << "\t";
				if (x == 5) {			// 当一行输出了5个值时换行
					cout << endl;
					x = 0;
				}
				x++;
			}

			// 位移机关及其范围

			cout << "位移机关：" << tp1 << "，" << tp2 << "，范围：" << tp0 << endl;

			// 秘密通道开关及其范围

			cout << "秘密通道开关：" << path1 << "，" << path2 << "，范围：" << path0 << endl;

			// 秘密通道

			if (pt == 1) {			// 如果秘密通道已生成，那么输出两个秘密通道位置，否则输出状态
				cout << "秘密通道：" << pa1 << "，" << pa2 << endl;
			}
			else {
				cout << "秘密通道：未开启" << endl;
			}

			// 宝藏

			cout << "宝藏：" << gold << endl;

			goto FIJH;			// 位于do while循环末尾
		}

		// 第二优先级判定：是否直接找到宝藏

		if (find == gold) {
			fin = 1;
			goto FIJH;			// 位于do while循环末尾
		}

		// 第三优先级判定：是否找到秘密通道

		if (find == pa1 || find == pa2) {
			fin = 2;
			goto FIJH;			// 位于do while循环末尾
		}

		// 第四优先级判定：是否触发位移机关
		// 首先改变宝藏位置

		if (find == tp1) {
			cout << "触发位移机关，宝藏位置发生改变" << endl;
			cout << "新的宝藏位于区域" << gold << "——100" << endl;
			uniform_int_distribution<int> disgtp1(gl, 100);		// 均匀整数分布,范围gl——100
			gold = disgtp1(gen);			// 新的宝藏生成在大于等于旧位置的区域内
			max = 100;							//更新最大值为新范围最大值
			min = gl;							//更新最小值为新范围最小值
			tpe = 1;
		}
		if (find == tp2) {
			cout << "触发位移机关，宝藏位置发生改变" << endl;
			cout << "新的宝藏位于区域1——" << gold << endl;
			uniform_int_distribution<int> disgtp2(1, gl);		// 均匀整数分布,范围1——gl
			gold = disgtp2(gen);			// 新的宝藏生成在小于等于旧位置的区域内
			max = gl;							//更新最大值为新范围最大值
			min = 1;							//更新最小值为新范围最小值
			tpe = 2;
		}

		// 位移机关状态确认后，执行位移机关的其他处理

		if (tpe > 0) {

			// 特别的：当只剩下1或者100时在1——100的范围内重新生成新宝藏

			if (min == max) {
				cout << "由于只剩下一个数字，故在区域1——100重新生成宝藏" << endl;
				min = 1;
				max = 100;
				uniform_int_distribution<int> disgold(1, 100);		// 均匀整数分布,范围1——100
				gold = disgold(gen);			//使用disgold分布生成新的宝藏位置gold
			}

			// 生成新的位移机关和秘密通道开关

			fx12(gold, tp0, &tp1, &tp2);			// 调用fx12函数生成新的位移机关
			fx12(gold, path0, &path1, &path2);			// 调用fx12函数生成新的秘密通道开关

			// 复位与炸弹开关相关的值

			u = 1;
			v = 10;
			w0 = 0;
			w1 = 0;
			w2 = 0;

			// 生成新的炸弹开关

			for (int i = 0; i < 20; i = i + 2) {
				bm[i] = bmf(i, u, gen);			// 调用bmf函数生成第一个开关
				w1 = bm[i];			// 临时存储第一个开关值
				w0 = bmw(w1, gold, tp1, tp2, path1, path2);			// 调用bmw函数进行值冲突判断
				if (w0 == 1) {
					bm[i]--;			// 如果存在冲突，将值自减
					w0 = 0;			// 复位中间值
				}
				w0 = 0;
				uniform_int_distribution<int> disbmi(1, 5);		// 均匀整数分布,范围1——5
				bm[i + 1] = bm[i] + disbmi(gen);			// 第一个开关值加上1——5范围的随机值生成另一个开关
				if (bm[i + 1] > v) {
					bm[i + 1] = bm[i + 1] - 10;			// 如果另一个值偏大，那么该值减10
				}
				w2 = bm[i + 1];			// 临时存储另一个开关值
				w0 = bmw(w2, gold, tp1, tp2, path1, path2);			// 调用bmw函数进行值冲突判断
				if (w0 == 1) {
					bm[i + 1]--;			// 如果存在冲突，将值自减
					w0 = 0;			// 复位中间值
				}
				w0 = 0;
				u = u + 10;			// 进入下一次循环，调整中间值到下一个范围（e.g.:1——>11）
				v = v + 10;			// 进入下一次循环，调整中间值到下一个范围（e.g.:10——>20）
			}

			// 判断秘密通道开关是否触发
			// 如果已触发则生成新的秘密通道，否则不执行

			if (pt == 1) {
				pa1 = paf(min, max, gold, gen);			// 调用paf函数生成新的秘密通道1
				pa2 = paf(min, max, gold, gen);			// 调用paf函数生成新的秘密通道2
			}

			// 复位值tpe

			tpe = 0;

			continue;
		}

		// 第五优先级判定：是否触发秘密通道开关

		if (find == path1 || find == path2) {

			// 首先更新最大值和最小值

			mf(find, gold, &min, &max);

			// 如果之前已经生成有秘密通道则更新位置，没有则生成秘密通道

			if (pt == 1) {
				pa1 = paf(min, max, gold, gen);			// 调用paf函数生成新的秘密通道1
				pa2 = paf(min, max, gold, gen);			// 调用paf函数生成新的秘密通道2
				cout << "秘密通道位置发生变化，当前剩余区域：" << min << "——" << max << endl;
			}
			else {
				pt = 1;
				pa1 = paf(min, max, gold, gen);			// 调用paf函数生成秘密通道1
				pa2 = paf(min, max, gold, gen);			// 调用paf函数生成秘密通道2
				cout << "秘密通道已开启，当前剩余区域：" << min << "——" << max << endl;
			}
			goto FIJH;			// 位于do while循环末尾
		}

		// 第六优先级判定：是否触发炸弹开关
		// 如果触发，先记录触发状态

		for (int i = 0; i < 20; i++) {
			if (find == bm[i]) {
				wr = 1;
			}
		}

		// 确认炸弹开关触发状态为触发后执行炸弹开关处理

		if (wr == 1) {
			switch (rl)
			{
			case 1:			// 如果开关处于打开状态，询问玩家是否要关闭
				cout << "发现一个开关，当前处于打开状态，请问是否要关闭？" << endl;
				cout << "（输入1执行操作，输入0放弃操作继续）" << endl;
				cin >> wrl;
				if (wrl == 1) {
					rl = 0;
					wrl = 0;
					cout << "已断开炸弹链接！" << endl;
					mf(find, gold, &min, &max);
					cout << "————剩余区域：" << min << "——" << max << endl;
				}
				else {
					mf(find, gold, &min, &max);
					cout << "————剩余区域：" << min << "——" << max << endl;
				}
				wr = 0;
				goto FIJH;			// 位于do while循环末尾
			case 0:			// 如果开关处于关闭状态，询问玩家是否要打开
				cout << "发现一个开关，当前处于关闭状态，请问是否要打开？" << endl;
				cout << "（输入1执行操作，输入0放弃操作继续）" << endl;
				cin >> wrl;
				if (wrl == 1) {
					rl = 1;
					wrl = 0;
					cout << "已恢复炸弹链接！" << endl;
					mf(find, gold, &min, &max);
					cout << "————剩余区域：" << min << "——" << max << endl;
				}
				else {
					mf(find, gold, &min, &max);
					cout << "————剩余区域：" << min << "——" << max << endl;
				}
				wr = 0;
				goto FIJH;			// 位于do while循环末尾
			}
		}

		// 如果没有触发任何一个有效值，更新当前最大值和最小值

		mf(find, gold, &min, &max);
		cout << "这个位置十分空旷" << endl;
		cout << "————剩余区域：" << min << "——" << max << endl;

	FIJH:			// 结束循环标记
		find = 0;
	} while (fin == 0);

END:			// 强制结束游戏标记
	
	// 游戏结束，进行结算

	if (rl == 1) {
		if (fin == 1) {

			// 炸弹开关处于打开状态时找到宝藏会导致炸弹爆炸，发现者失败

			cout << "\n发现宝藏！" << endl;
			cout << "但是很遗憾，炸弹爆炸，触发者失败。" << endl;
		}
		if (fin == 2) {

			// 炸弹开关处于打开状态时掉入秘密通道会导致炸弹爆炸，发现者失败

			cout << "\n掉入秘密通道，触发所有炸弹！" << endl;
			cout << "很遗憾，触发者失败。" << endl;
		}
	}
	if (rl == 0) {
		if (fin == 1) {

			// 炸弹开关处于关闭状态时找到宝藏，发现者可以安全带走宝藏获得胜利

			cout << "\n发现宝藏！" << endl;
			cout << "炸弹未发生爆炸，恭喜触发者获得胜利！！！" << endl;
		}
		if (fin == 2) {

			// 炸弹开关处于关闭状态时掉入秘密通道，发现者直接找到了宝藏并可以安全带走宝藏获得胜利

			cout << "\n掉入秘密通道，发现宝藏！" << endl;
			cout << "所有炸弹均未爆炸，恭喜触发者获得胜利！！！" << endl;
		}
	}

	// 结算完毕后请求下一步操作

	cout << "\n输入除103、104之外的任意整数并回车结束" << endl;
	cout << "输入代码103并回车可直接开启下一局" << endl;
	cout << "输入代码104并回车可清除记录" << endl;
	cin >> fe;
	if (fe == 103) {

		// 代码103，直接重开游戏

		cout << "\n已重开游戏" << endl;
		goto ICE;			// 位于变量定义后，游戏初始化前
	}
	if (fe == 104) {
		system("cls");			// 清空控制台
		cout << "\n已重开游戏" << endl;
		goto ICE;			// 位于变量定义后，游戏初始化前
	}
	return 0;
}

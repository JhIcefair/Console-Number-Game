#include <iostream>
#include <random>		// 现代随机数库
#include <iomanip>		// 用于控制输出格式

using namespace std;

// 主函数

int main() {

	// 定义值

	int waterx = -1;	// 随机大小水杯，容量20——300
	int watery = -1;	// 随机大小水杯容量存储器
	int waterov = -1;	// 溢出判定
	int water = 0;		// 水杯
	int wa = -1;		// 倒水存储，支持值1——50
	int dox = 0;		// 定义判定值用于判定值合法
	int fin = 0;		// 定义结束判定
	int over = -1;		// 溢出阈值，水杯容量在100以内时值范围1—3，大于100值范围4—7
	int number = -1;	// 计数器

ICE:		// 重开游戏标记

	// 初始化游戏
	// 初始化随机数生成引擎

	random_device rd;		// 硬件熵源（真随机数）
	mt19937 gen(rd());		// 梅森旋转算法引擎（伪随机数）

	// 生成随机大小的水杯

	uniform_int_distribution<int> waterxr(20, 300);		// 均匀整数分布,范围20——300
	waterx = waterxr(gen);			//使用waterxr分布生成随机大小水杯waterx
	watery = waterx;

	// 生成溢出阈值

	if (waterx <= 100) {
		uniform_int_distribution<int> ov1(1, 3);		// 均匀整数分布,范围1——3
		over = ov1(gen);
	}
	else {
		uniform_int_distribution<int> ov2(4, 7);		// 均匀整数分布,范围4——7
		over = ov2(gen);
	}

	// 初始化值

	waterov = waterx + over;
	water = 0;
	wa = -1;
	dox = 0;
	fin = 0;
	number = 0;

	// 游戏初始化完毕，输出游戏说明

	cout << "游戏名称：倒水挑战|游戏版本：1.2" << endl;
	cout << "代码语言：C++|游戏开发：凌柃" << endl;
	cout << "游戏代码：101——输出大水杯容量及水溢出阈值" << endl;
	cout << "游戏代码：102——强制结束游戏|103——直接重开游戏" << endl;
	cout << "游戏代码：111——输出当前水量|222——定义大水杯容量" << endl;
	cout << "游戏说明：" << endl;
	cout << "现有一个随机大小的大水杯和一个容量50的小水杯" << endl;
	cout << "可以用小水杯向大水杯中倒入一定量的水" << endl;
	cout << "导致水溢出的为失败者" << endl;

	// *****主 运 算 部 分*****
	// 建立do while循环，当fin大于0结束循环
	
	do {

		// 读取准备倒入小水杯中的水量

		dox = 0;
		do {
			cout << "请输入一个整数：";
			cin >> wa;

			// 游戏代码判定

			int sw = 0;		// 临时过渡值
			switch (wa)
			{
			case 101:		// 输出大水杯容量及水溢出阈值
				cout << "大水杯容量：" << waterx << endl;
				cout << "水溢出阈值：" << over << endl;
				sw = 1;
				break;
			case 102:		// 强制结束游戏
				goto END;
			case 103:		// 直接重开游戏
				cout << "\n已重开游戏" << endl;
				goto ICE;
			case 111:		// 输出当前水量
				cout << "当前水量：" << water << endl;
				sw = 1;
				break;
			case 222:		// 定义大水杯容量
				cout << "执行强制更改大水杯容量代码" << endl;
				cout << "请注意：该操作将会使之前的操作作废！" << endl;
				cout << "输入-9终止代码" << endl;
				int sw9 = 0;		// 终止过渡
				do {

					// 检测输入的值防止出现非正整数

					cout << "请输入一个大于1的整数作为大水杯容量：";
					cin >> waterx;

					// 判断是否执行终止代码

					if (waterx == -9) {
						waterx = watery;
						sw9 = 1;
						break;
					}
				} while (waterx <= 0);

				// 如果终止该代码，跳过后续语句

				if (sw9 == 1) {
					cout << "已终止代码" << endl;
					sw9 = 0;
					sw = 1;
					break;
				}

				// 初始化值

				waterov = waterx + over;
				water = 0;
				wa = -1;
				dox = 0;
				fin = 0;
				number = 0;
				watery = waterx;

				sw = 1;
			}

			// 代码执行后跳过该循环后续语句

			if (sw == 1) {
				continue;
			}

			// 判定值是否符合要求

			if (wa > 0 && wa < 51) {
				dox = 1;
			}
			else {
				cout << "值超出范围，请输入1——50范围内的整数" << endl;
			}

			// 计数器

			number++;
		} while (dox == 0);

		// 将小水杯中的水倒入大水杯

		water = water + wa;

		// 判定生成的大水杯容量是否小于小水杯
		// 如果小于则强制确保第一次不会溢出

		if (number == 1 && waterx<51 && water>waterx) {
			water = waterx;		// 首先使水杯中充满水
			cout << "即将溢出警告！！！" << endl;		// 其次输出“即将溢出警告”
			continue;		// 跳过该循环后续语句
		}

		// 判定水是否溢出

		if (water > waterov) {

			// 如果水溢出,游戏结束

			cout << "水溢出了，游戏结束" << endl;
			fin = 1;
		}
		else {

			// 如果水没有溢出，输出当前水量百分比

			if (water > waterx) {

				// 如果水满，直接输出溢出警告
				cout << "即将溢出警告！！！" << endl;
			}
			else {

				// 如果水没有满，进行占比计算

				double a = 0;
				double b = 0;
				double c = 0;
				a = (double)waterx;
				b = (double)water;
				c = (b / a) * 100;

				// 设置输出格式：固定小数点表示，保留两位小数

				cout << fixed << setprecision(2);

				// 如果水量已达到98%则不再输出确定百分比

				if (c >= 98) {
					cout << "即将溢出警告！！！" << endl;
				}
				else {
					cout << "当前水量：" << c << "%" << endl;
				}
			}
		}
	} while (fin == 0);
	
END:		// 游戏结束标记

	// 游戏结束后保持窗口显示

	cout << "输入任意整数结束游戏" << endl;
	cout << "输入103可重开游戏" << endl;
	cin >> wa;
	if (wa == 103) {
		cout << "\n已重开游戏" << endl;
		goto ICE;
	}
}

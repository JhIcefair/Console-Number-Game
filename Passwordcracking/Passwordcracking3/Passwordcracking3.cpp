#include <iostream>
#include <random>			// 现代随机数库
#include <cstdlib>			// 使用系统命令清除控制台

using namespace std;

int main() {

	//核心变量

	int i = 0;
	int a = 0;				// 范围最大值
	int ab = 0;				// 辅助判断器中间值
	int f = 0;				// 判断过渡
	int e = 0;				// 模式存储
	int e0 = 0;				// 模式存储继承中间值
	int a0 = 0;				// 范围存储继承中间值
	int ha1 = 0, ha2 = 0;	// 困难模式判断过渡
	int c = 0;				// 次数记录
	int k = 0;				// 确认输入过渡
	int eafk = 0;			// 确认继承过渡
	int fin = 0;			// 结束判断
	int fine = 0;			// 结束过渡
	int eaf = 0;			// 继承设置过渡
	int pw[4];				// 四位密码
	int pwa[4];				// 密码输入
	int p[100];				// 预备数组
	int yu = 5;				// 代码执行中间值

ICE:			// 重开游戏标记*

	// 初始化游戏
	// 初始化随机数生成引擎

	random_device rd;		// 硬件熵源（真随机数）
	mt19937 gen(rd());		// 梅森旋转算法引擎（伪随机数）

	// 配置预备数组（0-99）

	for (i = 0; i < 100; i++) {
		p[i] = i;
	}

	// 洗牌乱序

	for (i = 99; i > 0; i--) {
		int l1 = rand() % (i + 1);		// 任意生成一个随机位置l1
		int l2 = p[i];					// 提取位置i的值
		p[i] = p[l1];					// 将随机位置l1的值赋值给位置i
		p[l1] = l2;						// 将位置i的值赋值给随机位置l1
	}

	// 初始化完成，输出游戏说明

	cout << "游戏开发：凌柃|代码语言：C++|版本：3.0" << endl;
	cout << "游戏代码：（除104外在游戏设置完毕后有效）" << endl;
	cout << "101——直接输出密码|102——直接结束游戏" << endl;
	cout << "103——直接重开游戏|104——清除记录并重开" << endl;
	cout << "105——启用辅助判断器|106——停用辅助判断器" << endl;
	cout << "107——输出当前难度及范围" << endl;
	cout << "108——直接重开游戏且继承上一局游戏设置" << endl;
	cout << "请注意：密码有四个数字，游戏代码在准备完毕后才生效！" << endl;

	// 游戏难度配置
	// 如果继承设置过渡为0则进入设置，否则进入继承

	if (eaf == 0) {
		cout << "请输入您选择的难度（1简单，2困难）：";
		cin >> e;
		cout << "请输入您挑战的最大有效值（范围3——99）：";
		cin >> a;
	}
	else {

		// e,a值继承

		e = e0;
		a = a0;

		// 输出继承的设置

		cout << "\n您选择了继承上一次的设置->" << endl;
		cout << "游戏难度：";
		if (e == 1) {
			cout << "简单" << endl;
		}
		else {
			cout << "困难" << endl;
		}
		cout << "有效值范围：0——" << a << endl;

		// 继承确认

		cout << "输入1确认继承，输入2重新设置：";
		eafk = 0;			// 清除中间值
		cin >> eafk;

		// 确认继承判断
		// 中间值为1确认继承，为2则不继承，进行重新设置

		switch (eafk) {
		case 1:
			eaf = 0;
			eafk = 0;
			break;
		case 2:
			eaf = 0;
			eafk = 0;
			cout << "请输入您选择的难度（1简单，2困难）：";
			cin >> e;
			cout << "请输入您挑战的最大有效值（范围3——99）：";
			cin >> a;
			break;
		default:
			break;
		}
	}

	// 设置数据有效性判断

	while (a < 3) {
		cout << "错误，请注意最小有效值为3！" << endl;
		cout << "请重新输入您挑战的最大有效值（范围3——99）：";
		cin >> a;
	}

	// 存储设置的值

	e0 = e;
	a0 = a;

	// 修正重要值

	i = 0;
	f = 0;
	ab = 0;
	c = 0;
	k = 0;

	// 提取密码
	// 依次从准备好的数组中提取密码，如果符合条件则进入密码数组，否则丢弃

	do {
		if (p[i] <= a) {
			pw[f] = p[i];
			f++;
		}
		i++;
	} while (f < 4);
	cout << "游戏准备完毕" << endl;

RE:			// 重新输入标记*

	fin = 0;

	// *****主 运 算 部 分*****
	// 建立do while循环，当fin大于0结束循环

	do	{

		// 游戏开始，首先输入猜想的四位密码，中间用空格隔开

		fine = 0;			// 复位值

		cout << "请输入密码（一共四个数字，中间用空格隔开）：" << endl;

		// 首先进行游戏代码判断
		// 单独读取第一位进行代码值判断，如果是游戏代码则执行对应操作，否则继续

		cin >> pwa[0];
		if (pwa[0] > 100) {
			switch (pwa[0])	{
			case 101:			// 直接输出密码
				cout << "密码为：" << pw[0] << "-" << pw[1] << "-" << pw[2] << "-" << pw[3] << endl;
				goto RE;			// 位于主运算开始前
			case 102:			// 直接结束游戏
				cout << "执行直接结束游戏！" << endl;
				goto END;			// 位于主运算do函数后
			case 103:			// 直接重开游戏
				cout << "即将执行直接重开游戏···" << endl;
				cout << "请问是否要继承该局游戏的设置？" << endl;
				cout << "（输入1确认继承，输入0放弃继承）" << endl;
				yu = 5;			// 中间值清除
				cin >> yu;
				
				// 继承判断

				if (yu == 1) {
					eaf = 1;
					yu = 5;
					cout << "执行重开游戏且继承设置！" << endl;
					goto ICE;			// 位于核心变量配置后
				}
				else {
					eaf = 0;
					yu = 5;
					cout << "执行直接重开游戏！" << endl;
					goto ICE;			// 位于核心变量配置后
				}
			case 104:			// 清除记录并重开(不可用)
				cout << "错误，该代码只能在游戏结束后使用" << endl;
				goto RE;			// 位于主运算开始前
			case 105:			// 启用辅助判断器
				cout << "启用辅助判断器！" << endl;

				// 输出提示，告知玩家启用辅助判断器可能带来的后果

				if (e == 2) {
					cout << "请注意：困难难度启用辅助判断器将会破坏困难难度规则！" << endl;
					cout << "输入106代码可关闭辅助判断器" << endl;
				}
				ab = 1;
				goto RE;			// 位于主运算开始前
			case 106:			// 停用辅助判断器

				// 如果辅助判断器处于开启状态执行该代码则停用辅助判断器

				if (ab == 1) {
					cout << "执行停用辅助判断器！" << endl;
					ab = 0;
				}
				goto RE;			// 位于主运算开始前
			case 107:			// 输出当前游戏设置
				cout << "当前游戏难度：";
				if (e == 1) {
					cout << "简单" << endl;
				}
				else {
					cout << "困难" << endl;
				}
				cout << "当前有效值范围：0——" << a << endl;
				cout << "辅助判断器状态：";
				if (ab == 1) {
					cout << "开启" << endl;
				}
				else {
					cout << "关闭" << endl;
				}
				goto RE;			// 位于主运算开始前
			case 108:			// 直接重开游戏且继承上一局游戏设置
				cout << "执行直接重开游戏且继承上一局游戏设置" << endl;
				eaf = 1;
				goto ICE;			// 位于核心变量配置后
			default:
				break;
			}
		}
		cin >> pwa[1] >> pwa[2] >> pwa[3];
		cout << "请确认您的输入（输入1确认结果，输入2重新输入）" << endl;
		cout << pwa[0] << "-" << pwa[1] << "-" << pwa[2] << "-" << pwa[3] << endl;
		k = 0;
		cin >> k;

		// 输出结果确认，避免因失误输错数字浪费次数

		switch (k) {
		case 1:
			k = 0;
			break;
		case 2:
			k = 0;
			goto RE;			// 位于主运算开始前
		default:
			break;
		}
		c++;			// 当确认输入的结果后增加一次次数，然后进行密码判断
		cout << "您的输入结果：" << endl;
		cout << pwa[0] << "-" << pwa[1] << "-" << pwa[2] << "-" << pwa[3] << endl;

		// 根据值进行结果输出

		if (e == 1) {			// 简单难度
			
			// 密码判断

			for (i = 0; i < 4; i++) {
				if (pwa[i] == pw[0]) {			// 如果值与一号位相同，判断位置是否也相同
					if (i == 0) {			// 如果位置也相同则输出“V”
						cout << "V";
						fine++;
					}
					else {			// 位置不同则输出“Y”
						cout << "Y";
					}
				}
				if (pwa[i] == pw[1]) {			// 如果值与二号位相同，判断位置是否也相同
					if (i == 1) {			// 如果位置也相同则输出“V”
						cout << "V";
						fine++;
					}
					else {			// 位置不同则输出“Y”
						cout << "Y";
					}
				}
				if (pwa[i] == pw[2]) {			// 如果值与三号位相同，判断位置是否也相同
					if (i == 2) {			// 如果位置也相同则输出“V”
						cout << "V";
						fine++;
					}
					else {			// 位置不同则输出“Y”
						cout << "Y";
					}
				}
				if (pwa[i] == pw[3]) {			// 如果值与四号位相同，判断位置是否也相同
					if (i == 3) {			// 如果位置也相同则输出“V”
						cout << "V";
						fine++;
					}
					else {			// 位置不同则输出“Y”
						cout << "Y";
					}
				}
				if (pwa[i] != pw[0] && pwa[i] != pw[1] && pwa[i] != pw[2] && pwa[i] != pw[3]) {
					cout << "X";			// 如果值与正确密码中的任何一个都对不上，输出“X”
				}
			}
		}
		else {			// 困难难度
			ha1 = 0;
			ha2 = 0;
			for (i = 0; i < 4; i++) {
				if (pwa[i] == pw[i]) {
					ha2++;			// 首先判断是否存在完全正确的情况，有则ha2的值+1
				}
				else {
					if (pwa[i] == pw[0] || pwa[i] == pw[1] || pwa[i] == pw[2] || pwa[i] == pw[3]) {
						ha1++;			// 其次判断是否存在值相等的情况，有则ha1的值+1
					}
				}
			}
			if (ha2 > 0) {

				// 如果存在完全正确的情况，先输出对应数量的“V”

				for (i = 0; i < ha2; i++) {
					cout << "V";
				}

				// 如果同时存在值相等的情况，再输出对应数量的“Y”

				for (i = 0; i < ha1; i++) {
					cout << "Y";
				}

				// 最后用“X”补全

				for (i = 0; i < (4 - ha1 - ha2); i++) {
					cout << "X";
				}

				// 当完全正确的值的数量为4时结束游戏

				if (ha2 == 4) {
					fine = 4;
				}
			}
			else {

				// 如果没有完全正确的值，根据存在值相等的情况的数量直接输出对应结果

				switch (ha1) {
				case 0:
					cout << "XXXX" << endl;
					break;
				case 1:
					cout << "YXXX" << endl;
					break;
				case 2:
					cout << "YYXX" << endl;
					break;
				case 3:
					cout << "YYYX" << endl;
					break;
				default:
					cout << "YYYY" << endl;
					break;
				}
			}
		}

		// 判断游戏是否符合结束条件，如不符合再进行后续输出

		if (fine == 4) {
			fine = 0;
			fin++;
		}
		else {
			cout << "\n解释：V表示该位置数字完全正确；X表示密码中不包含该数字；" << endl;
			cout << "Y表示密码中包含该数字但位置不正确" << endl;

			// 辅助判断器

			if (ab == 1) {
				for (i = 0; i < 4; i++) {
					if (pwa[i] == pw[0] || pwa[i] == pw[1] || pwa[i] == pw[2] || pwa[i] == pw[3]) {
						cout << "=";			// 首先判断是否存在值相等的情况
					}
					else {

						// 其次判断偏大偏小

						if (pwa[i] > pw[i]) {
							cout << ">";
						}
						else {
							cout << "<";
						}
					}
				}
				cout << "（辅助判断结果）" << endl;
				cout << "辅助判断说明：=表示该位置与密码中的某一个数值相等" << endl;
			}
		}
	} while (fin == 0);

END:			// 游戏结束标记*

	// 游戏结束，进行结算
	// 如果游戏是直接结束的（fin值仍然为0），不反馈次数

	if (fin == 0) {
		cout << "游戏结束" << endl;
		cout << "正确密码为：";
		cout << pw[0] << "-" << pw[1] << "-" << pw[2] << "-" << pw[3] << endl;
	}
	else {
		cout << "\n游戏结束!正确密码为：";
		cout << pw[0] << "-" << pw[1] << "-" << pw[2] << "-" << pw[3] << endl;
		cout << "本次破解密码您一共花了" << c << "次" << endl;
	}
	cout << "输入103重开游戏，输入104清除记录并重开" << endl;
	int x = 0;
	int xl = 5;
	cin >> x;

	// 继承判断

	if (x == 103) {
		cout << "请问是否要继承该局游戏的设置？" << endl;
		cout << "（输入1确认继承，输入0放弃继承）" << endl;
		cin >> xl;
		if (xl == 1) {
			eaf = 1;
			xl = 5;
			cout << "执行重开游戏且继承设置！" << endl;
			goto ICE;			// 位于核心变量配置后
		}
		else {
			eaf = 0;
			xl = 5;
			cout << "执行直接重开游戏！" << endl;
			goto ICE;			// 位于核心变量配置后
		}
	}

	// 清除控制台

	if (x == 104) {
		system("cls");			// 清空控制台
		cout << "\n执行清除记录并重开游戏！" << endl;
		goto ICE;			// 位于核心变量配置后
	}
	return 0;
}

# 目录

- [使用教程](#use)
- [具体解析](#explain)
    - [numberfinding / 数轴探宝](#numberfinding)
    - [passwordcracking / 密码破解](#passwordcracking)
    - [wateroverflow / 倒水挑战](#wateroverflow)
- [使用说明及其他你应该知道的](#youknow)

<a id="use"></a>
# 使用教程

想要在自己的电脑上使用这些游戏很简单，只需要在Visual Studio上自己新建一个新项目，然后将代码复制粘贴进去即可。

> [!NOTE]
> * 如果你问其他工具是否可以？
> 
> 至少我没用过。理论上，只要能编译运行C语言或C++代码应该都可以，不过Visual Studio应该是比较简单的一个方案，因为他会帮你准备好必要的依赖，而在像VSCode的地方，需要自行处理依赖。

<a id="explain"></a>
# 具体解析

<a id="numberfinding"></a>
## numberfinding / 数轴探宝

原名：numberboom，数字炸弹。

正如原名，该游戏是参考“数字炸弹”做的小游戏。最初的一代版本1:1还原了数字炸弹原游戏（不过是在控制台中），后来的版本增加了一些全新的功能，4.0版本开始改名“numberfinding（数轴探宝）”。

其中，一代、二代、三代、四代均为C语言代码，第五代开始改用C++。

* 简要介绍

类似于扫雷，在1-100的范围内有一个宝藏（炸弹），你的目的是找到宝藏，但要避免触发和宝藏放在一起的炸弹。中途你可能遇到各种机关，其中包括了能不让炸弹爆炸的开关。

* 具体介绍

<details>
    <summary>第一代-点击展开</summary>

g

</details>

<details>
    <summary>第二代-点击展开</summary>

    g

</details>

<details>
    <summary>第三代-点击展开</summary>

    g

</details>

<details>
    <summary>第四代-点击展开</summary>

    g

</details>

<details>
    <summary>第五代-点击展开</summary>

    g

</details>

<a id="passwordcracking"></a>
## passwordcracking / 密码破解

参考玩具“超级密码机”制作的游戏。

其中，一代、二代为C语言代码，第三代开始改用C++。

* 简要介绍

游戏会根据你设定的数字范围挑选四个数字作为密码，你需要通过多次尝试并根据反馈的结果推断出正确密码，猜出则游戏结束。

游戏包含两种难度：简单、困难。简单难度下，反馈的结果会与位置对应，你能够得知具体每一个位置的对应结果（不是、包含、正确）；与之相对应的困难难度是只会反馈你输入的四位数字包含哪些情况，具体对应什么位置需要你自己猜测分析判断。

* 具体介绍

<details>
    <summary>第一代-点击展开</summary>

    g

</details>

<details>
    <summary>第二代-点击展开</summary>

    g

</details>

<details>
    <summary>第三代-点击展开</summary>

    g

</details>

<a id="wateroverflow"></a>
## wateroverflow / 倒水挑战

参考“由多个人依次上前按按钮，一个人一次可以按多次按钮，导致与按钮连接的炸弹爆炸的人失败”这样的小游戏制作的游戏，不过把按按钮改成了倒水。

游戏包含C++版本和借助deepseek制作的网页版（包括人工二次微调版）。

* 简要介绍

有一个空的大水杯和一个带有刻度的小水杯，你需要用小水杯往大水杯里倒水，导致水溢出的为失败者。

* 具体介绍

> [!NOTE]
> 借助deepseek制作的网页版（包括人工二次微调版）特性同一代，故不做具体单独介绍。

<details>
    <summary>第一代-点击展开</summary>

    g

</details>

<details>
    <summary>第二代-点击展开</summary>

    待开发。

    预计包含特性：新增初始水量。

</details>

<a id="youknow"></a>
# 使用说明及其他你应该知道的

该项目中包含的代码均为**净化之子凌柃Icefair**个人参考对应的小游戏独立设计开发的。

既然已经选择开源，那么我不再设置任何使用限制，你可以自由使用。

如果你想要联系我，可以在B站搜索“**净化之子凌柃**”，如果你想要在Discord、X/Twitter等的地方找到我，请认准“**@jhicefair**”！

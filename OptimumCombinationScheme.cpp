/*
动态规划之取最优解
	给一组数据，要求取出加起来能组合出的最大数，
	不能去相邻的两个数，取数数量不限

	思想：自底向上
		先把前面的最优解求出来，存在两个状态，选和不选，
		如果选的话，他的前一个就不能选，所以值为本身加上第前两个的最优解
		如果不选择的话，就取前面一个的最优解，两种方式求出取最大值就是取到现在的下标的最优解
*/
/***************************************************************************************************************************************************************************/
/*
	常量CLOCKS_PER_SEC，它用来表示一秒钟会有多少个时钟计时单元
	这个函数返回从“开启这个程序进程”到“程序中调用clock()函数”时之间的CPU时钟计时单元（clock tick）数，在MSDN中称之为挂钟时间（wal-clock）。

	引入：计算程序时间函数 clock()  对应类型 clock_t  头文件ctime
	用法：程序开始调用一次保存，结束调用一次保存再进行计算（尾-头）/CLOCKS_PER_SEC
*/

/***************************************************************************************************************************************************************************/

/*

	cin输入外挂 std::ios::sync_with_stdio(false)  

	c++中我们通常采用std::cin来读入外部数据，而C++中为了能向下兼容C，保证在代码中std :: cin和scanf一起出现时输出不出现错误，
	所以C++用一个流缓冲区来同步C的标准流。我们可以通过std :: ios :: sync_with_stdio函数可以解除这种同步，让std :: cin不再经过缓冲区
	，从而达到增加数据读取速度的目的，来减少代码执行时间。当然，关闭同步后，在程序中尽量不要使用c语言中的scanf，sscanf, getchar, fgets等函数，以免出现错误。

	测试：在运算量小的程序里差别只是0.0001精度，但是依然快了，只是要避免scanf等的重用出现未知的输出
*/
/***************************************************************************************************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
//解除stdio同步绑定(lambda表达式直接调用)
static const auto io_sync_off = [] {
	//取消绑定
	ios::sync_with_stdio(false);
	//解除cin和cout的绑定
	cin.tie(nullptr);
	return nullptr;
}();

auto opt(const vector<int> &v)
{
	vector<int> opti(v.size(), 1);
	if (v[1] > v[0])
		opti[1] = v[1];
	else
		opti[1] = v[0];

	for (int i = 2; i < v.size(); ++i)
	{
		opti[i] = max(opti[i - 1], v[i] + opti[i - 2]);
	}

	return opti;
}

int main()
{
	clock_t begin, end;
	//开始计算
	begin = clock();

	vector<int> v{ 1,2,4,1,7,8,3 };

	vector<int> s = opt(v);
	for (auto value : s)
	{
		cout << value << "\t";
	}
	cout << endl;

	//加大程序运算时间
	for (double long  i = 0; i < LONG_MAX; i++)
	{

	}

	//结束
	end = clock();
	//计算,时间可能很小，用double显示出来
	cout <<(double) (end - begin) / CLOCKS_PER_SEC<<endl;
	system("pause");
	return 0;
}
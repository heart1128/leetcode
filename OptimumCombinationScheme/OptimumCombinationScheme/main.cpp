/*
动态规划之取最优解
	给一组数据，要求取出加起来能组合出的最大数，
	不能去相邻的两个数，取数数量不限

	思想：自底向上
		先把前面的最优解求出来，存在两个状态，选和不选，
		如果选的话，他的前一个就不能选，所以值为本身加上第前两个的最优解
		如果不选择的话，就取前面一个的最优解，两种方式求出取最大值就是取到现在的下标的最优解
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
	vector<int> v{ 1,2,4,1,7,8,3 };

	vector<int> s = opt(v);
	for (auto value : s)
	{
		cout << value << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}
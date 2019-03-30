/*

	动态规划经典例题《求最优解》
		一个人做临时工，有个临时工表，求出他最多能赚的钱是多少
		时间上不能重叠
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int auxiliary(map<int,vector<int>> m,int n)
{
	for (int i = m.size()-1; i>=0; --i)
	{
		if (m[i][1] == m[n][0])
			return i;
	}
	return -1;
}

auto opt(map<int,vector<int>> m)
{
	vector<int> opti;
	opti.resize(m.size());
	fill(opti.begin(), opti.end(), 0);
	opti[0] = m[0][2];

	for (size_t i = 1; i < m.size(); ++i)
	{
		int n;
		if ((n = auxiliary(m, i)) == -1)
			n = 0;
		else
			n = opti[n];
		opti[i] = max(opti[i - 1], n +m[i][2]);
	}
	return opti;
}


int main()
{
	map<int, vector<int>> m;
	//m[i][0]是开始的时间
	//m[i][1]是结束的时间
	//m[i][2]是工资
	m[0].push_back(1);
	m[0].push_back(4);
	m[0].push_back(5);

	m[1].push_back(3);
	m[1].push_back(5);
	m[1].push_back(1);

	m[2].push_back(0);
	m[2].push_back(6);
	m[2].push_back(8);

	m[3].push_back(4);
	m[3].push_back(7);
	m[3].push_back(4);

	m[4].push_back(3);
	m[4].push_back(8);
	m[4].push_back(6);

	m[5].push_back(5);
	m[5].push_back(9);
	m[5].push_back(3);

	m[6].push_back(6);
	m[6].push_back(10);
	m[6].push_back(2);

	m[7].push_back(8);
	m[7].push_back(11);
	m[7].push_back(4);
	vector<int> v = opt(m);

	for (auto value : v)
	{
		cout << value << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}
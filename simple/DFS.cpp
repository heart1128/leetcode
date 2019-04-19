#include<iostream>
#include<array>
#include<algorithm>
using std::array;
#define LEN 9

class sudoku {
public:
	bool flag;
	array<array<int, LEN>, LEN> sd;
	//初始化数组
	sudoku(int a[][LEN])
	{
		flag = false;
		for (int i = 0; i < LEN; i++)
			for (int j = 0; j < LEN; j++)
			{
				sd[i][j]=a[i][j];
			}
	}
	//判断是否可填
	bool judge(int n,int tag)
	{
		int h = n / LEN;
		int l = n % LEN;
		//判断行,列重复
		for (int i = 0; i < LEN; i++)
		{
			if (sd[h][i] == tag || sd[i][l] == tag)
				return false;
		}

		//判断属于j的3*3方格是否重复
		int x = n / 9 / 3 * 3;
		int y = n % 9 / 3 * 3;
		for (int i = x; i < x + 3; i++)
			for (int j = y; j < y + 3; j++)
			{
				if (sd[i][j] == tag)
					return false;
			}

		return true;
	}
	//DFS深搜递归查找
	void DFS(int n)
	{
		//递归结束标志
		if (n > 80)
		{
			flag = true;
			return;
		}

		//如果不为0就不用填了
		if (sd[n / LEN][n % LEN] != 0)
		{
			DFS(n + 1);
		}

		else
		{ 
			for (int i = 1; i < LEN+1; i++)
			{
				if (judge(n, i))
				{
					//可以构造，构造后往下一个走
					sd[n / 9][n % 9] = i;
					DFS(n + 1);

					//如果是填好了的直接返回
					if (flag)return;
					//如果构造不成功则回溯还原
					sd[n / 9][n % 9] = 0;
				}
			}
		}
	}
	//打印填好的数独
	void print()
	{
		int count = 0;
		for (const auto value : sd)
		{
			for (const auto n : value)
			{
				std::cout << n <<" ";
				count++;
				if (count % 3 == 0)
					std::cout << "\t";
			}
			std::cout << std::endl;
			if (count % (LEN*3) == 0)
				std::cout << std::endl;
		}
	}
};

int main()
{
	int b[][LEN] = { 8, 0 ,0 ,0 ,0 ,0 ,0, 0, 1,
					 9, 0 ,0 ,0 ,2 ,0 ,0 ,0 ,3,
					 0, 3, 0, 0, 5, 0, 0, 7, 0,
					 0, 0, 5, 0, 0, 0, 4, 0, 0,
					 0, 0, 4, 5, 0, 9, 6, 0, 0,
					 0, 0, 0, 8, 0, 1, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 4, 6, 0, 0, 0, 8, 2, 0,
					 0, 2, 0, 3, 0, 5, 0, 9, 0, };
	sudoku a(b);
	a.DFS(0);
	a.print();
	system("pause");
	return 0;
}/*8 0 0 0 0 0 0 0 1
9 0 0 0 2 0 0 0 3
0 3 0 0 5 0 0 7 0
0 0 5 0 0 0 4 0 0
0 0 4 5 0 9 6 0 0
0 0 0 8 0 1 0 0 0
0 0 0 0 0 0 0 0 0
0 4 6 0 0 0 8 2 0
0 2 0 3 0 5 0 9 0*/
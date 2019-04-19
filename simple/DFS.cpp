#include<iostream>
#include<array>
#include<algorithm>
using std::array;
#define LEN 9

class sudoku {
public:
	bool flag;
	array<array<int, LEN>, LEN> sd;
	//��ʼ������
	sudoku(int a[][LEN])
	{
		flag = false;
		for (int i = 0; i < LEN; i++)
			for (int j = 0; j < LEN; j++)
			{
				sd[i][j]=a[i][j];
			}
	}
	//�ж��Ƿ����
	bool judge(int n,int tag)
	{
		int h = n / LEN;
		int l = n % LEN;
		//�ж���,���ظ�
		for (int i = 0; i < LEN; i++)
		{
			if (sd[h][i] == tag || sd[i][l] == tag)
				return false;
		}

		//�ж�����j��3*3�����Ƿ��ظ�
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
	//DFS���ѵݹ����
	void DFS(int n)
	{
		//�ݹ������־
		if (n > 80)
		{
			flag = true;
			return;
		}

		//�����Ϊ0�Ͳ�������
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
					//���Թ��죬���������һ����
					sd[n / 9][n % 9] = i;
					DFS(n + 1);

					//���������˵�ֱ�ӷ���
					if (flag)return;
					//������첻�ɹ�����ݻ�ԭ
					sd[n / 9][n % 9] = 0;
				}
			}
		}
	}
	//��ӡ��õ�����
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
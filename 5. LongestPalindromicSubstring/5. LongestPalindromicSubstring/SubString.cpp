#include <iostream>
#include <string>
using namespace std;
//中间分割法
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() == 1)
			return s;

		int head = 0, tail = 0;
		for (size_t i = 0; i < s.size(); ++i)
		{
			//这里是检查奇数长度的
			int len1 = strLenth(s, i, i);
			//这里检查偶数长度的,因为中间是空的
			int len2 = strLenth(s, i, i + 1);
			//哪个长度大就取哪个
			int len = len1 > len2 ? len1 : len2;
			if (len > tail - head)
			{
				head = i - (len - 1) / 2;
				tail = i + len / 2;
			}
		}
		return s.substr(head, tail - head + 1);
	}

	int strLenth(string s, int left, int right)
	{
		int L = left, R = right;
		while ((L >= 0 && R < s.size()) && s[L] == s[R])
		{
			L--;
			R++;
		}

		return R - L - 1;
	}
};

int main()
{
	Solution a;
	string str;
	cin >> str;
	cout << a.longestPalindrome(str) << endl;
	system("pause");
	return 0;
}
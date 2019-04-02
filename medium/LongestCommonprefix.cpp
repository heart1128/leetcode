/*
	2019/4/1

	难度：简单
	Leetcode14.求最长公共前缀

	思路：这里用二分法做，时间复杂度O(S*log(n))
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
static const auto io_sync_off = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";

		auto it = *(min_element(strs.begin(), strs.end()));

		int index;
		int L = 1;
		int R = it.size();
		//通过二分如果左边有相同的就跑到右边去
		while (L<=R)
		{
			index = (L +R) / 2;
			if (isEqual(strs, index))
				L = index + 1;
			else
				R = index - 1 ;
		}
		return strs[0].substr(0, (L + R) / 2);
	}

	bool isEqual(vector<string> &strs, size_t index)
	{
		string str = strs[0].substr(0, index);
		for (int i = 0; i < strs.size(); ++i)
		{
			if (strs[i].substr(0, index) != str)
				return false;
		}
		return true;
	}
};

int main()
{
	vector<string> v{ "s7ower","flow","flowt" };
	Solution a;
	cout<<a.longestCommonPrefix(v)<<endl;
	system("pause");
	return 0;
}

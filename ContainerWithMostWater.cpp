/*
		动态规划之求解最大面积

		给一个数组，里面的数组分别代表围墙的高度

			  |-|													|	|
			  |  |   *************						|	|
		|-|  |  |													|	|
		————————————————————————
		求出能围成最大的面积是多少

		思路：
				问题只是要求出最大的面积，先求最远的两堵墙的面积
				再比较两堵墙的高度，谁小就往里缩，最后取每次算的
				最大值
				时间复杂度O(n)
				空间复杂度O(n)
*/



#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int maxArea(const vector<int>& height) {
		int maxValue = 0;
		int L = 0, R = height.size() - 1;

		while (L < R)
		{
			maxValue = max(maxValue, (R - L)*min(height[R], height[L]));
			if (height[R] > height[L])
				L++;
			else
				R--;
		}
		return maxValue;
	}
};
int main()
{
	vector<int> v{1,2,4,3};
	Solution a;
	cout << a.maxArea(v) << endl;
	system("pause");
	return 0;
}
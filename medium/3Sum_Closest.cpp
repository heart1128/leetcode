/*
	LeetCode 16最接近的三数之和
	给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

 思路：
 方法和求3sum一样，都是先排序,然后用双指针一头一尾遍历，
 不过这里是求距离最小,就把距离最小的绝对值保存下来就行
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() == 3)
			return nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());

		int n = nums[0] + nums[1] + nums[2], sum;
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int L = i + 1;
			int R = nums.size() - 1;

			while (L < R)
			{
				sum =nums[i] + nums[L] + nums[R];
				//先把每次绝对值比较下，把小的留着
				if (abs(sum - target) < abs(n - target))
					n = sum;
				if (sum >target)
					R--;
				else if (sum < target)
				{
					L++;
					while (L < nums.size() - 1 && nums[L] == nums[L + 1])
						L++;
				}
				else
					return sum;
			}
			while (i < nums.size() - 1 && nums[i] == nums[i + 1])
				i++;
		}
		return  n;
	}
};

int main()
{
	vector<int> v{ 1,1,1,0 };
	Solution a;
	cout<<a.threeSumClosest(v,100 ) << endl;
	system("pause");
	return 0;
}
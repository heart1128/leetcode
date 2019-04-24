/*
	LeetCode 14 4数之和、
	给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
注意：
答案中不可以包含重复的四元组。
示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

思路: 对于n(n > 2)数之和  先每层循环减少为n-1数之和,直到2数之和，用双指针进行滑动检测,其中可以设定条件去重
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static const auto io_sync_off = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4)return {};

		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < nums.size() - 3; ++i)
		{
			//这个和前一个相同就不用比较了,一样的结果
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			//优化版
			//因为数组是拍好序的,如果前前四个最小的四个数都大于他，肯定就没有能组合的数了
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
				break;
			//如果当前的和最后三个最大的都比他小,就直接往下走i++
			if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
				continue;

			//temp1现在是三数之和
			int temp1 = target - nums[i];
			for (int j = i + 1; j < nums.size() - 2; ++j)
			{
				//同上
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;

				//优化版
				//因为数组是拍好序的,如果前前四个最小的四个数都大于他，肯定就没有能组合的数了
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
					break;
				//如果当前的和最后两个最大的都比他小,就直接往下走j++
				if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
					continue;

				//temp2现在是双数之和
				int temp2 = temp1 - nums[j];
				//L R 进行滑动搜索,因为之前排序了,两端开始滑动
				int L = j + 1, R = nums.size() - 1;
				while (L < R)
				{
					//去除不符合的数
					if (R > L && nums[L] + nums[R] > temp2)
						R--;
					//同上
					if (L < R && nums[L] + nums[R] < temp2)
						L++;
					//有符合的,加入vector,再移动一次
					if (R != L && nums[L] + nums[R] == temp2)
					{
						res.push_back({ nums[i],nums[j],nums[L],nums[R] });
						//同样对已保存的数去重
						while (L < R && nums[L] == nums[L + 1])
							L++;
						while (L < R && nums[R] == nums[R - 1])
							R--;

						L++;
						R--;
					}
				}
			}
		}
		return res;
	}
};

int main()
{
	vector <int> v{ 1, 0, -1, 0, -2, 2 };
	Solution s;
	vector<vector<int>> v1 = s.fourSum(v, 0);
	for (auto values : v1)
	{
		cout << "[";
		for (auto value : values)
		{
			cout << value << ",";
		}
		cout << "]" << endl;
	}
	system("pause");
	return 0;
}
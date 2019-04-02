/*

	3Sum(KSum) 
	描述：
	给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
	注意：答案中不可以包含重复的三元组。
	例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

	满足要求的三元组集合为：
	[
	 [-1, 0, 1],
	[-1, -1, 2]
	]

	解法：
			 先排序数组，这样就有规律可寻，
			 给定两个移动下标，一个当前可用最大，一个为当前可用最小,如果三数加起来大于0，那就是R太大，往小的移,Ld的相反
			 如果判定到相等的,加入数组，然后最重要的去重，一直往下一个比较，如果相等就不用比较的，
			 最后给最外层去重，同样的方法

			 关于KSum的解，都是类似的方法
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
static const auto io_sync_off = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> v;
		if (nums.size() < 3)
			return v;

		int len = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len - 2; ++i)
		{
			if (nums[i] > 0)
				break;
			int L = i + 1;
			int R = len - 1;
			while (L < R)
			{
				if (nums[i] + nums[L] + nums[R] > 0)
					R--;
				else if (nums[i] + nums[L] + nums[R] < 0)
					L++;
				else
				{
					v.push_back({ nums[i],nums[L] ,nums[R]});
					while (L+1 < len && nums[L] == nums[L + 1]) L++;
					L++;
				}
			}
			while (i+1 < len && nums[i] == nums[i + 1])
				i++;
		}
		return v;
	}
};
int main()
{
	clock_t begin, end;
	begin = clock();
	vector<int> v{2,41,45,5,5,0,4,0,4, -4,5,-1,-21,-4,-5,5,1,0};
	Solution a;
	auto it = a.threeSum(v);
	for (auto array : it)
	{
		cout << "[";
		for (auto value : array)
		{
			cout << value << ",";
		}
		cout << "]" << endl;
	}
	end = clock();
	cout << "用时" << (begin - end) / CLOCKS_PER_SEC << "\n";
	system("pause");
	return 0;
}
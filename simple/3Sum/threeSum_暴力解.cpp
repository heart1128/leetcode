/*

		LeetCode 3Sum:
		暴力超时代码

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static const auto io_sync_off = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> v;
		if (nums.size() < 3)
			return v;
		if (nums.size() == 3 && (nums[0] + nums[1] + nums[2]) != 0)
			return v;
		else if (nums.size() == 3 && nums[0] + nums[1] + nums[2] == 0)
		{
			v.push_back(nums);
			return v;
		}
		
		for (size_t i = 0; i < nums.size(); ++i)
		{
			for (size_t j = i + 1; j < nums.size(); ++j)
			{
					int n = 0 - nums[i] - nums[j];
					vector<int> temp{ n,nums[i],nums[j] };
					sort(temp.begin(), temp.end());
					auto it = find(v.begin(), v.end(), temp);
					if (middle(nums, n,i,j) && it == v.end())
					{
						v.push_back(temp);
					}
			}
		}
		return v;
	}

	bool middle(vector<int>& nums, int n,int i,int j)
	{
		int L = 0;
		int R = nums.size() - 1;
		while (L <= R)
		{
			int mid = (R + L) / 2;
			if (mid != i && mid != j && n == nums[mid])
				return true;
			if (n > nums[mid])
				L = mid + 1;
			else
				R = mid - 1;
		}

		return false;
	}
};
int main()
{
	vector<int> v{10,-2,-12,3,-15,-12,2,-11,3,-12,9,12,0,-5,-4,-2,-7,-15,7,4,-5,-14,-15,-15,-4,10,9,-6,7,1,12,-6,14,-15,12,14,10,0,10,-10,3,4,-12,10,7,-9,-7,-15,-8,-15,-4,2,9,-4,3,-10,13,-3,-1,5,5,-4,-15,4,-11,4,-4,6,-11,-9,12,7,11,7,2,-5,13,10,-5,-10,3,7,0,-3,10,-12,2,9,-8,8,-9,13,12,13,-6,8,3,5,-9,7,12,10,-8,0,2,1,10,-7,-3,-10,-10,7,4,5,-11,-8,0,-2,-14,8,13,-8,-2,10,13 };
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
	system("pause");
	return 0;
}
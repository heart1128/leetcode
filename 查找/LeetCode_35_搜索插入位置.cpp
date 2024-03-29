/*
LeetCode 查找插入位置 
 
	给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
你可以假设数组中无重复元素。
示例 1:
输入: [1,3,5,6], 5
输出: 2
示例 2:
输入: [1,3,5,6], 2
输出: 1
示例 3:
输入: [1,3,5,6], 7
输出: 4
示例 4:
输入: [1,3,5,6], 0
输出: 0

//在二分查找基础上多了一个判断插入位置的if 
*/ 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int L = 0;
		int R = nums.size() - 1;
		int mid = (L + R) / 2;

		if (target < nums[0])
			return 0;
		if (target > nums[R])
			return R + 1;

		while (L <= R)
		{
			mid =(L + R) / 2;
			//因为二分mid是向下取整的,所以最后一次找不到匹配的值时,下标就会比要插入的位置小1 
			if (L == R && nums[mid] < target)
			{
				mid++;
				break;
			}
			if (nums[mid] > target)
				R = mid - 1;
			else if (nums[mid] < target)
				L = mid + 1;
			else
				break;
		}
		return mid;
	}
};
int main()
{
	vector<int> v{ 1,4,7,9};
	Solution s;
	cout << s.searchInsert(v,8)<<endl;
	system("pause");
	return 0;
}

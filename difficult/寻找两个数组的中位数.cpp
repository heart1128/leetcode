/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       for (auto b : nums1)
		{
			auto it = std::lower_bound(nums2.begin(), nums2.end(), b)-nums2.begin();
			nums2.insert(nums2.begin()+it, b);
		}
		if (nums2.size() % 2 == 0)
		{
			auto mid = nums2.begin() + nums2.size() / 2;
			return (*mid + *(mid - 1)) / 2.0;
		}
		else
		{
			auto mid = nums2.begin() + nums2.size() / 2;
			return *mid;
		}
    }
};
int main()
{
	Solution a;
	vector<int> v1{1,3};
	vector<int> v2{2};
	cout<<a.findMedianSortedArrays(v1,v2)<<endl;
	return 0;
}

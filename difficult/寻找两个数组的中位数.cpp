/*
����������СΪ m �� n ���������� nums1 �� nums2��
�����ҳ������������������λ��������Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(log(m + n))��
����Լ��� nums1 �� nums2 ����ͬʱΪ�ա�
ʾ�� 1:
nums1 = [1, 3]
nums2 = [2]

����λ���� 2.0
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

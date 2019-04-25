/*
LeetCode ���Ҳ���λ�� 
 
	����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
����Լ������������ظ�Ԫ�ء�
ʾ�� 1:
����: [1,3,5,6], 5
���: 2
ʾ�� 2:
����: [1,3,5,6], 2
���: 1
ʾ�� 3:
����: [1,3,5,6], 7
���: 4
ʾ�� 4:
����: [1,3,5,6], 0
���: 0

//�ڶ��ֲ��һ����϶���һ���жϲ���λ�õ�if 
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
			//��Ϊ����mid������ȡ����,�������һ���Ҳ���ƥ���ֵʱ,�±�ͻ��Ҫ�����λ��С1 
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

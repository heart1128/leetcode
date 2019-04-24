/*
	LeetCode 14 4��֮�͡�
	����һ������ n ������������ nums ��һ��Ŀ��ֵ target���ж� nums ���Ƿ�����ĸ�Ԫ�� a��b��c �� d ��ʹ�� a + b + c + d ��ֵ�� target ��ȣ��ҳ��������������Ҳ��ظ�����Ԫ�顣
ע�⣺
���в����԰����ظ�����Ԫ�顣
ʾ����
�������� nums = [1, 0, -1, 0, -2, 2]���� target = 0��

����Ҫ�����Ԫ�鼯��Ϊ��
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

˼·: ����n(n > 2)��֮��  ��ÿ��ѭ������Ϊn-1��֮��,ֱ��2��֮�ͣ���˫ָ����л������,���п����趨����ȥ��
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
			//�����ǰһ����ͬ�Ͳ��ñȽ���,һ���Ľ��
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			//�Ż���
			//��Ϊ�������ĺ����,���ǰǰ�ĸ���С���ĸ��������������϶���û������ϵ�����
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
				break;
			//�����ǰ�ĺ�����������Ķ�����С,��ֱ��������i++
			if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
				continue;

			//temp1����������֮��
			int temp1 = target - nums[i];
			for (int j = i + 1; j < nums.size() - 2; ++j)
			{
				//ͬ��
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;

				//�Ż���
				//��Ϊ�������ĺ����,���ǰǰ�ĸ���С���ĸ��������������϶���û������ϵ�����
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
					break;
				//�����ǰ�ĺ�����������Ķ�����С,��ֱ��������j++
				if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
					continue;

				//temp2������˫��֮��
				int temp2 = temp1 - nums[j];
				//L R ���л�������,��Ϊ֮ǰ������,���˿�ʼ����
				int L = j + 1, R = nums.size() - 1;
				while (L < R)
				{
					//ȥ�������ϵ���
					if (R > L && nums[L] + nums[R] > temp2)
						R--;
					//ͬ��
					if (L < R && nums[L] + nums[R] < temp2)
						L++;
					//�з��ϵ�,����vector,���ƶ�һ��
					if (R != L && nums[L] + nums[R] == temp2)
					{
						res.push_back({ nums[i],nums[j],nums[L],nums[R] });
						//ͬ�����ѱ������ȥ��
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
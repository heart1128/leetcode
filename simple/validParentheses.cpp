/*
	LeetCode 20 有效的括号
	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

	简单类型的题目,用一个栈保持顺序即可,但是可以不用保存左括号对右括号的关系
	这里()的ACSSl的值差1  其他两个括号的差2
	利用这一特性,
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
static const auto io_sysn_off = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();

class Solution {
public:
	bool isValid(string s) {
		if (s.empty())
			return true;
		if (s[0] == ')' || s[0] == ']' || s[0] == '}')
			return false;

		stack<int> v;
		for (auto value : s)
		{
			if (v.empty())
				v.push(value);
			//这里()的ACSSl的值差1  其他两个括号的差2，有就匹配成功，出栈
			else if (value - 2 == v.top() || value - 1 == v.top())
				v.pop();
			else
				v.push(value);
		}
		if (v.empty())
			return true;
		return false;
	}
};

int main()
{
	string str;
	cin >> str;
	Solution a;
	if (a.isValid(str))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	system("pause");
	return 0;
}
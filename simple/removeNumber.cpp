#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static const auto io_sysn_off = [](){
	cin.tie(nullptr);
	return nullptr;
}();
class Soluth{
public:
	int removeNumber(vector<int>& v,int tag)
	{
		int n = count_if(v.begin(),v.end(),[&tag](int n)->bool{
			if(n == tag)
				return true;
			else
				return false;
		});
		remove(v.begin(),v.end(),tag);
		return v.size() - n;
	}
};
int main()
{
	int a[8] = {1,2,5,4,2,1,3,4};
	vector<int> v{1,2,5,4,2,1,3,4};
	Soluth A;
	int n = A.removeNumber(v,2);
	for(int i = 0;i<n;++i)
	{
		cout<<v[i]<<"\t";
	}
	cout<<endl;
	return 0;
}
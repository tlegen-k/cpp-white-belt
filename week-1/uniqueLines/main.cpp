#include <map>
#include <set>
#include <iostream>
using namespace std;

void PrintSetSize(const set<string>& dic)
{
	cout << dic.size() << endl;
}
int main()
{
	int q;
	cin >> q;
	set<string> dic;
	for (int i=0; i<q; ++i)
	{
		string s;
		cin >> s;
		dic.insert(s);

	}
	PrintSetSize(dic);
	return 0;
}

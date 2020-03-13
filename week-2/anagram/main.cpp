#include <map>
#include <string>
#include <iostream>

using namespace std;

map<char, int> BuildCharCounters(const string& word){
	map<char, int> result;
	for (auto x : word)
	{
		++result[x];
	}
	return result;
}
int main()
{
	int N;
	string first, second;
	cin >> N;
	for (int i=0; i<N; ++i)
	{
		cin >> first >> second;

		if (BuildCharCounters(first) == BuildCharCounters(second))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
return 0;
}

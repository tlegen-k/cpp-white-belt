#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v)
{
	vector<int> tmp={};
	int size = v.size();
	for (int i = size-1; i>=0; --i)
	{
		int x = v[i];
		tmp.push_back(x);
	}

	v = tmp;
}

int main()
{
	vector<int> numbers = {1, 5, 3, 4, 2};
	for ( auto x : numbers)
	{
		cout << x << " ";
	}

	Reverse(numbers);

	for ( auto x : numbers)
	{
		cout << x << " ";
	}
	return 0;
}

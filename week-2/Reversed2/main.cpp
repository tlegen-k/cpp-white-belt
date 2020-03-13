#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v)
{
	vector<int> tmp={};
	int size = v.size();
	for (int i = size-1; i>=0; --i)
	{
		int x = v[i];
		tmp.push_back(x);
	}
	return tmp;
}

int main()
{
	vector<int> numbers = {1, 5, 3, 4, 2};

	Reversed(numbers);

	return 0;
}

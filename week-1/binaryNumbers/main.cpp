#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> v = {};
	int N, N0, y;
	cin >> N;
	N0 = N;
	if (N>0)
	{
		while (N>0)
		{
			y = N%2;
			N /=2;
			if (N == N0/2 && y==0)
			{
				cout << "" << endl;
			}
			else
			{
				//cout << y;
			}
			v.push_back(y);
		}
	}
	for (int i=v.size()-1; i>=0; --i)
	{
		cout << v[i];
	}

	return 0;
}

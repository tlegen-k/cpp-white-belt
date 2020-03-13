#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A;
	for (int i=0; i<N; ++i)
	{

		int n;
		cin >> n;
		A.push_back(n);
	}
	sort(A.begin(), A.end(), [] (int i, int j) {
		return (abs(i)<abs(j));
	});
	for(auto& i : A)
	{
		cout << i << " ";
	}
	return 0;
}

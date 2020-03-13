#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N,x;
	vector<int> nums={};
	int sum = 0;
	cin >> N;

	for (int i=0; i < N; ++i)
	{
		cin >> x;
		nums.push_back(x);
		sum += nums[i];
	}

	int mean;
	mean = sum/N;

	int K;
	K=0;
	for (int i=0; i<N; ++i)
	{
		if (nums[i]>mean)
		{
			K += 1;
		}
		else
		{

		}
	}
	cout << K << endl;

	for (int i=0; i<N; ++i)
	{
		if (nums[i]>mean)
		{
			cout << i << " ";
		}
		else
		{

		}
	}
}

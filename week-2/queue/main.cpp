#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int Q;
	cin >> Q;

	vector<bool> input;
	string command;

	for (int i=0; i<Q; ++i)
	{
		int N,k;
		cin >> command;

		if (command == "COME")
		{
			cin >> N;
			if (N>0)
			{
				for (k=0; k<N; ++k)
				{
					input.push_back(false);
				}
			}
			else
			{
				for (k=N; k<0; ++k)
				{
					input.pop_back();
				}
			}
		}
		else if (command == "WORRY")
		{
			cin >> N;
			input[N]=true;
		}
		else if (command == "QUIET")
		{
			cin >> N;
			input[N]=false;
		}
		else if (command == "WORRY_COUNT")
		{
			k=0;
			for (auto x : input)
			{
				if (x == true)
				{
					k+=1;
				}

			}
			cout << k<< endl;
		}

	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	vector<vector<string>> chores(31);
	//define size of arrays equal to number of days
	vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int N, day;

	cin >> N;

	int month = 0;
	int nextCounter = 0; //counts next command usage number
	string command, chore;

	for (int i=0; i<N; ++i)
	{
		cin >> command;

		if (command == "ADD")
		{
			cin >> day >> chore;
			chores[day-1].push_back(chore);
		}

		else if (command == "DUMP")
		{
			cin >> day;
			cout << chores[day-1].size();
			for (auto x : chores[day-1])
			{
				cout << " " << x;
			}
			cout << endl;
		}

		else if (command == "NEXT")
		{
			if (nextCounter == 11)
			{
				month = 0;
				chores.resize(days[month]);
				nextCounter = 0;
			}
			else
			{
				int prev=days[month];
				int next=days[month+1];
				if (prev > next)
				{
					for (int k=next; k<=prev-1; ++k)
					{
						chores[next-1].insert(end(chores[next-1]), begin(chores[k]), end(chores[k]));

						//chores[next].push_back(chores[i]);
					}

					chores.resize(next);
				}
				else
				{
					chores.resize(next);
				}
				++month;
			++nextCounter;
			}
		}
	}
	return 0;
}

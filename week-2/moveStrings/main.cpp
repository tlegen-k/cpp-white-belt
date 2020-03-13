#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (auto x : source)
	{
		destination.push_back(x);
	}
	source.clear();
}

int main()
{
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};

	cout << "destination=";
	for (auto x: destination)
	{
		cout << x << endl;
	}

	cout << "source=";
	for (auto x: source)
		{
			cout << x << endl;
		}

	MoveStrings(source, destination);

	cout << "destination=";

	for (auto x: destination)
	{
		cout << x << endl;
	}

	cout << "source=";
	for (auto x: source)
		{
			cout << x << endl;
		}

	return 0;
}

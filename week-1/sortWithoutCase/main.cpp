#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string> S(N);
	for (string& x : S)
	{
		cin >> x;
	}

	sort(S.begin(), S.end(), [] (string first, string second) {
		int i=0;
		while (first[i])
			{
			first[i]=tolower(first[i]);
			++i;
			}
		i=0;
		while (second[i])
			{
			second[i]=tolower(second[i]);
			++i;
			}
		return (first < second);
	});

	for(auto& i : S)
	{
		cout << i << " ";
	}
	return 0;
}

#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	int q, val=1;
	cin >> q;
	map<vector<string>, int> routes;
	vector<string> bus_stops;

	for(int i=0; i<q; ++i)
	{
		int n;
		cin >> n;
		string bus_stop;
		for (int k=0; k<n; ++k)
		{
			cin >> bus_stop;
			bus_stops.push_back(bus_stop);
		}
		if (routes.count(bus_stops)==0)
		{
			routes[bus_stops]=val;
			cout << "New bus " << val << endl;
			val++;
		}
		else
		{
			cout << "Already exists for " << routes[bus_stops] << endl;
		}
		bus_stops.clear();
	}

	return 0;
}



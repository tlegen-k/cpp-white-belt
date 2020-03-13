#include <set>
#include <map>
#include <iostream>

using namespace std;

int main()
{
	int q;
	cin >> q;
	map<set<string>, int> bus_stops;
	set<string> stops;
	int num=1;
	for(int i=0; i<q; ++i)
	{
		string bus_stop;
		int n;
		cin >> n;
		for (int k=0; k<n; ++k)
		{
			cin >> bus_stop;
			stops.insert(bus_stop);
		}
		if (bus_stops.count(stops)==0)
		{
			cout << "New bus " << num << endl;
			bus_stops[stops]=num;
			++num;
		}
		else
		{
			cout << "Already exists for " << bus_stops[stops] << endl;
		}
		stops.clear();
	}

}

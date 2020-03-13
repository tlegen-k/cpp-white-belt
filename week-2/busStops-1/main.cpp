#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
	int q;
	cin >> q;
	string command;

	map<string, vector<string>> routes;
	map<string, vector<string>> stops_buses;

	for (int i=0; i<q; ++i)
	{
		cin >> command;
		if (command=="NEW_BUS")
		{
			string bus, stop;
			int stop_count;
			cin >> 	bus >> stop_count;
			for (int k=0; k<stop_count; ++k)
			{
				cin >> stop;
				routes[bus].push_back(stop);
				stops_buses[stop].push_back(bus);
			}
		}
		else if (command=="BUSES_FOR_STOP")
		{
			string stop;
			cin >> stop;
			if (stops_buses.count(stop)==0)
			{
				cout << "No stop" << endl;
			}
			else
			{
				for(auto jj : stops_buses[stop])
				{
					cout << jj << " ";
				}
				cout << endl;
			}
		}

		else if (command == "STOPS_FOR_BUS")
		{
			string bus;
			cin >> bus;
			if (routes.count(bus)==0)
			{
				cout << "No bus" << endl;
			}
			else {
				for (auto y : routes[bus])
				{
					cout << "Stop " << y << ":";
					if (stops_buses[y].size() == 1)
					{
						cout << " no interchange" << endl;
					}
					else
					{
							for  (auto z : stops_buses[y])
							{
								if (z!=bus)
								{
								cout << " " << z;
								}
							}
							cout << endl;
					}
				}
			}
		}
		else if (command == "ALL_BUSES")
		{
			if (routes.size()==0)
			{
				cout << "No buses" << endl;
			}
			else{
				for (auto p : routes)
				{
					cout << "Bus " << p.first << ": ";
					for (auto ll : p.second)
					{
						cout << ll << " ";
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	string command;

	int N;
	map<string,string> folder;
	cin >> N;
	for (int i=0; i<N; ++i)
	{
		cin >> command;
		if (command=="CHANGE_CAPITAL")
		{
			string country, new_capital;
			cin >> country >> new_capital;
			if (folder.count(country)==0)
			{
				cout << "Introduce new country " << country << " with capital " <<
						new_capital << endl;

			}
			else
			{
				string old_capital=folder[country];
				if (old_capital==new_capital)
				{
					cout << "Country " << country << " hasn't changed its capital"
							<< endl;
				}
				else
				{
					folder[country]=new_capital;
					cout << "Country " << country << " has changed its capital from "
							<< old_capital << " to " << new_capital << endl;
				}
			}
			folder[country]=new_capital;
		}

		if (command=="RENAME")
		{
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if (old_country_name==new_country_name || folder.count(old_country_name)==0
					|| folder.count(new_country_name)==1)
			{
				cout << "Incorrect rename, skip" << endl;
			}
			else
			{
				cout << "Country " << old_country_name << " with capital " <<
						folder[old_country_name] << " has been renamed to " <<
						new_country_name << endl;
				folder[new_country_name]=folder[old_country_name];
				folder.erase(old_country_name);
			}
		}

		if (command == "ABOUT")
		{
			string country;
			cin >> country;
			if (folder.count(country)==0)
			{
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else
			{
				cout << "Country " << country << " has capital " << folder[country] <<
						endl;
			}
		}

		if (command == "DUMP")
		{
			if (folder.size()==0)
			{
				cout << "There are no countries in the world" << endl;
			}
			else
			{
				for (auto item : folder)
				{
					cout << item.first << "/" << item.second << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}

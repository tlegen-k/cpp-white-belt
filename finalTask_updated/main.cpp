/*
 * main.cpp
 *
 *  Created on: Feb 5, 2020
 *      Author: tlegenkamidollayev
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
	//empty constructor
//	Date() {	}
	Date(int y, int m, int d) {
		year = y;
		if ( m < 1 || m > 12 ) {
			throw out_of_range("Month value is invalid: " + to_string(m));
		}
		else if ( d < 1 || d > 31 ) {
			throw out_of_range("Day value is invalids: " + to_string(d));
		}
		else {
			month = m;
			day = d;
		}
	}
	int GetYear() const {
	  return year;
	}
	int GetMonth() const {
	  return month;
	}
	int GetDay() const {
	  return day;
	}
private:
	int year;
	int month;
	int day;
};

ostream& operator << ( ostream& stream, const Date& date) {
	stream << setfill('0') << setw(4) << to_string(date.GetYear()); //input year in format 0013
	stream << "-";
	stream << setfill('0') << setw(2) << to_string(date.GetMonth()); //input month in format 01
	stream << "-";
	stream << setfill('0') << setw(2) << to_string(date.GetDay()); //input day in format 01
	return stream;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear()) {
		return true;
	}
	else if (lhs.GetYear() > rhs.GetYear() ) {
		return false;
	}
	else {
		if ( lhs.GetMonth() < rhs.GetMonth() ) {
			return true;
		}
		else if ( lhs.GetMonth() > rhs.GetMonth() ) {
			return false;
		}
		else {
			if ( lhs.GetDay() < rhs.GetDay() ) {
				return true;
			}
			else {
				return false;
			}

		}
	}
}
Date ReadDate(const string& date) {
	stringstream date_stream(date);
    bool flag = true;

    int year;
    flag = flag && (date_stream >> year);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int month;
    flag = flag && (date_stream >> month);
    flag = flag && (date_stream.peek() == '-');
    date_stream.ignore(1);

    int day;
    flag = flag && (date_stream >> day);
    flag = flag && date_stream.eof();

    if (!flag)
    {
        throw logic_error("Wrong date format: " + date);
    }
    return Date(year, month, day);
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
//		if ( !events[date].empty() && ( events.[date] != event ) ) {
		if ( !event.empty() ) {
			events[date].insert(event);
		}
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if ( events.count(date) > 0 && events[date].count(event) > 0 ) {
			events[date].erase(event);
			return true;
		}
		else {
			return false;
		}
	}
	int  DeleteDate(const Date& date) {
		int no_of_events = events[date].size();
		if ( no_of_events > 0 ) {
			events[date].clear();
			events.erase(date);
		}
		return no_of_events;
	}

	set<string> Find(const Date& date) const {
		set<string> no_of_events;
		if ( events.count(date) > 0 ) {
			no_of_events = events.at(date);
		}
		return no_of_events;
	}

	void Print() const {
		for ( const auto& i : events ) {
			for ( auto k : i.second ) {
				cout << i.first << " " << k << endl;
			}

		}

	}
private:
	map<Date, set<string>> events;
};

int main() {
    try
    {
    	ifstream input ("input.txt");

        Database db;
        string command;

        while (getline(cin, command))
//        while (getline(input, command))
        {
            if(command == "") continue;

            stringstream input(command);

            string operation;
            input >> operation;

 //           map<string, char> operations_codes = {{"Add", 'A'}, {"Del",'D'}, {"Find", 'F'}, {"Print",'P'}};

   //         char operation_code = operations_codes[operation];
            if (operation == "Add")
                {
                    string date_string, event;
                    input >> date_string >> event;
                    const Date date = ReadDate(date_string);
                    if (event != "" || event != " ") {
                        db.AddEvent(date, event);
                    }
                }
            else if (operation == "Del")
                {
                    string date_string, event;
                    input >> date_string;
                    if (!input.eof()) {
                        input >> event;
                    }

                    const Date date = ReadDate(date_string);

                    if (event.empty()) {
                        const int num_of_events_to_del = db.DeleteDate(date);
                        cout << "Deleted " << num_of_events_to_del << " events" << endl;
                    } else {
                        if (db.DeleteEvent(date, event)) {
                            cout << "Deleted successfully" << endl;
                        } else {
                            cout << "Event not found" << endl;
                        }
                    }
                    break;
                }
            else if (operation == "Find")
                {
                    string date_string, event;
                    input >> date_string >> event;
                    const Date date = ReadDate(date_string);
                    set<string> events_set;
                    events_set = db.Find(date);

                    for (string e : events_set) {
                        cout << e << endl;
                    }
                    break;
                }
            else if (operation == "Print")
                {
                    db.Print();
                    break;
                }
        }
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }
return 0;

//templates of useful stuff
/*	int y, m, d;
	char def1, def2;
	cin >> y >> def1 >> m >> def2 >> d >> EOF;
	cin.peek() == EOF; //check reaching the end of stream
	return 0; */
}





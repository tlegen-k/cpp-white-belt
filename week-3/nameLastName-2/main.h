#ifndef MAIN_H_
#define MAIN_H_

#include <map>
#include <string>
#include <iostream>
#include <vector>
using namespace std;



class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    last_names[year] = last_name;
  }
  string GetFullName(int year) {
    // получаем имя и фамилию по состоянию на год year
    const string first_name = FindNameByYear(first_names, year);
    const string last_name = FindNameByYear(last_names, year);

    // если и имя, и фамилия неизвестны
    if (first_name.empty() && last_name.empty()) {
      return "Incognito";

    // если неизвестно только имя
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";

    // если неизвестна только фамилия
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";

    // если известны и имя, и фамилия
    } else {
      return first_name + " " + last_name;
    }
  }
  // если имя неизвестно, возвращает пустую строку
  string FindNameByYear(const map<int, string>& names, int year) {
    string name;  // изначально имя неизвестно

    // перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
    for (const auto& item : names) {
      // если очередной год не больше данного, обновляем имя
      if (item.first <= year) {
        name = item.second;
      } else {
        // иначе пора остановиться, так как эта запись и все последующие относятся к будущему
        break;
      }
    }

    return name;
  }

  string GetHistoryNames(const vector<string>& data)
  {
  	string result;// = " (";
  	string check = data[0];
  	unsigned int limit = data.size()-1;
  	for(unsigned int i = 1; i < limit; ++i)
  	{
  		if(check != data[i])
  		{
  			result += data[i] + ", ";
  			check = data[i];
  		}
  	}
  	if(data[limit] != check)
  		result += data[limit];
  	if(!result.empty())
  	{
  		return " (" + result + ")";
  	}
  	//result += ")";
  	return result;
  }

  vector<string> FormNamesHistory(int year, map<int, string>& data)

  {
  	vector<string> result;
  	int limit = data.begin() -> first;
  	for(int i = year; i >= limit; --i)
    	{
    		if(data.count(i))
   			result.push_back(data[i]);
    	}
    	return result;
  }

  string GetFullNameWithHistory (int year) {
	  	vector<string> names = FormNamesHistory(year, first_names);
	  	vector<string> surnames = FormNamesHistory(year, last_names);
	  	string result;
	  	if(!names.empty() && !surnames.empty())
	  	{
	  		result = names[0];
	  		if(names.size() > 1)
	  		{
	  			result += GetHistoryNames(names);
	  		}
	  		result += (" " + surnames[0]);
	  		if(surnames.size() > 1)
	  		{
	  			result += GetHistoryNames(surnames);
	  		}
	  		return result;
	  	}
	  	else if(!names.empty())
	  	{
	  		result = names[0];
	  		if(names.size() > 1)
	  		{
	  			result += GetHistoryNames(names);
	  		}
	  		result += " with unknown last name";
	  	}
	  	else if(!surnames.empty())
	  	{
	  		result = surnames[0];
	  		if(surnames.size() > 1)
	  		{
	  			result += GetHistoryNames(surnames);
	  		}
	  		result += " with unknown first name";
	  	}
	  	else result = "Incognito";
	  	return result;
  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};





#endif /* MAIN_H_ */

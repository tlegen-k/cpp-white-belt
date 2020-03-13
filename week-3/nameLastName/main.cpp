#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
	  firstNames[year]=first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
	  lastNames[year]=last_name;
  }
  string GetFullName(int year) {
	  string answer;
	  int tempYearLast, tempYearFirst;
	  for (const auto& a : firstNames)
	  {
		  if (!a.second.empty())
		  {
			  if (year >= a.first)
			  {
			  	tempYearFirst = a.first;
			  }
		  }
	  }
	  for (const auto& b : lastNames)
	  {
		  if (!b.second.empty())
		  {
			  if (year >= b.first)
			  {
			  	tempYearLast = b.first;

			  }
		  }
	  }
	  if (firstNames[tempYearFirst].empty() && lastNames[tempYearLast].empty())
	  {
		  answer  = "Incognito";
	  }
	  else if (firstNames[tempYearFirst].empty() && !lastNames[tempYearLast].empty())
	  {
		  answer = lastNames[tempYearLast] + " with unknown first name";
	  }
	  else if (!firstNames[tempYearFirst].empty()&& lastNames[tempYearLast].empty())
	  {
		  answer = firstNames[tempYearFirst] + " with unknown last name";
	  }
	  else
	  {
		  answer = firstNames[tempYearFirst] + " " + lastNames[tempYearLast];
	  }
	  return answer;
  }
private:
  // приватные поля
  map<int, string> firstNames;
  map<int, string> lastNames;
};

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}






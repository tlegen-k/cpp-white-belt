## C++ White belt
This repository contains my solutions to tasks from week 3 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)

### Names and last names
Implement a human class that maintains a person's history of changes to their last name and first name.
```cpp
class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
  }
  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
  }
  string GetFullName(int year) {
    // получить имя и фамилию по состоянию на конец года year
  }
private:
  // приватные поля
};
```
Consider that no more than one surname change and no more than one name change can occur each year. At the same time, over time, more and more facts from a person's past may be discovered, therefore, the years in successive calls to the ChangeLastName and ChangeFirstName methods are not required to increase.

It is guaranteed that all first and last names are non-empty.

The string returned by the GetFullName method must contain the person's first and last name, separated by a single space, as of the end of the given year.

- If no surname or first name changes have occurred by this year, return the "Incognito" string.
- If there was a last name change for the given year, but there was no name change, return "last_name with unknown first name".
- If there was a name change for the given year, but there was no last name change, return "first_name with unknown last name".

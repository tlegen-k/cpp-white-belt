## C++ White belt
This repository contains my solutions to tasks from week 3 of [C++ course](https://www.coursera.org/learn/c-plus-plus-yellow/home/welcome)

### Names and last names - 2
Add the GetFullNameWithHistory method to the class from the previous First and Last Name 1 task:
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
  string GetFullNameWithHistory(int year) {
    // получить все имена и фамилии по состоянию на конец года year
  }
private:
  // приватные поля
};
```
Unlike the GetFullName method, the GetFullNameWithHistory method should return not only the last first and last name by the end of a given year, but also all previous first and last names in reverse chronological order. If current facts indicate that a person has changed his last name or first name to the same twice in a row, the second change in the formation of history should be ignored.

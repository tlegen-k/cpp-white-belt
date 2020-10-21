#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
	  strings.push_back(s);
    // добавить строку s в набор
  }
  vector<string> GetSortedStrings() {
		sort(strings.begin(), strings.end());
		return strings;
    // получить набор из всех добавленных строк в отсортированном порядке
  }
private:
  vector<string> strings;
  // приватные поля
};
void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}
int main()
{
	  SortedStrings strings;

	  strings.AddString("first");
	  strings.AddString("third");
	  strings.AddString("second");
	  PrintSortedStrings(strings);

	  strings.AddString("second");
	  PrintSortedStrings(strings);

	  return 0;
	return 0;
}

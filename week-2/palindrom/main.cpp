#include <iostream>
#include <string>
using namespace std;

bool IsPalindrom (string word)
{
	string second;
	int size = word.size();

	for ( int i=size; i>0; --i)
	{
		second += word[i-1];
	}

	if (!second.compare(word))
	{
//		cout << "true";
		return true;

	}
	else
	{
//		cout << "false";
		return false;
	}
}

int main()
{
	string word ;
	cin >> word;
	IsPalindrom(word);
	return 0;
}

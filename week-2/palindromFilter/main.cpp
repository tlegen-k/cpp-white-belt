#include <iostream>
#include <vector>
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

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> answer;

	for (auto x : words)
	{
		int size = x.size();

		if ( (IsPalindrom(x) == true) && (size >= minLength) )
		{
			answer.push_back(x);
		}

	}
//	cout << answer;
	for (auto x : answer)
	{
		cout << x << " ";
	}
	return answer;
}

int main()
{
	vector<string> words;
	int minLength;
	words = {"weew", "bro", "code"};
	minLength = 4;

	PalindromFilter(words, minLength);
}

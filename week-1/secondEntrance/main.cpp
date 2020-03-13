#include <iostream>
#include <string>
using namespace std;

int main() {
	string word = "";

	cin >> word;
	int number=0;

	for (int i=0; i <= word.size(); ++i) {
		if ( word[i] == 'f' ) {
			number += 1;
		}
	}

	if ( number == 1 ) {
		cout << "-1"; }

	else if ( number == 0 ) {
		cout << "-2"; }

	else {
		number = 0;

		for (int i=0; i <= word.size(); ++i){
			if (word[i] == 'f') {
				number += 1;
				if ( word[i] == 'f' && number == 2) {
					cout << i;
				}
			}
		}
	}
	return 0;
}

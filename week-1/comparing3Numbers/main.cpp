#include <iostream>
using namespace std;

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	if (a<b){
		if (b<c){
			cout << a;
		}
		else{
			if (a>c) {
				cout << c;
			}
			else {
				cout << a;
			}
		}
	}
	else {
		if (b>c) {
			cout << c;
		}
		else {
			cout << b;}
		}
	return 0;
}

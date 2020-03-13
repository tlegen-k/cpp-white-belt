#include <iostream>
#include <cmath>
using namespace std;
int main() {
	//roots of equation A*x^2 + B*x + c =0//
	double a, b, c;
	cin >> a >> b >> c;
	double x1,x2;
	if (a==0){
		if (b==0){

		}
		else {
		cout << -c/b;
		}
	}
	else if (b==0){
		if (a==0){

		}
		else if (c==0){
			cout << "0";
		}
		else if (c/a < 0){
			x1 = sqrt(-c/a);
			x2 = -sqrt(-c/a);
			cout << x1 << " " << x2;
		}

	}
	else if (c==0){
		if (a==0) {
			cout << "0";
		}
		else if (b==0){
			cout << "0";
		}
		else {
			cout << "0 " << -b/a;
		}
	}
	else if (sqrt(b*b-4*a*c)>= 0){
		x1 = (-b + sqrt(b*b-4*a*c))/(2*a);
		x2 = (-b - 	sqrt(b*b-4*a*c))/(2*a);
		if (x1==x2){
			cout << x1;
		}
		else {
			cout << x1 << " " << x2;
		}
	}

	return 0;
}

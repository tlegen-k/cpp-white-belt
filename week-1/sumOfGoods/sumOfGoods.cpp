#include <iostream>
using namespace std;
int main(){
	double N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;
	if (N <= A)
		cout << N;
	else if (N > A && N <= B)
		cout << N*(1-0.01*X);
	else
		cout << N*(1-0.01*Y);
	return 0;
}

#include <iostream>
using namespace std;

int Factorial (int x)
{
	int factorial=1;

	if (x<0)
	{
		return 1;

	}
	else
	{

		for (int i=x; i>0; --i)
		{
			factorial*=i;
		}
		return factorial;
	}

}

int main()
{
	int x;

//	cout << "Input number: ";
	cin >> x;
	cout << Factorial(x);
	return 0;
}

#include <iostream>
#include <exception>
using namespace std;

class Rational {
    // Вставьте сюда реализацию класса Rational
public:
    Rational() {
    	num = 0;
    	denom = 1;
    }

    Rational(int numerator, int denominator) {
//    	cout << numerator << " " << denominator << endl;
    	if (denominator ==0)
    	{
    		throw invalid_argument("invalid argument");
    	}
    	else {
			int a=abs(numerator);
			int b=abs(denominator);
			int gcd = 1;
	//    	cout << a << " " << b << endl;

			while (a>0 && b>0)
			{
				if (a>b)
				{
					a=a%b;
				}
				else
				{
					b=b%a;
				}
			}

			gcd = a+b;

			num = numerator/gcd;
			denom = denominator/gcd;

			if ((num < 0 && denom < 0) || (num > 0 && denom < 0))
			{
				num = -num;
				denom = -denom;
			}
			else if (numerator==0)
			{
				num = 0;
				denom = 1;

			}
    	}
    }

    int Numerator() const
    {
    	return num;
    }

    int Denominator() const
    {
    	return denom;
    }


private:
    // Добавьте поля
    int num;
    int denom;
};

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	if (lhs.Denominator() == 0 || rhs.Numerator() == 0) {
		throw domain_error("domain error");
	}
	else
	{
		return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
	}
}


// Вставьте сюда реализацию operator / для класса Rational

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument&) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error&) {
    }

    cout << "OK" << endl;
    return 0;
}

/*
 * main.cpp
 *
 *  Created on: Jan 22, 2020
 *      Author: tlegenkamidollayev
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

class Rational {
public:
    Rational() {
    	num = 0;
    	denom = 1;
    }

    Rational(int numerator, int denominator) {
//    	cout << numerator << " " << denominator << endl;
    	if (denominator == 0 ) {
    		throw invalid_argument("Invalid argument");
    	}
    	else
    	{
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
/*    	cout << "GCD " << gcd << endl;
    	cout << "Num " << num << endl;
    	cout << "Denom " << denom << endl; */
    }

    int Numerator() const
    {
        // Реализуйте этот метод
    	return num;
    }

    int Denominator() const
    {
        // Реализуйте этот метод
    	return denom;
    }


private:
    // Добавьте поля
    int num;
    int denom;
};
bool operator< (const Rational& lhs, const Rational& rhs)
{
	return ( lhs.Numerator()*rhs.Denominator() < rhs.Numerator() * lhs.Denominator() );
}
Rational operator+( const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
					lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
					lhs.Denominator() * rhs.Denominator());
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
	if ((lhs.Numerator()==rhs.Numerator() ) && (lhs.Denominator()==rhs.Denominator()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational(lhs.Numerator()*rhs.Numerator(), lhs.Denominator()*rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
	if (lhs.Denominator() == 0 || rhs.Numerator() == 0) {
		throw domain_error("Division be zero");
	}
	else
	{
	return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
	}
}

ostream& operator<<(ostream& stream, const Rational& rational)
{
	stream << rational.Numerator() << "/" << rational.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rational)
{
	int top, bot;

/*	if (stream.tellg() == -1) {
	return stream;
 	} */

	if (stream && !stream.eof() && stream.good()) {
		stream >> top;
		stream.ignore(1);
		stream >> bot;
		rational=Rational(top,bot);
	}
	return stream;
}

int main() {
	try {
		Rational first, second;
		char sym;
		cin >> first >> sym >> second;
		if (sym == '+') {
			cout << (first + second) << endl;
		}
		else if (sym == '-') {
			cout << (first - second) << endl;
		}
		else if (sym == '*') {
			cout << (first * second) << endl;
		}
		else {
			cout << (first / second) << endl;
		}

/*		cout << "First: " << first << endl;
		cout << "Second: " << second << endl;
		cout << "Sym: " << sym << endl; */
	}
	catch (invalid_argument&) {
		cout << "Invalid argument" << endl;
	}
	catch (domain_error& ){
		cout << "Division by zero" << endl;

	}
	/*
	catch (int error) {
		if (error == 1) {
			cout << "Invalid argument" << endl;
		}
		else
			cout << "Division by zero" << endl;
	} */

	return 0;
}




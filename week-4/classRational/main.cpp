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
	return Rational(lhs.Numerator()*rhs.Denominator(), lhs.Denominator()*rhs.Numerator());
}

ostream& operator<<(ostream& stream, const Rational& rational)
{
	stream << rational.Numerator() << "/" << rational.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rational)
{
	int top, bot;

	if (stream.tellg() == -1) {
	return stream;
	}

	if (stream && !stream.eof() && stream.good()) {
		stream >> top;
		stream.ignore(1);
		stream >> bot;
		rational=Rational(top,bot);
	}
	return stream;
}

int main() {
	{
		set<int> numbers;
		numbers.insert(3);
		numbers.insert(4);
		cout << numbers.size() <<endl;
	}

	{
		set<Rational> rationals;
		rationals.insert(Rational(1, 2));
		rationals.insert(Rational(1, 3));

		map<Rational, string> name;
		name[Rational(1, 2)] = "одна вторая";
	}

    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        for (auto x : rs) {
        	cout << x.Numerator() << '/' << x.Denominator() << endl;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
        for (auto i : v) {
              cout << i.Numerator() << '/' << i.Denominator() << endl;
          }

    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

	cout << "OK" << endl;
	return 0;
}

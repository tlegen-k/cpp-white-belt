/*
 * main.cpp
 *
 *  Created on: Jan 20, 2020
 *      Author: tlegenkamidollayev
 */
#include <iomanip>
#include <iostream>
using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if ( left != right) {
		throw  runtime_error(left + " != " + right);
	}
	else {

	}

}

int main() {
	 try {
	    EnsureEqual("C++ White", "C++ White");
	    EnsureEqual("C++ White", "C++ Yellow");
	  } catch (runtime_error& e) {
	    cout << e.what() << endl;
	  }
	return 0;
}




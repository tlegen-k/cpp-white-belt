/*
 * main.cpp
 *
 *  Created on: Jan 5, 2020
 *      Author: tlegenkamidollayev
 */


#include <iostream>
#include <ostream>
#include <fstream>
using namespace std;

int main() {
	ifstream input("input.txt");
	string line;

	while ( getline(input, line)) {
		cout << line << endl;
	}
	return 0;
}





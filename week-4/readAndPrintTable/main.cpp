/*
 * main.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: tlegenkamidollayev
 */

#include <iomanip>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main() {
	ifstream input("input.txt");
	int N, M, value;
	input >> N;
	//input.ignore(1);
	input >> M;
	//input.ignore(1);
//	cout << setfill('.');
	cout << right;

		for (int i=0; i < N; i++)
		{
			for (int k=0; k < M; k++)
			{
				input >> value;
				input.ignore(1);
				if (k!=M-1)
				{
					cout << setw(10) << value;
					cout << " ";
				}
				else
				{
					cout << setw(10) << value;
				}
			}
			if (i!=N-1)
			{
				cout << endl;
			}
			else
			{

			}
		}

	return 0;
}



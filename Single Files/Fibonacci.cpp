/*
* File: Fibonacci.cpp
* Author: Robert Crawford
* Date: 2023-10-25
* Version: 1.0
* Description: Write a program that writes out the first so many values of
* the Fibonacci series, that is, the series that starts with 1 1 2 3 5 8 13
* 21 34. The next number of the series is the sum of the two previous ones.
* Find the largest Fibonacci number that fits in an int.
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;
 
void calculate_fib_numbers(int n, vector<int>& fib_numbers);

int main()
{
	try {
		int n;
		cout << "Enter the amount of fib numbers you want to compute: ";
		cin >> n;

		if (n <= 2)
			throw invalid_argument("Input must be greater than 2.");

		vector<int> fib_numbers = { 0, 1 };
		calculate_fib_numbers(n, fib_numbers);

		for (int fib_number : fib_numbers)
			cout << fib_number << " ";
	}
	catch (const exception& e) {
		cerr << "Exception caught: " << e.what() << endl;
		return 1;
	}
	return 0;
}

void calculate_fib_numbers(int n, vector<int>& fib_numbers)
{
	for (int i = fib_numbers.size(); i < n; ++i) {
		int n1 = fib_numbers[i - 2];
		int n2 = fib_numbers[i - 1];

		if (n1 > numeric_limits<int>::max() - n2)
			throw overflow_error("Integer overflow");

		fib_numbers.push_back(n1 + n2);
	}
}
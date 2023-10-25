/*
* File: SumOfIntegers.cpp
* Author: Robert Crawford
* Date: 2023-10-24
* Version: 1.0
* Description: This program reads and stores a series of integers and then 
* computes the sum of the first n integers. It also prints out a vector 
* containing the N-1 differences between adjacent values.
*/

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Function prototypes
int get_n();
void set_numbers(int n, vector<int>& numbers);
int sum_n_numbers(int n, vector<int>& numbers);
void set_differences(vector<int>& numbers, vector<int>& differences);

int main()
{
	try {
		int n = get_n();

		vector<int> numbers;
		set_numbers(n, numbers);

		int sum = sum_n_numbers(n, numbers);
		
		cout << "The sum of the first " << n << " integers is: " << sum
			<< endl;

		vector<int> differences;
		set_differences(numbers, differences);

		for (int difference : differences)
			cout << difference << " ";
	}
	catch (const exception& e) {
		cerr << "Exception caught: " << e.what() << endl;
		return 1;
	}
	return 0;
}

int get_n() 
{
	int n;
	cout << "Enter the number of values you want to sum: ";
	cin >> n;

	if (n < 0)
		throw invalid_argument("Can't summate a negative amount.");

	return n;
}

void set_numbers(int n, vector<int>& numbers)
{
	cout << "Enter some integers followed by any character to stop: ";
	for (int i; cin >> i;)
		numbers.push_back(i);

	if (n > numbers.size())
		throw invalid_argument("Not enough numbers in the vector.");
}

int sum_n_numbers(int n, vector<int>& numbers)
{
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (numbers[i] > numeric_limits<int>::max() - sum)
			throw overflow_error("Integer overflow");

		if (numbers[i] < numeric_limits<int>::min() + sum)
			throw overflow_error("Integer underflow");

		sum += numbers[i];
	}

	return sum;
}

void set_differences(vector<int>& numbers, vector<int>& differences)
{
	int n = numbers.size();
	for (int i = 0, j = 1; j < n; i++, j++) {
		differences.push_back(abs(numbers[i] - numbers[j]));
	}
}
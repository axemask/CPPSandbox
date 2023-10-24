/*
* File: QuadraticEquationSolver.cpp
* Author: Robert Crawford
* Date: 2023-10-24
* Version: 1.0
* Description: This program solves quadratic equations of standard form 
* ax^2 + bx + c = 0.
*/

#include <iostream>
#include <vector>
using namespace std;

void solveQuadratic(double a, double b, double c, vector<double>& solutions);

int main()
{
	try {
		double a, b, c;
		vector<double> solutions;

		cout << "Enter coefficients a, b, and c: ";
		cin >> a >> b >> c;

		solveQuadratic(a, b, c, solutions);

		for (double solution : solutions)
			cout << "x = " << solution << endl;
	}
	catch (const exception& e) {
		cerr << "Exception caught: " << e.what() << endl;
		return 1;
	}
	return 0;
}

void solveQuadratic(double a, double b, double c, vector<double>& solutions) 
{
	double discriminant = b * b - 4 * a * c;

	if (discriminant > 0) {
		// Two real solutions
		cout << "There is two real solutions:" << endl;
		solutions.push_back((-b + sqrt(discriminant)) / (2 * a));
		solutions.push_back((-b - sqrt(discriminant)) / (2 * a));
	}
	else if (discriminant == 0) {
		// One real solution
		cout << "There is one real solution:" << endl;
		solutions.push_back(-b / (2 * a));
	}
	else {
		throw invalid_argument("Discriminant < 0. Can't solve for complex roots.");
	}
}
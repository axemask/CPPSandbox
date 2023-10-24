/*
* File: CelsiusKelvinConverter.cpp
* Author: Robert Crawford
* Date: 2023-10-24
* Version: 1.0
* Description: This program converts temperatures from celsius to kelvins or kelvins to celsius.
*/

#include <iostream>
#include <cctype>
using namespace std;

// Global constants
constexpr double ABSOLUTE_ZERO_C = -273.15;
constexpr double ABSOLUTE_ZERO_K = 0;

// Function prototypes
double ctok(double temperatureCelsius);
double ktoc(double temperatureKelvin);

int main()
{
	try {
		double temperature;
		char unit;

		cout << "Enter a temperature followed by the unit (k/c): ";
		cin >> temperature >> unit;

		// Convert unit to uppercase for case-insensitive comparison
		unit = toupper(unit);

		double result;
		if (unit == 'C') {
			result = ctok(temperature);
			cout << temperature << " degrees Celsius in Kelvins is: "
				<< result << " kelvins." << endl;
		}
		else if (unit == 'K') {
			result = ktoc(temperature);
			cout << temperature << " kelvins in celsius is: "
				<< result << " celsius." << endl;
		}
		else throw invalid_argument("Unsupported unit.");

	}
	catch (const exception& e) {
		cerr << "Exception caught: " << e.what() << endl;
		return 1;
	}

	return 0;
}

double ctok(double temperatureCelsius)
{
	if (temperatureCelsius < ABSOLUTE_ZERO_C)
		throw invalid_argument("Temperature can't be below absolute zero.");
	return temperatureCelsius - ABSOLUTE_ZERO_C; // temperature + 273.15
}

double ktoc(double temperatureKelvin)
{
	if (temperatureKelvin < ABSOLUTE_ZERO_K)
		throw invalid_argument("Temperature can't be below absolute zero.");
	return temperatureKelvin + ABSOLUTE_ZERO_C; // temperature - 273.15
}
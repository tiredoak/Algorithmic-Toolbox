/*
	Calculates a number raised to a power

	Input: two integers a, b (such that a^b under integer max size)
	Output: a^b
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int power(const int base, const int exponent) {
	int result = 1;
	if (exponent == 0) {
		return 1;
	} else {
		for (int i = 1; i <= exponent; i++) {
			result *= base;
		}
		return result;
	}
}

int power_recursive(const int base, const int exponent) {
	if (exponent == 0) {
		return 1;
	} else if (exponent == 1) {
		return base;
	} else {
		return base * power_recursive(base, exponent - 1);
	}
}

int main () {
	int base, exponent;
	cin >> base >> exponent;
	int result = power(base, exponent);

	cout << base << "^" << exponent << " = " << result << endl;

	return 0;
}
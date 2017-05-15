/*
	Calculate factorial of a number
	(iterative and recursive versions)

	Input: integer n where 0 <= n <= 20
	Output: n!
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Recursive
unsigned long long factorial(const unsigned long long number) {
	if (number == 0 || number == 1) {
		return 1;
	} else {
		unsigned long long result = number * factorial(number - 1);
		return result;
	}
}

// Iterative
unsigned long long factorial_iterative(const unsigned long long number) {
	unsigned long long result = 1;
	if (number == 0 || number == 1) {
		return 1;
	} else {
		for (unsigned long long i = 1; i <= number; i++) {
			result *= i;
		}
	}
	return result;
}

int main () {
	cout << "Enter a number to calculate the factorial (between 0 and 20): ";
	unsigned long long number;
	cin >> number;
	unsigned long long result = factorial_iterative(number);
	cout << result << endl;
	return 0;
}
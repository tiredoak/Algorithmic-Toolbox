/*
	Determine if a string is a palindrome

	Input: string with max 256 char
	Output: string is / isn't a palindrome
*/

#include <iostream>

using namespace std;

// Recursive algorithm compares first and last chars and
// continues towards middle of the string. If at any time
// there is a mismatch, return false.
bool palindrome(char string[], int left, int right) {
	if (right - left < 1) {
		return true;
	} else if (string[right] != string[left]) {
		return false;
	} else {
		if (palindrome(string, left + 1, right - 1)) {
			return true;
		}
	}
	return false;
}

	

int main () {

	char string[256];
	cin >> string;

	cout << "\"" << string << "\" is";
	bool result = palindrome(string, 0, strlen(string) - 1);
	if (!result)
		cout << "NOT";	
	cout << " a palindrome." << endl;

	return 0;
}
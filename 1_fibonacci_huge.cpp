/*
	Computes Fibonacci n mod m where n may be up to 10^18
	Logic is to take advantage of the fact that any Fibonacci
	number modulo a given n will produce a finite sequence which
	repeats (known as Pisano period). Trick is not to compute the 
	large Fibonacci number, instead finding the Pisano period and
	figure out the corresponding number. 

	Input: integer n, m where 1 <= n <= 10^18
					          2 <= m <= 10^5
	Output: Fibonacci n mod m
*/

#include <iostream>
#include <vector>

using namespace std;

// Returns the last digit in a huge Fibonacci number
int pisano_period(long long number, int m) {
    vector<int> period;
    // Pisano periods all start with sequence 01
    period.push_back(0);
    period.push_back(1);
    // Starting index is 2
    int i = 2;
    do {
    	// Creates vector with Pisano period
    	period.push_back((period[i - 2] + period[i - 1]) % m);
    	i++;
    	// Sequence of 011 means the period is repeating
    } while (i <= 3 || !(period[i - 3] == 0 && 
    		period[i - 2] == 1 && period[i - 1] == 1));
    // Deducting the next 011 which signalled repetition
    int pisano_length = i - 3;
    int remainder = number % pisano_length;
    return period[remainder];
}

int main() {
    long long number;
    int m;
    cin >> number >> m;
    int result = pisano_period(number, m);
    cout << result << endl;
    return 0;
}

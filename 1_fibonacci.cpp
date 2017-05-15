/*
	Calculates the nth Fibonacci number

	Input: n, 0 <= n <= 45
	Output: nth Fibonacci number
*/

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Slow recursive algorithm
int fibonacci_naive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

// Fast bottom-up (memoised)
int fibonacci_fast(int number) {
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    for (int i = 2; i <= number; i++) {
        a.push_back(a[i - 1] + a[i - 2]);
    }
    return a[number];
}

int main() {
    int n = 0;
    cin >> n;
    cout << fibonacci_fast(n) << '\n';
    return 0;
}

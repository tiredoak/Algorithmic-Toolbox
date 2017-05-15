/*
	Finds the last digit of a sum of the first n Fibonacci numbers

	Input: n, 0 <= n <= 10^14
	Output: Last digit of F0 + F1 + ... + Fn
*/

#include <iostream>
#include <vector>

using std::vector;

int get_fibonacci_partial_sum_fast(long long start, long long end) {
    int start_equivalent = (start % 60);
    int end_equivalent = (end % 60);

    int start_sum = 1;
    int end_sum = 1;
    // Find last digits
    int p1 = 0;
    int p2 = 1;
    int temp = 0;
    for (int i = 2; i <= end_equivalent; i++) {
        // Save old value of p1
        temp = p1;
        // Advance p1
        p1 = p2;
        // Calculate new p2
        p2 = (temp + p1) % 10;
        // Last digit of the sum
        end_sum = ((end_sum + p2) % 10);
        // Find the sum up until the start
        if (start_equivalent <= 1) {
            start_sum = 0;
        } else if (i == start_equivalent - 1) {
            start_sum = end_sum;
        }
    }
    // Calculate the last digit of partial sum
    if (end_sum >= start_sum) {
        return end_sum - start_sum;
    } else {
        return 10 + (end_sum - start_sum);
    }
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    int result = get_fibonacci_partial_sum_fast(from, to);
    std::cout << result << '\n';
}

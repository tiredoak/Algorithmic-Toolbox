/*
	Finds the least common multiple (lcm) of two positive integers
	a and b, m, which is divisible by both a and b.
	Trick is to use relation between the lcm and the greatest common 
	divisor (gcd), specifically: lcm(a, b) * gcd(a, b) = a * b.

	Input: a, b where 1 <= a, b <= 2*10^9
	Output: lcm(a, b)
*/

#include <iostream>

// Naive algorithm scans through every possible option
long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

// Recursively find gcd(a, b) using Euclid's algorithm
// gcd(a, b) = gcd(a % b, b) or gcd(b % a, a), whichever
// is higher
int gcd_fast(const int n1, const int n2) {
  // Base cases
  if (n1 == 0) {
    return n2;
  } else if (n2 == 0) {
    return n1;
  }
  if (n1 == n2)
    return n1;
  // Other cases
  int max = (n1 > n2) ? n1 : n2;
  int min = (n1 < n2) ? n1 : n2;
  int n1_prime = max % min;
  if (n1_prime == 0)
    return min;
  return gcd_fast(min, n1_prime);
}

// Use relationship described above
long lcm_fast(long a, long b) {
  int gcd = gcd_fast(a, b);
  return a * b / gcd;
}

int main() {
	long a, b;
	std::cin >> a >> b;
	std::cout << lcm_fast(a, b);

	return 0;
}

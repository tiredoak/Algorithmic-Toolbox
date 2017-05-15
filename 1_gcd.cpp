/*
	Returns the Greatest Common Divisor (gcd) using Euclid's 
	algorithm. Idea is that gcd(a, b) = gcd(a % b, b) or 
	gcd(b % a, b) whichever is higher. 

	Input: a, b, where 1 <= a, b <= 2*10^9
	Output: gcd(a, b)
*/


#include <iostream>

// Naive algorithm tries every integer up to
// min(a, b) 
int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// Recursive implementation of Euclid's algorithm described above
int gcd_fast(const int n1, const int n2) {
  // Base cases
  if (n1 == 0) {
    return n2;
  } else if (n2 == 0) {
    return n1;
  }
  // Same number
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

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}

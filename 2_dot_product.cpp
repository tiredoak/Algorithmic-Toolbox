/*
  Given two sequences a1, ..., an and b1, ..., bn, partition them
  into n pairs (ai, bj) such that the sum of their products is maximised

  Input: length n, where 1 <= n <= 10^3
         sequences a and b where -10^5 <= ai, bj <= 10^5 for positive i, j
  Output: maximum possible value by multiplying elements ai and bj in permutations
          of a and b.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int find_max(vector<long int> a) {
  long int max = a[0];
  int max_index = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] > max) {
      max_index = i;
      max = a[i];
    }
  }
  return max_index;
}

long long max_dot_product(vector<long int> a, vector<long int> b) {
  long long sum = 0;
  while (a.size() != 0) {
    // Find max of a and b and multiply them
    long int max_a = find_max(a);
    long int max_b = find_max(b);
    sum += a[max_a] * b[max_b];
    // Delete the already multiplied pairs
    a.erase(a.begin() + max_a);
    b.erase(b.begin() + max_b);
  }
  return sum;
}

int main() {
  size_t n;
  // Number of pairs we will enter
  std::cin >> n;
  vector<long int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}

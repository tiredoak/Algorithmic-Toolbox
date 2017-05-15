/*
  Implements quicksort partitioning sequence into 3 regions: elements strictly
  lower than pivot, elements equal to pivot, and elements strictly greater
  than the pivot.

  Input: first line contains integer n, where 1 <= n <= 10^5
         second line contains sequence of n integers in range [1,10^9]
  Output: Outputs the sequence in non-decreasing order
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

// Returns vector with 2 elements: index of first element equal to pivot
// and index of last element equal to pivot (m1 and m2)
std::vector <int> partition3(vector<int> &a, int l, int r) {
  vector<int> m(2);
  int x = a[l];
  int m1 = l;
  int m2 = m1;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      m1++;
      m2++;
      if (i == m2) {
        swap(a[i], a[m1]);
      } else {
        swap(a[m1], a[m2]);
        swap(a[i], a[m1]);
      }
    } else if (a[i] == x) {
      m2++;
      swap(a[i], a[m2]);
    }
  }
  swap(a[l], a[m1]);
  m[0] = m1;
  m[1] = m2;
  return m;
}

void randomized_quick_sort3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m(2);
  m = partition3(a, l, r);
  int m1 = m[0];
  int m2 = m[1];
  randomized_quick_sort3(a, l, m1 - 1);
  randomized_quick_sort3(a, m2 + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  return 0;
}

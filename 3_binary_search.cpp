/*
  Binary search

  Input: first line contains integer n followed by n distinct 
         integers in increasing order, where 1 <= n <= 10^5
         Second line contains digit k, followed by k integers to search 
         for in input array, where 1 <= k <= 10^5
         Integers must be in range [1, 10^9]
  Output: index where integer is in array or -1 if not found
*/

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  while (left <= right) {
  	int mid = left + ((right - left) / 2);
  	if (a[mid] == x)
  		return mid;
  	if (a[mid] > x) {
  		right = mid - 1;
  	}
  	if (a[mid] < x) {
  		left = mid + 1;
  	}
  }
  return -1;
}

// Simple linear search used for stress testing
int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  // Vector with elements
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  // Vector with indices to search
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }

  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    int output = binary_search(a, b[i]);
    std::cout << output << ' ';
    std::cout << std::endl;
  }
}

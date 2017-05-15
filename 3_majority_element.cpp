/*
  Finds the majority element in an array (an array has a majority element
  if this element appears more than n/2 times).
  Idea is to use divide-and-conquer approach since if a sequence contains 
  a majority element than at least one of its halves will also have that 
  majority element.

  Input: first line contains an integer n, where 1 <= n <= 10^5
         seconds line contains n non-negative integers in range [0, 10^9]
  Output: 1 if sequence has a majority elements and 0 if not.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  // Base case - 1-element array
  if (left == right) return a[left];
  
  int mid = left + ((right-left)/2);
  int candidate_left = get_majority_element(a, left, mid);
  int candidate_right = get_majority_element(a, mid + 1, right);
  // Same valid candidate 
  if (candidate_left == candidate_right && candidate_right != -1)
    return candidate_left;
  // Neither has a valid candidate
  if (candidate_left == candidate_right && candidate_left == -1)
    return -1;
  // Left has a possible candidate
  if (candidate_left != -1 && candidate_right == -1) {
    int count = 0;
    // Scan array and check if it's a majority element
    for (int i = left; i <= right; i++) {
      if (a[i] == candidate_left)
        count++;
    }
    if (count > ((right + 1) - left)/2) {
      return candidate_left;
    } else {
      return -1;
    }
  }
  // Right has a possible candidate
  if (candidate_right != -1 && candidate_left == -1) {
    int count = 0;
    // Scan array and check if it's a majority element
    for (int i = left; i <= right; i++) {
      if (a[i] == candidate_right)
        count++;
    }
    if (count > ((right + 1) - left)/2) {
      return candidate_right;
    } else {
      return -1;
    }
  }
  if (candidate_left != candidate_right) {
    int count_left = 0;
    int count_right = 0;
    // Scan array and check if it's a majority element
    for (int i = left; i <= right; i++) {
      if (a[i] == candidate_left) {
        count_left++;
      } else if (a[i] == candidate_right) {
        count_right++;
      }
    }
    int max = (count_right > count_left) ? count_right : count_left;
    int candidate = (count_right > count_left) ? candidate_right : candidate_left;
    if (max > ((right + 1) - left)/2) {
      return candidate;
    } else {
      return -1;
    }
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  int majority = (get_majority_element(a, 0, a.size() - 1) == -1) ? 0 : 1;
  std::cout << majority << '\n';
}

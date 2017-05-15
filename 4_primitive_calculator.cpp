/*
  Given a calculator which can only (1) multiply input by 2, 
  (2) multiply input by 3, and (3) add 1 to input, output the minimum
  number of operations needed to reach a number x from starting at number
  1.

  Input: single integer n where 1 <= n <= 10^6
  Output: first line corresponds to number of operations needed to get to 
          number n using the primitive calculator
          second line shows the sequence which transformed 1 into the input
          number
*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// min of 2
int min(const int &a, const int &b) {
  return (a < b) ? a : b;
}

// min of 3
int min(const int &a, const int &b, const int &c) {
  int min = (a < b) ? a : b;
  return (min < c) ? min : c;
}

// Returns minimum number of operations to get to n
// in the primitive calculator
vector<int> min_operations(const int &n) {
  vector<int> operations;
  operations.push_back(0);
  operations.push_back(0);
  int minus_one = 0;
  int half = 0;
  int third = 0;
  for (int i = 2; i <= n; i++) {
    // i starts at 2 so there is always i - 1
    minus_one = operations[i - 1] + 1;
    half = operations[i / 2] + 1;
    third = operations[i / 3] + 1;
    // Divisible by 2 and 3
    if (i % 2 == 0 && i % 3 == 0) {
      operations.push_back(min(minus_one, half, third));
      continue;
      // Divisible by 2 but not by 3
    } else if (i % 2 == 0 && i % 3 != 0) {
      operations.push_back(min(minus_one, half));
      continue;
      // Divisible by 3 but not by 2
    } else if (i % 2 != 0 && i % 3 == 0) {
      operations.push_back(min(minus_one, third));
      continue;
    } else {
      operations.push_back(minus_one);
    }
  }
  return operations;
}

vector<int> optimal_sequence(const int &n) {
  vector<int> operations;
  vector<int> indices;
  operations = min_operations(n);
  indices.push_back(n);
  int minimum = 0;
  int minus_one = 0, half = 0, third = 0;
  // Retrace operations used
  int i = n;
  while (i > 1) {
    minus_one = operations[i-1];
    half = operations[i/2];
    third = operations[i/3];
    // Divisible by 2 and 3
    if (i % 2 == 0 && i % 3 == 0) {
      // Check where it came from
      minimum = min(minus_one, half, third);
      if (minimum == minus_one) {
        indices.push_back(i-1);
        i--;
        continue;
      }
      if (minimum == half) {
        indices.push_back(i/2);
        i /= 2;
        continue;
      }
      if (minimum == third) {
        indices.push_back(i/3);
        i /= 3;
        continue;
      }
      // Only divisible by 2
    } else if (i % 2 == 0 && i % 3 != 0) {
      minimum = min(minus_one, half);
      if (minimum == minus_one) {
        indices.push_back(i-1);
        i--;
        continue;
      }
      if (minimum == half) {
        indices.push_back(i/2);
        i /= 2;
        continue;
      }
      // Only divisible by 3
    } else if (i % 2 != 0 && i % 3 == 0) {
      minimum = min(minus_one, third);
      if (minimum == minus_one) {
        indices.push_back(i-1);
        i--;
        continue;
      }
      if (minimum == third) {
        indices.push_back(i/3);
        i /= 3;
        continue;
      }
    } else {
      indices.push_back(i-1);
      i--;
      continue;
    }
  }
  return indices;
}

int main() {
  int n;
  std::cin >> n;
  // Get number of operations
  vector<int> operations = min_operations(n);
  int operation_count = operations[n];
  // Get sequence used
  vector<int> sequence = optimal_sequence(n);
  
  std::cout << operation_count << std::endl;

  int sequence_size = sequence.size();
  for (int i = sequence_size - 1; i >= 0; i--) {
    std::cout << sequence[i] << " ";
  }
  std::cout << std::endl;
}

/*
  Finds the longest common subsequence of 3 different strings.
  Uses an extension to the dynamic programming approach to the 2-string
  version of the problem.

  Input: first line, length n of sequence 1
         second line, n integers a1, ..., an
         third line, length m of sequence 2
         fourth line, m integers b1, ..., bm
         fifth line, length p of sequence 3
         sixth line, p integers c1, ..., cp
         1 <= n, m, p <= 100
         -10^9 <= a, b, c <= 10^9
  Output: length of longest common subsequence between the 3 input ones.
*/

#include <iostream>
#include <vector>

using std::vector;

typedef int* IntArrayPtr;

int maximum(const int &a, const int &b, const int &c) { 
  int max = (a > b) ? a : b;
  max = (max > c) ? max : c;
  return max;
}

int maximum(const int &a, const int &b, const int &c, const int &d) {  
  int max1 = (a > b) ? a : b;
  int max2 = (c > d) ? c : d;
  int max = (max1 > max2) ? max1 : max2;
  return max;
}

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int rows = a.size() + 1, cols = b.size() + 1, height = c.size() + 1;
  
  int*** table;
  table = new int**[rows];
  for (int i = 0; i < rows; i++) {
    table[i] = new int*[cols];
    for (int j = 0; j < cols; j++) {
      table[i][j] = new int[height];
      for (int k = 0; k < height; k++) {
          table[i][j][k] = 0;
      }
    }
  }
  // Fill values
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = 0; k < height; k++) {
        // Initialise value to zero
        if (i == 0 || j == 0 || k == 0) {
          table[i][j][k] = 0;
          continue;
        }
        // All numbers are equal
        if (a[i-1] == b[j-1] && b[j-1] == c[k-1]) {
          table[i][j][k] = table[i-1][j-1][k-1] + 1;
        } else {
          table[i][j][k] = maximum(table[i-1][j][k], table[i][j-1][k], table[i][j][k-1], table[i-1][j-1][k-1]);
        }
      }
    }
  } 
  int max = table[rows-1][cols-1][height-1];
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      delete[] table[i][j];
    }
  }
  delete[] table;

  return max;
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}

/*
  Discrete knapsack without repetitions problem.
  Use dynamic programming approach where a table is created which
  contains, for any knapsack of weight lower than or equal to weight
  provided, the optimal solution using any number of items.

  Input: first line contain capacity W of knapsack and number n of items
         (here assumed to have value equal to their weight)
         second line contains n integers w1, ..., wn containing the weights
         of the items.
         1 <= W <= 10^4 and 1 <= n <= 300 and 0 <= w0, ..., wn-1 <= 10^5
  Output: maximum weight of item that fits into knapsack of capacity W
*/

#include <iostream>
#include <vector>

using std::vector;

typedef int* IntArrayPtr;

int max(int a, int b) {
  return (a > b) ? a : b;
}

int optimal_weight(int W, const vector<int> &w) {
  int rows = w.size();
  int cols = W + 1;
  // Create table
  IntArrayPtr *table = new IntArrayPtr[rows];
  int i = 0, j = 0;
  for (i = 0; i < rows; i++) {
    table[i] = new int[cols];
  }
  // Fill table values
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      // First row and first col
      table[i][j] = 0;
      if (i == 0 || j == 0) {
        table[i][j] = 0;
      } else {
        if (j - w[i] >= 0) {
          table[i][j] = max(table[i-1][j], table[i-1][j-w[i]] + w[i]);
        } else {
          table[i][j] = table[i-1][j];
        }
      }
    }
  }
  // Save value;
  int optimal = table[rows-1][W];
  // Return heap space
  for (i = 0; i < rows; i++) {
    delete[] table[i];
  }
  delete [] table;
  return optimal;
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w;
  w.push_back(0);
  for (int i = 0; i < n; i++) {
    int m = 0;
    std::cin >> m;
    w.push_back(m);
  }
  std::cout << optimal_weight(W, w) << '\n';
}

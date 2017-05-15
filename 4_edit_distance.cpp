/*
  Computes the edit distance between two strings.
  Length of string is at least 1 and at most 100.
  Creates a dynamic programming (DP) matrix with solutions
  to the different subproblems.

  Input: two strings 
  Output: edit distance between the two strings
*/

#include <iostream>
#include <string>

using std::string;

typedef int* IntArrayPtr;

int min(int a, int b, int c) {
	int min = (a < b) ? a : b;
	return (min < c) ? min : c;
}

int edit_distance(const string &str1, const string &str2) {
  int rows = str1.size() + 1;
  int cols = str2.size() + 1;
  // Creates DP matrix
  IntArrayPtr *table = new IntArrayPtr[rows];
  int i = 0, j = 0;
  for (i = 0; i < rows; i++) {
    table[i] = new int[cols];
  }

  // Fill table values
  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      // First row
      if (i == 0) {
      	table[i][j] = j;
      	continue;
      	// First col
      } else if (j == 0) {
      	table[i][j] = i;
      	continue;
      }
      // Check if letters match (-1 accounts for fact that
      // the first letter of each string corresponds to row
      // col 0 in DP matrix
      if (str1[i-1] == str2[j-1]) {
        // Since they match, we only add one for the cases where we
        // matched either of them with another letter
        // Last case means we're matching them together, in which case
        // we don't need to add one.
      	table[i][j] = min(table[i][j-1] + 1, table[i-1][j] + 1, table[i-1][j-1]);
      } else {
        // Regardless of where we come from, we must add one.
      	table[i][j] = min(table[i][j-1] + 1, table[i-1][j] + 1, table[i-1][j-1] + 1);
      }
  	}
  }
  // Save value
  int optimal = table[rows-1][cols-1];
  // Return heap space
  for (i = 0; i < rows; i++) {
    delete[] table[i];
  }
  delete [] table;
  return optimal;
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}

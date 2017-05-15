/*
  Given n multiple digit numbers, return the maximum number
  possible to obtain by aligning the given numbers in some order
  A greedy strategy which works for the single digit problem 
  does not work in this case. A simple trick used here is to 
  convert numbers to strings and compare them digit by digit
  (thus the concept of being larger than something has a different
  meaning in the context of this algorithm)

  Input: integer n where 1 <= n <= 100 followed by 
         n digits separated by spaces
  Output: largest number possible formed by combination of input 
          numbers
*/

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::string;

// Key part of the program. Compares integers digit
// by digit rather than standard greater than.
bool is_greater_than_or_equal(string n1, string n2) {
  string a = n1 + n2;
  string b = n2 + n1;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] > b[i]) {
      return true;
    } else if (a[i] < b[i]) {
      return false;
    }
  }
  return false;
}

string largest_number(vector<string> a) {
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  // Number of ints to input
  int n;
  std::cin >> n;
  vector<string> a(n);
  // Input numbers as strings
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end(), is_greater_than_or_equal);
  std::cout << largest_number(a);
  std::cout << std::endl;
  return 0;
}

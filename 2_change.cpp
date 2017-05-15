/*
	Returns the minimum number of coins needed to change the input
	into coins of denominations 1, 5, and 10.

	Input: integer m, where 1 <= m <= 10^3
	Output: minimum number of coins needed to change the input
			into coins of denominations 1, 5, and 10.
*/

#include <iostream>

int get_change(int m) {
	int tens = m / 10;
	int fives = (m % 10) / 5;
	int ones = ((m % 10) % 5) / 1;
	return tens + fives + ones;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}

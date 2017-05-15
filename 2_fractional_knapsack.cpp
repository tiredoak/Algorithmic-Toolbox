/*
  Fractional knapsack problem
  Idea is to use a greedy approach where item with largest value per weight
  is taken first, until the knapsack reaches full capacity.

  Input: number of items n and capacity W of knapsack
         next n-lines define the values and weights of the items.
  Output: maximal value of fractions of items that fit into the knapsack.

*/

#include <iostream>
#include <vector>

using std::vector;

int find_max(vector<double> ratio) {
  double max = ratio[0];
  int max_index = 0;
  for (int i = 0; i < ratio.size(); i++) {
    if (ratio[i] > max) {
      max_index = i;
      max = ratio[i];
    }
  }
  return max_index;
}

double get_optimal_value(int capacity, vector<double> weights, vector<double> values) {
  double value = 0.0;
  int size = values.size();
  vector<double> ratio(size);
  ratio.clear();
  // Create vector with ratios of all inputs
  for (int i = 0; i < size; i++) {
    ratio.push_back(double(values[i]) / weights[i]);
  }
  
  while (capacity > 0 && ratio.size() != 0) {
    int max_index = find_max(ratio);
    // If best ratio can be added in full
    if (weights[max_index] <= capacity) {
      value += values[max_index];
      capacity -= weights[max_index];
      // Delete items
      values.erase(values.begin() + max_index);
      weights.erase(weights.begin() + max_index);
      ratio.erase(ratio.begin() + max_index);
    } else {
       value += double(capacity) * ratio[max_index];
      capacity = 0;
      // Delete items
      values.erase(values.begin() + max_index);
      weights.erase(weights.begin() + max_index);
      ratio.erase(ratio.begin() + max_index);
    }
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<double> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}

/*
  Given a set of n segments with integer coordinates on a line, return the 
  minimum number of m points such that each segment contains at least one point

  Input: number of segments n where 1 <= n <= 100
  Output: minimum number of points m on the first line and the integer coordinates
          of m points (separated by spaces) on the second line. If there are multiple
          possible sets, output any correct one. 

*/

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool comparison_start(const Segment &a, const Segment &b) {
  return (a.start < b.start) ||
         ((a.start == b.start) && (a.end < b.end));
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points(segments.size());
  // Clear vector contents
  points.clear();
  int chosen_point = segments[0].end;
  for (int i = 0; i < segments.size() - 1; i++) {
    if (segments[i + 1].start > chosen_point) {
      // Save the point and change to next segment's end
      points.push_back(chosen_point);
      chosen_point = segments[i + 1].end;
      // If next is contained in first
    } else if (segments[i + 1].end < chosen_point) {
      chosen_point = segments[i + 1].end;
    } // For all other cases, we want to keep the same point
  }
  points.push_back(chosen_point);
  return points;
}

int main() {
  int n;
  // Number of segments to consider
  std::cin >> n;
  vector<Segment> segments(n);
  // Populate segments
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  std::sort(segments.begin(), segments.end(), comparison_start);
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); i++) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
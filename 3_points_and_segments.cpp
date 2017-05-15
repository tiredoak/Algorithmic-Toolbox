/*
  Given a set of points on a line and a set of segments computes, for each 
  point, how many segments contain that point.
  Trick is to sort the points in ascending order but also taking into account
  if they refer to a point, a start of a segment (l), or end (r). 
  After that, a simple scan of the sequence can do the count easily.

  Input: first line contains 2 non-negative integers s and p defining the
         number of segments and points, respectively. Next s lines contain
         2 integers defining the ith segment. The line after the last segment
         contains the coordinates of the points.
         1 <= s, p <= 50000; -10^8 <= ai <= bj <= 10^8
  Output: p non-negative integers k where k1 corresponds to number of segments
          which contain x1.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::vector;
using std::sort;

struct Points {
  int value;
  char type;
  int order;
};

struct Counts {
  int order;
  int count;
};

// Compare function to pass to library sort
// Sorts of coordinates first and type second.
bool compare(const Points a, const Points b) {
  return (a.value < b.value) || 
         ((a.value == b.value) && (a.type < b.type));
}

bool compare_counts(const Counts a, const Counts b) {
  return (a.order < b.order);
}

vector<Counts> fast_count_segments(vector<Points> points) {
  vector<Counts> cnt;
  Counts temp;

  int count = 0;
  for (int i = 0; i < points.size(); i++) {
    if (points[i].type == 'l') count++;
    if (points[i].type == 'p') {
      temp.order = points[i].order;
      temp.count = count;
      cnt.push_back(temp);
    }
    if (points[i].type == 'r') count--;
  }
  return cnt;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  vector<Points> all;
  Points temp;
  // Creates segment points
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
    temp.value = starts[i];
    temp.type = 'l';
    temp.order = i;
    // Add start points
    all.push_back(temp);
    temp.value = ends[i];
    temp.type = 'r';
    temp.order = i;
    // Add end points
    all.push_back(temp);
  }

  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
    temp.value = points[i];
    temp.type = 'p';
    temp.order = i;
    // Add point points
    all.push_back(temp);
  }

  std::sort(all.begin(), all.end(), compare);
  vector<Counts> cnt = fast_count_segments(all);

  std::sort(cnt.begin(), cnt.end(), compare_counts);

  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i].count << ' ';
  }
}
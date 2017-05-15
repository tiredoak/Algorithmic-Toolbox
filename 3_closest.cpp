/*
	Finds the closest pair of points among given points.
	Idea is to use a divide and conquer strategy to solve 
	the problem, dividing the set in half (based on x-coordinates)
	and recursively calculating the closest pair in each side.
	Notice, it must also consider the pairs around the middle
	(i.e. strip) since the closest pair can be made up of 2 points
	where each falls on different side of the strip.

	Input: first line contains n number of points, 1 <= n <= 10^5
		   subsequent lines contain points with x and y coordinates
		   where -10^9 <= x, y <= 10^9
	Output: outputs the minimum distance between any two points given
*/

#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::abs;

struct Point {
	long x;
	long y;
};

bool compare_x(const Point &a, const Point &b) {
  return (a.x < b.x) || ((a.x == b.x) && (a.y < b.y));
}

bool compare_y(const Point &a, const Point &b) {
  return (a.y < b.y) || ((a.y == b.y) && (a.x < b.x));
}

double min(const double &a, const double &b) {
    return (a < b) ? a : b;
}

double euclidean_distance(const Point &a, const Point &b) {
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

double brute_force(const vector<Point> &points, const int &left, const int &right) {
	int size = right - left;
	if (size < 2) return -1;
	double distance = euclidean_distance(points[0], points[1]);
	double shortest = distance;
	int i = 0, j = 0;
	for (i = left; i < right; i++) {
		for (j = i + 1; j < right; j++) {
			distance = euclidean_distance(points[i], points[j]);
			if (distance < shortest) {
				shortest = distance;
			}
		}
	}
	return shortest;
}

// Calculates the minimum distance for pairs which fall around the strip
double strip_min_distance(const vector<Point> &y_strip, double &current_delta) {
	int size = y_strip.size();
	if (size < 2) return current_delta;

	double mid_min = euclidean_distance(y_strip[0], y_strip[1]);
	double mid_min_distance = mid_min;
	// Brute force to inner points
	// Points whose vertical distance exceeds current_delta can
	// be ignored
	int i = 0, j = 0;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (abs(y_strip[i].y - y_strip[j].y) < current_delta) {
				mid_min_distance = euclidean_distance(y_strip[i], y_strip[j]);
				mid_min = min(mid_min_distance, mid_min);
			} else {
				break;
			}
		}
	}
	current_delta = min(current_delta, mid_min);
	return current_delta;
}

double min_distance(const vector<Point> &points_x, int x_left, int x_right, 
		const vector<Point> &points_y, double &current_delta) {
	// No distance is lower than zero so halt
	if (current_delta == 0) return current_delta;
	// Base case
	int current_size = x_right - x_left;
	if (current_size < 4) return brute_force(points_x, x_left, x_right);

	int mid = x_left + ((x_right - x_left) / 2);
	int mid_x = points_x[mid].x;
	// Create the y vectors from previously sorted points_y
	vector<Point> y_left;
 	vector<Point> y_right;
	int i = 0;
	int y_size = points_y.size();

	for (i = 0; i < y_size; i++) {
		if (points_y[i].x < mid_x) {
			y_left.push_back(points_y[i]);
		} else if (points_y[i].x > mid_x) {
			y_right.push_back(points_y[i]);
		}
	}
	// Recursively solve left and right
	double min_left = min_distance(points_x, x_left, mid, y_left, current_delta);
	if (min_left == 0) return min_left;
	double min_right = min_distance(points_x, mid, x_right, y_right, current_delta);
	if (min_right == 0) return min_right;

	if (min_left == -1 && min_right != -1) {
		current_delta = min_right;
	} else if (min_left != -1 && min_right == -1) {
		current_delta = min_left;
	} else if (min_left != -1 && min_right != -1) {
		current_delta = min(min_left, min_right);
	}
	// Create y-sorted array with all points in the strip
	vector<Point> y_strip;
	for (Point p : points_y) {
		if (abs(p.x - mid_x) <= current_delta) {
			y_strip.push_back(p);
		}
	}
	// Find the minimum distance in the strip region
	// and return the lowest of the two
	return strip_min_distance(y_strip, current_delta);
}	

int main() {
	size_t n;
	std::cin >> n;
	Point temp;
	vector<Point> points_x;
	vector<Point> points_y;
	// Create the vectors
	for (size_t i = 0; i < n; i++) {
		std::cin >> temp.x >> temp.y;
		points_x.push_back(temp);
		points_y.push_back(temp);
	}
	// Sort on x first and y after
	sort(points_x.begin(), points_x.end(), compare_x);
	// Sort on y first and x after
	sort(points_y.begin(), points_y.end(), compare_y);

	double initial_delta = euclidean_distance(points_x[0], points_x[1]);
	double minimum = min_distance(points_x, 0, points_x.size(), points_y, initial_delta);
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << minimum << "\n";
	return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

#define endl '\n'
#define MAXN 50000
#define INF LONG_LONG_MAX

struct Point {
	long long x, y;
    int id;
	bool operator < (Point const &other) {
		if (y == other.y) {
			return x < other.x;
		}
		return y < other.y;
	}
};

bool ccw(struct Point p0, struct Point p1, struct Point p2) {
	long long dx1 = p1.x - p0.x;
	long long dy1 = p1.y - p0.y;
	long long dx2 = p2.x - p0.x;
	long long dy2 = p2.y - p0.y;
	if (dx1 * dy2 >= dy1 * dx2) return true;
	return false;
}

double calcDist(Point a, Point b) {
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double calcCos(Point a, Point b) {
	double dist = calcDist(a, b);
	if (dist == 0) return INF;
	return (abs(a.x - b.x) * (a.x - b.x)) / dist;
}

int n;
Point point[MAXN];

struct Angles {
	double cosine;
	int num;
	/*bool operator < (Angles const &other) {
		if (this->cosine == other.cosine) {
			return !(point[this->num] < point[other.num]);
		}
		return this->cosine > other.cosine;
	}*/
};

bool comp(Angles a, Angles b) {
	if (a.cosine == b.cosine) {
		return !(point[a.num] < point[b.num]);
	}
	return a.cosine > b.cosine;
}

Angles angles[MAXN];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> point[i].x >> point[i].y;
        point[i].id = i + 1;
	}
	Point start = {INF, INF, -1};
	for (int i = 0; i < n; ++i) {
		if (point[i] < start) {
			start = point[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		// cout << calcCos(point[i], start) << endl;
		angles[i] = {.cosine = calcCos(point[i], start), .num = i};
	}
	sort(angles, angles + n, comp);
	/*for (int i = 0; i < n; ++i) {
		cout << angles[i].cosine << " ";
	}
	cout << endl;*/
	vector<Point> edges;
	Point prev1 = point[angles[1].num];
	Point prev2 = point[angles[0].num];
	edges.push_back(prev2);
	edges.push_back(prev1);
	for (int i = 2; i < n; ++i) {
		/*for (int j = 0; j < edges.size(); ++j) {
			cout << "(" << edges[j].x << " " << edges[j].y << ") ";
		}
		cout << endl;*/
		Point cur = point[angles[i].num];
		if (!ccw(prev2, prev1, cur)) {
			while (!ccw(prev2, prev1, cur)) {
				edges.pop_back();
				prev1 = prev2;
				prev2 = edges[edges.size() - 2];
			}
		}
		prev2 = prev1;
		prev1 = cur;
		edges.push_back(cur);
	}
    double maxdist = 0;
    pair<int, int> ans = {INT_MAX, INT_MAX};
    for (int i = 0; i < edges.size(); ++i) {
		for (int j = i + 1; j < edges.size(); ++j) {
            int dist = calcDist(edges[i], edges[j]);
            pair<int, int> possibleAns = {min(edges[i].id, edges[j].id), max(edges[i].id, edges[j].id)};
            if (dist > maxdist) {
                maxdist = dist;
                ans = possibleAns;
            }
            else if (dist == maxdist && possibleAns < ans) {
                ans = possibleAns;
            }
        }
	}
    cout << ans.first << " " << ans.second << endl;
}

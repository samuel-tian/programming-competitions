/*input
8
2 6
3 3
2 8
4 5
7 5
5 5
9 1
5 4
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50000

struct Point {
	int x, y, z;
	bool operator < (Point const &p) {
		return z < p.z;
	}
	bool operator == (Point const &other) {
		return x == other.x && y == other.y;
	}
};

struct Ans {
	Point p1, p2;
	int d;
	bool operator < (Ans const &other) {
		if (d == other.d) {
			if (p1 == other.p1) {
				return p2 < other.p2;
			}
			return p1 < other.p1;
		}
		return d < other.d;
	}
};

bool compx(Point a, Point b) {
	if (a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

bool compy(Point a, Point b) {
	if (a.y == b.y) return a.x < b.x;
	else return a.y < b.y;
}

int calcDist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int n;
Point cows[MAXN];

Ans recurse(int l, int h) {
	if (h - l <= 2) {
		Ans ret = {(Point){0, 0, -1}, (Point){0, 0, -1}, INF};
		for (int i = l; i < h; ++i) {
			for (int j = i + 1; j < h; ++j) {
				int dist = calcDist(cows[i], cows[j]);
				Ans possibleRet = {cows[i], cows[j], dist};
				if (possibleRet < ret) ret = possibleRet;
			}
		}
		// cout << l << " " << h << " ret: " << ret.p1.z << " " << ret.p2.z << " " << ret.d << endl;
		return ret;
	}
	int mid = (l + h) / 2;
	Ans left = recurse(l, mid);
	Ans right = recurse(mid + 1, h);
	Ans ret = left < right ? left : right;
	vector<Point> yset;
	for (int i = l; i <= h; ++i) {
		if (abs(cows[mid].x - cows[i].x) <= ret.d) {
			yset.push_back(cows[i]);
		}
	}
	sort(yset.begin(), yset.end(), compy);
	for (int i = 0; i < yset.size(); ++i) {
		for (int j = 1; j <= 12; ++j) {
			if (i + j >= yset.size()) break;
			int dist = calcDist(yset[i], yset[i + j]);
			Ans possibleRet;
			if (yset[i] < yset[i + j]) possibleRet = {yset[i], yset[i + j], dist};
			else possibleRet = {yset[i + j], yset[i], dist};
			if (possibleRet < ret) ret = possibleRet;
		}
	}
	// cout << l << " " << h << " ret: " << ret.p1.z << " " << ret.p2.z << " " << ret.d << endl;
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> cows[i].x >> cows[i].y;
		cows[i].z = i + 1;
	}
	sort(cows, cows + n, compx);
	Ans ans = recurse(0, n - 1);
	cout << ans.p1.z << " " << ans.p2.z << endl;
}

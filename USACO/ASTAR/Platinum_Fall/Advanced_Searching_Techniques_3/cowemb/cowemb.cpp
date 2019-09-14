#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define endl '\n'
#define MAXN 50000

struct Point {
	double theta;
	double firstTheta;
	bool inc;
	int id;
};

bool comparator(Point a, Point b) {
	return a.theta < b.theta;
}

int n, d;
Point circlePoints[2*MAXN];
int segTree[4*MAXN + 1];

void update(int iter, int iterStart, int iterEnd, int index, int value) {
	if (iterStart <= index && index <= iterEnd) {
		segTree[iter] += value;
	}
	else return;
	if (iterStart != iterEnd) {
		update(2 * iter + 1, iterStart, (iterStart + iterEnd) / 2, index, value);
		update(2 * iter + 2, (iterStart + iterEnd) / 2 + 1, iterEnd, index, value);
	}
}

int query(int iter, int iterStart, int iterEnd, int qStart, int qEnd) {
	if (qStart > qEnd) return 0;
	if (iterStart >= qStart && iterEnd <= qEnd) {
		return segTree[iter];
	}
	if (iterStart >= qEnd || iterEnd <= qStart) return 0;
	return query(2 * iter + 1, iterStart, (iterStart + iterEnd) / 2, qStart, qEnd) + query(2 * iter + 2, (iterStart + iterEnd) / 2 + 1, iterEnd, qStart, qEnd);
}

int binarySearch(int lo, int hi, double t) {
	if (lo > hi) return -1;
	int mid = (lo + hi) / 2;
	if (circlePoints[mid].theta == t) return mid;
	else if (circlePoints[mid].theta < t) return binarySearch(lo, mid, t);
	else return binarySearch(mid + 1, hi, t);
}

int main() {
	ifstream ifs ("input.txt", ios::in);
	ofstream ofs ("output.txt", ios::out);
	ifs >> n >> d;
	for (int i = 0; i < n; ++i) {
		double a, b, c;
		ifs >> a >> b >> c;
		if (b == 0) {
			double x1 = -1 * c / a;
			double x2 = x1;
			double y1 = sqrt(d*d - c*c/(a*a));
			double y2 = -1 * y1;
			double t1 = min(atan2(y1, x1), atan2(y2, x2));
			double t2 = max(atan2(y1, x1), atan2(y2, x2));
			Point p1 = {t1, t1, true, i};
			Point p2 = {t2, t1, false, i};
			circlePoints[2 * i] = p1;
			circlePoints[2 * i + 1] = p2;
		}
		else {
			double x1 = -1 * (sqrt(b*b*(d*d*(a*a+b*b)-c*c))+a*c) / (a*a+b*b);
			double y1 = a * (sqrt(b*b*(d*d*(a*a+b*b)-c*c))-b*b*c) / (b*(a*a+b*b));
			double x2 = (sqrt(b*b*(d*d*(a*a+b*b)-c*c))-a*c) / (a*a+b*b);
			double y2 = -1 * a * (sqrt(b*b*(d*d*(a*a+b*b)-c*c))+b*b*c) / (b*(a*a+b*b));
			double t1 = min(atan2(y1, x1), atan2(y2, x2));
			double t2 = max(atan2(y1, x1), atan2(y2, x2));
			Point p1 = {t1, t1, true, i};
			Point p2 = {t2, t1, false, i};
			circlePoints[2 * i] = p1;
			circlePoints[2 * i + 1] = p2;
		}
	}
	sort(circlePoints, circlePoints + 2*n, comparator);
	int ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (circlePoints[i].inc) {
			update(0, 0, 2 * n - 1, i, 1);
		}
		else {
			int index = binarySearch(0, 2 * n, circlePoints[i].firstTheta);
			update(0, 0, 2 * n - 1, i, -1);
			ans += query(0, 0, 2 * n - 1, index, i);
		}
		for (int j = 0; j < 4 * n + 1; ++j) {
			cout << segTree[j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 2 * n; ++i) {
		cout << circlePoints[i].id << " " << circlePoints[i].inc << " " << circlePoints[i].theta << endl;
	}
	ofs << ans << endl;
	ifs.close();
	ofs.close();
	return 0;
}

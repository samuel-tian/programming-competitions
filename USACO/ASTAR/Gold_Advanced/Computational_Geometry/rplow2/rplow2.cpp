/*input
10 10 5
5 2 6 9
6 5 10 6
3 7 6 7
1 2 1 8
2 2 3 4
*/

/*
. . . . . . . . . .
. . . . o o . . . .
o . . . o o . . . .
o . o o o o . . . .
o . . . o o o o o o
o . . . o o o o o o
o o o . o . . . . .
o o o . o . . . . .
o o o . o . . . . .
. . . . . . . . . .
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 1000

struct Rectangle {
	int x1, y1, x2, y2;
};

bool comparator(Rectangle a, Rectangle b) {
	return a.y1 < b.y1;
}

int x, y, n;
Rectangle rect[MAXN];

int main() {
	cin >> x >> y >> n;
	for (int i = 0; i < n; ++i) {
		cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
	}
	sort(rect, rect + n, comparator);
	int ret = 0;
	for (int i = 1; i <= x; ++i) {
		cout << "xline: " << i << endl;
		int start = 0, end = 0;
		for (int j = 0; j < n; ++j) {
			if (rect[j].x1 > i || rect[j].x2 < i) continue;
			if (end >= rect[j].y1) {
				end = max(end, rect[j].y2);
			}
			else {
				if (start != 0 && end != 0) {
					ret += end - start + 1;
				}
				start = rect[j].y1;
				end = rect[j].y2;
			}
			cout << start << " " << end << endl;
		}
		if (start != 0 && end != 0) {
			ret += end - start + 1;
		}
	}
	cout << ret << endl;
	return 0;
}
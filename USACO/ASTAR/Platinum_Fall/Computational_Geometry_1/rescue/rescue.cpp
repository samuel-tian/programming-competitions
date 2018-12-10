/*input
158 10
76 108
96 120
83 92
117 110
121 59
32 23
29 38
36 66
152 153
2 1
53 90
*/
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

#define endl '\n'
#define MAXM 10000
#define INF INT_MAX

int dist(int x1, int y1, int x2, int y2) {
	// cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	if (x1 > x2) return dist(x2, y2, x1, y1);
	if (x1 == x2) return abs(y1 - y2);
	if (y1 % 2 == 0) return dist(x1 - 1, y1 - 1, x2, y2) - 1;
	if (y2 % 2 == 0) return dist(x1, y1, x2 - 1, y2 - 1) + 1;
	// if (y2 > y1) return dist(x1 + 1, y1 + 2, x2, y2) + 2;
	// else return dist(x1 + 1, y1, x2, y2) + 2;
	int dx = x2 - x1;
	int dy = (y2 - y1) / 2;
	if (dx <= dy) return dist(x2, y1 + dx * 2, x2, y2) + 2 * dx;
	else if (dy <= 0) return dist(x2, y1, x2, y2) + 2 * dx;
	else return dist(x2, y2, x2, y2) + 2 * dx;
}

int n, m;
int si, sj;
int tempx, tempy;

int main() {
	cin >> n >> m;
	cin >> si >> sj;
	// cout << "S: " << si << " " << sj << endl;
	int mindistance = INF;
	int minx = 0, miny = 0;
	for (int i = 0; i < m; ++i) {
		cin >> tempx >> tempy;
		// cout << "TEMP: " << tempx << " " << tempy << endl;
		int tempdist = dist(si, sj, tempx, tempy);
		if (tempdist < mindistance) {
			mindistance = tempdist;
			minx = tempx;
			miny = tempy;
		}
		else if (tempdist == mindistance) {
			if (tempx < minx) {
				minx = tempx;
				miny = tempy;
			}
			else if (tempx == minx) {
				if (tempy < miny) {
					minx = tempx;
					miny = tempy;
				}
			}
		}
	}
	cout << minx << " " << miny << endl << mindistance + 1 << endl;
}
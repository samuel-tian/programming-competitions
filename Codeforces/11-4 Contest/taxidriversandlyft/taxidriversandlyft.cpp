/*input
4 3
1 2 3 4 5 6 7
0 1 0 1 0 1 0
*/
#include <iostream>
#include <climits>
#include <cmath>
#include <utility>

using namespace std;

#define endl '\n'
#define MAXN 200000

int m, n;
int locations[MAXN];
int istaxi[MAXN];
int closest[MAXN];

int main() {
	cin >> n >> m;
	int taxidrivers[m];
	for (int i = 0; i < m + n; ++i) {
		cin >> locations[i];
	}
	int counter = 0;
	for (int i = 0; i < m + n; ++i) {
		cin >> istaxi[i];
		if (istaxi[i]) {
			taxidrivers[counter] = i;
			++counter;
		}
	}
	// for (int i = 0; i < m; ++i) {
	// 	cout << taxidrivers[i] << endl;
	// }
	int ans[m];
	fill(ans, ans + m, 0);
	for (int i = 0; i < m + n; ++i) {
		if (istaxi[i]) closest[i] = -1;
		else {
			// cout << "NEW" << endl;
			int lower = 0;
			int upper = m - 1;
			while (lower < upper) {
				int oldlower = lower;
				int oldupper = upper;
				// cout << lower << " " << upper << endl;
				int middle = (lower + upper) / 2;
				int dist = abs(locations[i] - locations[taxidrivers[middle]]);
				int upperdist = abs(locations[i] - locations[taxidrivers[upper]]);
				int lowerdist = abs(locations[i] - locations[taxidrivers[lower]]);
				if (dist <= upperdist && dist <= lowerdist) {
					if (locations[i] <= locations[taxidrivers[middle]]) upper = middle;
					else {
						lower = middle;
						if (lower == oldlower) break;
					}
				}
				else if (dist >= lowerdist && dist <= upperdist) {
					upper = middle;
				}
				else if (dist <= lowerdist && dist >= upperdist) {
					lower = middle + 1;
				}
			}
			// cout << lower << endl;
			ans[lower]++;
		}
	}
	for (int i = 0; i < m; ++i) {
		if (i == 0) {
			cout << ans[i];
		}
		else {
			cout << " " << ans[i];
		}
	}
	cout << endl;
}
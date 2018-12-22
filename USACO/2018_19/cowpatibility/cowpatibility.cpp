#include <iostream>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 50000

int main() {
	freopen("cowpatibility.in", "r", stdin);
	freopen("cowpatibility.out", "w", stdout);
	int n;
	cin >> n;
	int flavors[n][5];
	/*int current = 0;
	set<int> used;*/
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			cin >> flavors[i][j];
		}
	}
	int counter = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			set<int> merge;
			for (int k = 0; k < 5; ++k) {
				merge.insert(flavors[i][k]);
			}
			for (int k = 0; k < 5; ++k) {
				if (merge.find(flavors[j][k]) != merge.end()) {
					break;
				}
				if (k == 4) ++counter;
			}
		}
	}
	cout << counter << endl;
}
/*input
8 5 3
3 2 1 4 5
3 4
4 7
5 8
*/
#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int n;

int find (int arr[], int val) {
	for (int i = 0; i < n; ++i)
		if (arr[i] == val) 
			return i;
	return -1;
}

int main() {
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);
	int m, k;
	cin >> n >> m >> k;
	int order[n];
	fill(order, order + n, -1);
	vector<int> q;
	for (int i = 0; i < m; ++i) {
		int o;
		cin >> o;
		--o;
		q.insert(q.begin(), o);
	}
	bool fixed[n];
	fill(fixed, fixed + n, false);
	for (int i = 0; i < k; ++i) {
		int c, p;
		cin >> c >> p;
		--c; --p;
		order[p] = c;
		fixed[c] = true;
	}

	int breakStart = 0;
	int toBreak = false;

	for (int i = 0; i < q.size(); ++i) {
		if (fixed[q[i]]) continue;
		if (q[i] == 0) {
			breakStart = i;
			toBreak = true;
			break;
		}
		if (i == 0) {
			for (int j = n - 1; j >= 0; --j) {
				if (order[j] > 0) continue;
				order[j] = q[i];
				break;
			}
			continue;
		}
		for (int j = n - 1; j >= 0; --j) {
			if (order[j] >= 0) continue;
			if (find(order, q[i - 1]) < j) continue;
			order[j] = q[i];
			break;
		}
	}

	if (toBreak) {
		for (int i = q.size() - 1; i >= breakStart; --i) {
			if (fixed[q[i]]) continue;
			if (i == q.size() - 1) {
				for (int j = 0; j < n; ++j) {
					if (order[j] > 0) continue;
					order[j] = q[i];
					break;
				}
				continue;
			}
			for (int j = 0; j < n; ++j) {
				if (order[j] >= 0) continue;
				if (find(order, q[i + 1]) > j) continue;
				order[j] = q[i];
				break;
			}
		}
	}

	if (find(order, 0) != -1) cout << find(order, 0) + 1 << endl;
	else cout << find(order, -1) + 1 << endl;
}
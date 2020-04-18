#include <iostream>
#include <climits>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100000
#define MAXM 100000

int n, m;
pair<int, int> demands[MAXN];
pair<int, int> grasses[MAXM];
// .first is greenness score, .second is greenness price

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> demands[i].second >> demands[i].first;
	}
	for (int i = 0; i < m; ++i) {
		cin >> grasses[i].second >> grasses[i].first;
	}
	sort(demands, demands + n);
	sort(grasses, grasses + m);
	multiset<int> s;
	// .first is price, .second is ID
	long long ans = 0;
	int tracker = m - 1;
	for (int i = n - 1; i >= 0; --i) {
		while (tracker >= 0 && grasses[tracker].first >= demands[i].first) {
			s.insert(grasses[tracker].second);
			--tracker;
		}
		multiset<int>::iterator removeme = s.lower_bound(demands[i].second);
		if (removeme == s.end()) {
			cout << -1 << endl;
			return 0;
		}
		ans += *removeme;
		s.erase(removeme);
	}
	cout << ans << endl;
	return 0;
}

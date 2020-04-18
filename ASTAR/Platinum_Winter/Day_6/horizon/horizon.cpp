#include <iostream>
#include <climits>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF 0x7FFFFFFF
#define MAXN 40000

long long n;
vector<pair<pair<long long, long long>, long long> > buildings;
// first.first is the x-coordinate, first.second is the height, second is whether to remove the height from the multiset or not
multiset<long long> sweep;

int main() {
	cin >> n;
	long long x1, x2, h;
	for (long long i = 0; i < n; ++i) {
		cin >> x1 >> x2 >> h;
		buildings.push_back(make_pair(make_pair(x1, h), 1));
		buildings.push_back(make_pair(make_pair(x2, h), 0));
	}
	sort(buildings.begin(), buildings.end());
	sweep.insert(buildings[0].first.second);
	long long ans = 0;
	long long curx = buildings[0].first.first;
	for (long long i = 1; i < 2*n; ++i) {
		// for (auto iter = sweep.begin(); iter != sweep.end(); ++iter) {
		// 	cout << *iter << " ";
		// }
		// cout << endl;
		pair<pair<long long, long long>, long long> next = buildings[i];
		if (!sweep.empty()) ans += (next.first.first - curx) * (*sweep.rbegin());
		if (next.second) {
			sweep.insert(next.first.second);
		}
		else {
			sweep.erase(sweep.find(next.first.second));
		}
		curx = next.first.first;
	}
	cout << ans << endl;
}

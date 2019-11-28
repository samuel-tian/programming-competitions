#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX
#define endl '\n'
#define MAXN 100000

int n, d;
pair<int, int> raindrops[MAXN];

bool verify(int w) {
	int lo = 0, hi = 0;
	multiset<int> vert;
	vert.insert(raindrops[lo].second);
	for (; lo < n; ++lo) {
		if (hi < lo) {
			hi = lo;
			vert.clear();
			vert.insert(raindrops[lo].second);
		}
		while (hi + 1 < n && raindrops[hi + 1].first - raindrops[lo].first <= w) {
			vert.insert(raindrops[++hi].second);
		}
		if (*(prev(vert.end())) - *(vert.begin()) >= d) {
			return true;
		}
		vert.erase(vert.find(raindrops[lo].second));
	}
	return false;
}

int main() {
//	freopen("input.txt", "r", stdin);
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> raindrops[i].first >> raindrops[i].second;
	}
	sort(raindrops, raindrops + n);
	int lo = 0;
	int hi = 1000000;
	while (lo < hi) {
		int mid = (lo + hi) >> 1;
		if (verify(mid)) {
			hi = mid;
		}
		else {
			lo = mid + 1;
		}
	}
	if (verify(lo)) {
		cout << lo << endl;
	}
	else {
		cout << -1 << endl;
	}
}
/*input
10
1
0
0
2
0
0
1
2
2
2
*/

#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'
#define MAXN 100000

int n;
queue<int> cows[MAXN];
int dist[MAXN];

int filled() {
	for (int i = 0; i < n; ++i) {
		if (cows[i].empty()) {
			return i;
		}
	}
	return -1;
}

int main() {
	cin >> n;
	int counter = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int i = 0; i < a; ++i) {
			cows[i].push(counter);
			++counter;
		}
	}
	long long ans = 0;
	while (true) {
		int pos = filled();
		if (pos == -1) break;
		int cur = (pos - 1 + n) % n;
		while (cows[cur] == 0) {
			cur = (cur - 1 + n) % n;
		}
		--cows[cur];
		++cows[pos];
		int t = (pos - cur + n) % n;
		cout << "pos: " << pos << " cur: " << cur << " dif: " << t << endl;
		ans += t * t;
	}
	cout << ans << endl;
}
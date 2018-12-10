/*input
4 5
6 3
2 4
4 10
12 15
*/

#include <iostream>
#include <climits>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'
#define INF INT_MAX
#define MAXN 100000

struct Drop {
	int x, y;
};

bool xcomp(Drop a, Drop b) {
	return a.x < b.x;
}

int n, d;
Drop drops[MAXN];

int main() {
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> drops[i].x >> drops[i].y;
	}
	sort(drops, drops + n, xcomp);
	int ret = INF;
	int left = 0, right = 0;
	multiset<int> s;
	s.insert(drops[0].y);
	while (true) {
		/*for (multiset<int>::iterator it = s.begin(); it != s.end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;*/
		if (*s.rbegin() - *s.begin() >= d) {
			if (drops[right].x - drops[left].x < ret) {
				ret = drops[right].x - drops[left].x;
			}
			s.erase(s.find(drops[left].y));
			++left;
		}
		else {
			if (right == n - 1) {
				break;
			}
			++right;
			s.insert(drops[right].y);
		}
	}
	if (ret == INF) cout << -1 << endl;
	else cout << ret << endl;
}